/*
 * @file : Documentation_fonction.h
 * @brief summary of the role : Fichier avec documentation du projet de gestionnaire de logs en C++
 * @author : Ilyes
 * @details :
 * Ce fichier contient la documentation des outils principaux du projet de gestionnaire de logs en C++
 */


 /** @brief Documentation de la fonction main() */
 /**
 * @fn int main();
 * @brief Fonction principale du programme de gestion des logs, c'est au sein d'elle que tout le programme s'exécute.
 * @author Ilyes
 * @date Début Janvier 2026
 * @return int Retourne 0 si le programme s'est exécuté correctement.
 * @details
 * Cette fonction affiche un menu permettant à l'utilisateur de choisir entre différentes options de gestion des logs, c'est cette fonction qui est le coeur du programme.
 */

 int main();

 
 /** @brief Documentation de la fonction afficherMenu */
 /**
 * @fn void afficherMenu();
 * @brief Affiche le menu principal du programme de gestion des logs.
 * @author Ilyes
 * @date 1 Février 2026
 * @details
 * Cette fonction affiche un menu avec les différentes options disponibles pour la gestion des logs.
 */

 void afficherMenu();


/** @brief Documentation de la fonction choixLog */
 /**
 * @fn int choixLog(int nombreEntré);
 * @brief Traite le choix de l'utilisateur dans le menu principal du programme de gestion des logs.
 * @author Ilyes
 * @date 1 Février 2026
 * @param nombreEntré Le choix de l'utilisateur (1, 2 ou 0).
 * @return int Retourne le nombre entré par l'utilisateur.
 * @details
 * Cette fonction permet à l'utilisateur de choisir une option et affiche les messages correspondants à chaque option du menu.
 */

 int choixLog(int nombreEntré);