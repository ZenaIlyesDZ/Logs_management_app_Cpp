/*
 * @file : Documentation_fonction.h
 * @brief summary of the role : This file contains the documentation of the functions.
 * @author : Ilyes
 * @details :
 * This file contains the documentation of the functions of the log management project in C++, it provides detailed descriptions of the main functions used in the project, including their purpose, parameters...
 */
#include "../Logs/log.h"


 /** @brief Documentation of the main() function */
 /**
 * @fn int main();
 * @brief Main function of the log management program, it is within this function that the entire program runs.
 * @author Ilyes
 * @date Beginning of January 2026
 * @return int Returns 0 if the program executed correctly.
 */

 int main();

 
 /** @brief Documentation of the afficherMenu() function */
 /**
 * @fn void afficherMenu();
 * @brief Displays the main menu of the log management program.
 * @author Ilyes
 * @date 1 February 2026
 * @details
 * This function displays a menu with the different options available for log management.
 */

 void afficherMenu();


/** @brief Documentation of the choixLog() function */
 /**
 * @fn int choixLog(int nombreEntré);
 * @brief Processes the user's choice in the main menu of the log management program.
 * @author Ilyes
 * @date 1 February 2026
 * @param int nombreEntré The user's choice (1, 2 or 0).
 * @return int Returns the number entered by the user.
 * @details
 * This function allows the user to choose an option and displays the corresponding messages for each menu option.
 */

 int choixLog(int nombreEntré);


/** @brief Documentation of the sudoLog() function */
    /**
    * @fn int sudoLog();
    * @brief Displays the sudo logs of the system.
    * @author Ilyes
    * @date 5 February 2026
    * @return int Returns 0 if the logs were displayed correctly.
    * @details
    * This function reads the file /var/log/auth.log and displays the lines containing "sudo" to the user. It filters the log entries corresponding to sudo commands and displays the sudo command requests.
    */
    
    int sudoLog();

/** @brief Documentation of the sshLog() function */
    /**
    * @fn int sshLog();
    * @brief Manages the SSH logs of the system.
    * @author Ilyes
    * @date 6 February 2026
    * @return int Returns 0 if the logs were displayed correctly.
    * @details
    * Filter the log entries corresponding to SSH connections and display the connection requests in the format of the SshLogging structure
    */
    int sshLog();
  
/** @brief Documentation of the enregistrerSSHLog() function */
    /**
    * @fn int enregistrerSSHLog(SSHLogging sshlog);
    * @brief Records the SSH logs in a file.
    * @author Ilyes
    * @date 10 February 2026
    * @param SSHLogging sshlog The structure containing the SSH connection information to be recorded.
    * @return int Returns 1 if the logs were recorded correctly, -1 in case of error.
    * @details
    * This function opens the file /home/vboxuser/CNED/logiciel_gestions_logs/Logs/ssh_logs.txt in append mode and writes the SSH connection information in this file. If the file already contains logs, the new logs will be added at the end of the file without overwriting the existing logs.
    */
    int enregistrerSSHLog(SSHLogging sshlog);