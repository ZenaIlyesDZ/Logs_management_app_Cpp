/*
 * @file : Gestion_logs.cpp
 * @brief summary of the role : Logs management software in C++
 * @author : Ilyes
 * @date : 17/01/2026
 * @details :
 * this file contains the main function of the log management software, which displays a menu to the user and allows them to choose between different options for displaying and saving logs, such as sudo logs and ssh logs.
 * The program continues to display the menu until the user chooses to exit by entering 0.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Menu/Menu.h"


int nombreEntré; // Variable which stock the choice of the user 

int main() {
    do
    {
        afficherMenu(); // Function which display the menu to the user
        std::cout << "Enter your choice : ";
    
    if (!(std::cin >> nombreEntré)) { // We verify if the entry is an integer, if not we display an error message and ask the user to enter a valid option
        std::cout << "Invalid entry. Please enter a number." << std::endl; }
    
    else { // If the entry is an integer, we call the function which corresponds to the choice of the user
        choixLog(nombreEntré);
    }
    } while (nombreEntré != 0); // The program continues to display the menu until the user chooses to exit by entering 0

    return 0;
}
