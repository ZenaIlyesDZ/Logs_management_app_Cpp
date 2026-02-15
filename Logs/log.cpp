/*
@file : log.cpp
@brief summary of the role : This file contains the functions to display logs, such as sudo logs, ssh logs.
@author : Ilyes
@date : 05/02/2026
@details :
This file contains the functions to display logs, such as sudo logs, ssh logs. The function sudoLog() filters log entries containing sudo requests from the /var/log/auth.log file and displays them to the user. The function sshLog() extracts and displays SSH connection information from the /var/log/syslog file, including the date, local machine name, local user, SSH user, SSH server, and SSH port. It also saves this information to a file named ssh_logs.txt for future reference.
*/

#include <iostream>
#include <fstream>
#include <string> 
#include "/home/vboxuser/CNED/logiciel_gestions_logs/Menu/Menu.h"
#include "log.h"
#include <unistd.h>

void hostName(SSHLogging &sshLog) { // retrieve the hostname of the local machine 
    char hostname[1024];  
    gethostname(hostname, 1024);
    sshLog.hostname = hostname; 
 }

void userName(SSHLogging &sshLog) { // retrieve the username of the local user
    char username[1024]; 
    getlogin_r(username, 1024); 
    sshLog.username = username; 
}


int sudoLog() { // Filter log entries containing sudo requests from the /var/log/auth.log file and display them to the user
    if (nombreEntré == 1) {
    std::ifstream file("/var/log/auth.log"); 
    std::string line; 
    
    if (file.is_open()) {
        while (std::getline(file, line)) { 
            if (line.find("sudo") != std::string::npos) {
                std::cout << line << std::endl;
            } 
        }
    file.close();
    } else {
        std::cout << "Impossible to open the auth.log file." << std::endl;
    }
    }

    return 0;
}

int sshLog() { // Extract and display SSH connection information from the /var/log/syslog file.
    std::string line; 
    sshDateTime sshDateTime;
    SSHLogging sshLog;
    std::string sshPart;
    
    if (nombreEntré == 2) {
        std::ifstream file("/var/log/syslog"); 
        
        if (!file.is_open()) {
            std::cout << "Impossible to open the syslog file." << std::endl;
            return 0;
            }
     
            hostName(sshLog);
            userName(sshLog);
            
            while (std::getline(file, line)) {
                    
                    // We are looking for lines containing "ssh ". If the line does not contain "ssh ", we continue.
                    size_t posSSH = line.find("ssh "); 
                    if (posSSH == std::string::npos) {
                        continue;}

                    //We extract every part of the line after "ssh ".
                    sshPart = line.substr(posSSH + 4);

                    // We check if the line contains "@" and " -p", if not we continue.
                    if (sshPart.find("@") == std::string::npos) continue;
                    if (sshPart.find(" -p") == std::string::npos) continue;

                    // Retrieval of the SSH username.
                    size_t posUser = sshPart.find("@");
                    sshLog.sshUser = sshPart.substr(0, posUser);

                    // Retrieval of the SSH server.
                    size_t posHost = sshPart.find(" -p");
                    sshLog.sshHost = sshPart.substr(posUser + 1, posHost - (posUser + 1));

                    // Retrieval of the date and time of the SSH connection.
                    sshDateTime.day = line.substr(0, 10);
                    sshDateTime.hour = line.substr(11, 2); 
                    sshDateTime.minute = line.substr(14, 2); 
                    sshDateTime.second = line.substr(17, 2);
                    
                    // Retrieval of the SSH port.
                    sshLog.sshPort = std::stoi(sshPart.substr(posHost + 3));

                    // Display the SSH connection information and save it to a file named ssh_logs.txt.
                    std::cout << "\n=== SSH connection has been detected ===\n";
                    std::cout << "Date : " << sshDateTime.day 
                              << " at " << sshDateTime.hour << "h "
                              << sshDateTime.minute << "m "
                              << sshDateTime.second << "s\n";
                    std::cout << "Local device : " << sshLog.hostname << "\n";
                    std::cout << "Local user : " << sshLog.username << "\n";
                    std::cout << "SSH user : " << sshLog.sshUser << "\n";
                    std::cout << "SHH server : " << sshLog.sshHost << "\n";
                    std::cout << "SSH port : " << sshLog.sshPort << "\n";
                    std::cout << "===============================\n";

                    sshLog.Date = sshDateTime;
                    enregistrerSSHLog(sshLog);
                } 
            
            file.close();
            }

    return 0;
}

int enregistrerSSHLog(SSHLogging sshlog) { // Save the SSH connection information to a file named ssh_logs.txt.
    std::ofstream outFile("/home/vboxuser/CNED/logiciel_gestions_logs/Logs/ssh_logs.txt", std::ios::app); // Open the file in append mode to add new logs without overwriting existing ones.
    if (!outFile) {
        std::cerr << "Error opening the file for recording." << std::endl;
        return -1;
    }

    // Write the SSH connection information to the file.
    outFile << "Date : " << sshlog.Date.day 
            << " at " << sshlog.Date.hour << "h "
            << sshlog.Date.minute << "m "
            << sshlog.Date.second << "s\n";
    outFile << "Local device : " << sshlog.hostname << "\n";
    outFile << "Local user : " << sshlog.username << "\n";
    outFile << "SSH user : " << sshlog.sshUser << "\n";
    outFile << "SHH server : " << sshlog.sshHost << "\n";
    outFile << "SSH port : " << sshlog.sshPort << "\n";
    outFile << "===============================\n";

    outFile.close(); // Close the file
    return 1;
}