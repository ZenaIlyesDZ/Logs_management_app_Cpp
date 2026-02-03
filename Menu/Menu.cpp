/**
 * @file Menu.cpp
 * @brief Implémentation des fonctions pour afficher le menu et traiter les choix de l'utilisateur.
 * @author Ilyes
 * @date 3 Février 2026
 * @details
 * Ce fichier contient les fonctions utilisées pour afficher le menu principal du programme de gestion des logs et pour traiter les choix de l'utilisateur.
 */

 #include <iostream>

void afficherMenu() {
    std::cout << "CNED-Gestion de logs" << std::endl;
    std::cout << "Menu" << std::endl;
    std::cout << " Choisir une option" << std::endl;
    std::cout << "1 - Afficher log sudo" << std::endl;
    std::cout << "2 - Afficher et enregistrer log ssh" << std::endl;
    std::cout << "0 - Sortir du programme" << std::endl;
}

int choixLog(int nombreEntré) {
    std::cout << "Vous avez choisi l'option : " << nombreEntré << std::endl; 
        switch(nombreEntré){
        case 1:
            std::cout << "Affichage des logs sudo" << '\n' << std::endl;
            break;
        case 2:
            std::cout << "Affichage et enregistrement des logs ssh" << '\n' << std::endl;
            break;
        case 0:
            std::cout << "Sortie du programme..." << '\n'<< std::endl;
            break;
        default:
            std::cout << "Option non valide. Veuillez réessayer avec une option existante" << '\n' << std::endl;
            break;   
    }  
    return nombreEntré;
}