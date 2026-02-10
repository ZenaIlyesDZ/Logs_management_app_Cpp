/*
@file : log.cpp
@brief summary of the role : Fichier avec les fonctions pour afficher les logs
@author : Ilyes
@date : 05/02/2026
@details :
Ce fichier contient les fonctions pour afficher les logs, comme les logs sudo, logs ssh.
*/

#include <iostream>
#include <fstream>
#include <string> 
#include "/home/vboxuser/CNED/logiciel_gestions_logs/Menu/Menu.h"
#include "log.h"
#include <unistd.h>

void hostName(SSHLogging &sshLog) { // Affiche le nom de l'hôte de la machine  
    char hostname[1024]; // Buffer pour stocker le nom de l'hôte  
    gethostname(hostname, 1024); // Récupère le nom de l'hôte
    sshLog.hostname = hostname; // Stocke le nom de l'hôte dans la structure
 }

void userName(SSHLogging &sshLog) { // Affiche le nom de l'utilisateur de la machine
    char username[1024]; // Buffer pour stocker le nom de l'utilisateur
    getlogin_r(username, 1024); // Récupère le nom de l'utilisateur
    sshLog.username = username; // Stocke le nom de l'utilisateur dans la structure
}


int sudoLog() { // Filtre les entrées de log contenant des requêtes sudo depuis le fichier /var/log/auth.log
    if (nombreEntré == 1) { // Si l'utilisateur choisit 1, on affiche les logs sudo
    std::ifstream file("/var/log/auth.log"); // Ouvre le fichier auth.log
    std::string line; // Variable pour stocker chaque ligne lue du fichier
    
    if (file.is_open()) { // Vérifie si le fichier est ouvert correctement
        while (std::getline(file, line)) { // Lit chaque ligne du fichier
            if (line.find("sudo") != std::string::npos) { // Si la ligne contient "sudo", on l'affiche
                std::cout << line << std::endl;
            } 
        }
    file.close();
    } else {
        std::cout << "Impossible d'ouvrir le fichier." << std::endl;
    }
    }

    return 0;
}

int sshLog() { // Structure pour stocker les éléments concernant les log de connexion SSH
    std::string line; //
    sshDateTime sshDateTime;
    SSHLogging sshLog;
    std::string sshPart; // Variable pour stocker la partie du flux contenant les informations de connexion SSH
    
    if (nombreEntré == 2) {
        std::ifstream file("/var/log/syslog"); 
        
        if (!file.is_open()) {
            std::cout << "Impossible d'ouvrir le fichier." << std::endl;
            return 0;
            }
     
            hostName(sshLog);
            userName(sshLog);
            
            while (std::getline(file, line)) {
                    
                    // On cherche "ssh "
                    size_t posSSH = line.find("ssh "); 
                    if (posSSH == std::string::npos) {
                        continue;}

                    // On récupère tout ce qui vient après "ssh "
                    sshPart = line.substr(posSSH + 4);

                    // Vérifications de sécurité
                    if (sshPart.find("@") == std::string::npos) continue;
                    if (sshPart.find(" -p") == std::string::npos) continue;

                    // Extraction du nom d'utilisateur
                    size_t posUser = sshPart.find("@");
                    sshLog.sshUser = sshPart.substr(0, posUser);

                    // Extraction de l'adresse du serveur
                    size_t posHost = sshPart.find(" -p");
                    sshLog.sshHost = sshPart.substr(posUser + 1, posHost - (posUser + 1));

                    // Extraction de la date et de l'heure
                    sshDateTime.day = line.substr(0, 10);
                    sshDateTime.hour = line.substr(11, 2); 
                    sshDateTime.minute = line.substr(14, 2); 
                    sshDateTime.second = line.substr(17, 2);
                    
                    // Extraction du port SSH
                    sshLog.sshPort = std::stoi(sshPart.substr(posHost + 3));

                    // Affichage des informations de connexion SSH
                    std::cout << "\n=== Connexion SSH détectée ===\n";
                    std::cout << "Date : " << sshDateTime.day 
                              << " à " << sshDateTime.hour << "h "
                              << sshDateTime.minute << "m "
                              << sshDateTime.second << "s\n";
                    
                    std::cout << "Machine locale : " << sshLog.hostname << "\n";
                    std::cout << "Utilisateur local : " << sshLog.username << "\n";

                    std::cout << "Utilisateur SSH : " << sshLog.sshUser << "\n";
                    std::cout << "Serveur SSH : " << sshLog.sshHost << "\n";
                    std::cout << "Port SSH : " << sshLog.sshPort << "\n";
                    std::cout << "===============================\n";
                } 
            
            file.close();
            }

    return 0;
}