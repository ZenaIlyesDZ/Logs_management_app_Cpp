/*
@file : log.h
@brief summary of the role : Fichier avec la déclaration des fonctions pour afficher les logs
@author : Ilyes
@date : 05/02/2026
@details :
Ce fichier contient les déclarations des fonctions pour afficher les logs, comme les logs sudo ou logs ssh.
*/

#ifndef LOG_H
#define LOG_H
#include <string>
#include <unistd.h>

struct sshDateTime
{ 
    std::string day;
    std::string hour; 
    std::string minute; 
    std::string second; 
};

struct SSHLogging
{
    std::string hostname;
    std::string username; 
    std::string sshUser; 
    std::string sshHost;
    int sshPort;
    sshDateTime Date;
};

int sudoLog();
int sshLog();
void hostName(SSHLogging &sshLog);
void userName(SSHLogging &sshLog);
int enregistrerSSHLog(SSHLogging sshlog);

#endif