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
    if (nombreEntré == 2) { // Si l'utilisateur choisit 2, on affiche les logs ssh
    std::ifstream file("/var/log/syslog"); // Ouvre le fichier profile
    std::string line; // Variable pour stocker chaque ligne lue du fichier
    
    if (file.is_open()) { // Vérifie si le fichier est ouvert correctement
        while (std::getline(file, line)) { // Lit chaque ligne du fichier
            if (line.find("ssh") != std::string::npos) { // Si la ligne contient "ssh", on l'affiche
                std::cout << line << std::endl;
            } 
        }
    file.close();
    } else {
        std::cout << "Impossible d'ouvrir le fichier." << std::endl;
    }
    return 0;
}
}
