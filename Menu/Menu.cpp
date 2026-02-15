/**
 * @file Menu.cpp
 * @brief summary of the role : This file contains the functions used to display the main menu of the log management program and to process the user's choices.
 * @author Ilyes
 * @date 03/02/2026
 * @details
 * The function afficherMenu() displays the main menu to the user, which includes options for displaying sudo logs, displaying and saving ssh logs, and exiting the program.
 * The function choixLog(int nombreEntré) processes the user's choice and calls the appropriate function based on the input.
 */

#include <iostream>
#include "Menu.h"
#include "../Logs/log.h"

void afficherMenu() {
    std::cout << "CNED-Log management" << std::endl;
    std::cout << "Menu" << std::endl;
    std::cout << " Choose an option" << std::endl;
    std::cout << "1 - Display sudo logs" << std::endl;
    std::cout << "2 - Display and save ssh logs" << std::endl;
    std::cout << "0 - Exit the program" << std::endl;
}

int choixLog(int nombreEntré) {
    std::cout << "You have chosen option : " << nombreEntré << std::endl; 
        switch(nombreEntré){
        case 1:
            std::cout << "Displaying sudo logs" << '\n' << std::endl;
            sudoLog();
            break;
        case 2:
            std::cout << "Displaying and saving ssh logs" << '\n' << std::endl;
            sshLog();
            break;
        case 0:
            std::cout << "Exiting the program..." << '\n'<< std::endl;
            break;
        default:
            std::cout << "Invalid option. Please try again with an existing option." << '\n' << std::endl;
            break;   
    }  
    return nombreEntré;
}
