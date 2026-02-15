# Logs management app in C++
## This app allow a user to sort, view and save the logs
A console-based tool designed to monitor, visualize, and record system logs according to a set of functional requirements.
This project was created as part of my BTS CIEL coursework to practice C++ programming, file handling, and system monitoring concepts.
## Goals
This project aim to :
- Visualize and filter logs
- Save logs
- Record certain SSH-related events into a structured log file
- Provide a simple and intuitive menu-based interface
## Functional Requirements
### Logs monitor
We want to monitor this type of log : 
- sudo demand
- disconnection on the local station;
- critical system event
### Logs to save
We want certains logs to be save on the workstation : The ssh connexion
We want the ssh connexion demand to be save in a text file, which contain the informations : 
- date of the connexion request
- time of the connexion request
- name of client machine
- name of the connected user
- name of the SSH user
- SHH server
- SSH port

All of these information will be save on a ssh_logs.txt
## Menu Interface
in the menu, we have 3 options :
- 1 : show the sudo logs
- 2 : show and save ssh logs
- 0 : leave the program

## Project structure
```
Logs management app in C++/
├── Doc
│   ├── Documentation_fonction.h
│   |── Doxyfile
|   └── English_Doc.h
|── Logs
│   |── log.cpp
|   └── log.h
├── Menu
│   |── Menu.cpp
|   └── Menu.h
|
|── CMakeLists.txt
|── Gestion_logs.cpp
└── README.md 
```