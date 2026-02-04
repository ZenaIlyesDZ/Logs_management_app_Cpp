# *@file : CMakeList.txt
#* @brief summary of the role : Fichier de configuration CMake pour le projet de gestionnaire de logs en C++
#* @author : Ilyes
#* @date : 17/01/2026 
# * @details : Ce fichier configure le projet CMake pour compiler et lier le programme de gestion des logs en C++.

cmake_minimum_required(VERSION 3.10)

project(Gestion_logs VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#1/3- Ajouter les fichiers sources de votre projet
set(SRCS
    Gestion_logs.cpp
    Menu/Menu.cpp
    Logs/log.cpp
)
#2/3- Ajouter les fichiers d'en-tête de votre projet
set(HEADERS
    Menu/Menu.h
    Logs/log.h
)
#3/3-Ajouter les noms des dossiers de vos modules
include_directories(Menu)
include_directories(Logs)

add_executable(Gestion_logs ${SRCS} ${HEADERS})
