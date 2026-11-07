Matrice – Bibliothèque de manipulation de matrices en C++
📌 Présentation

Ce projet consiste à développer une classe matrice en C++ permettant de créer et de manipuler des matrices de nombres réels (float).

L'objectif est de mettre en pratique la programmation orientée objet en C++, notamment la gestion dynamique de la mémoire, les constructeurs, les destructeurs, la surcharge d'opérateurs et l'héritage.

⚙️ Fonctionnalités

Le projet propose plusieurs opérations sur les matrices :

Création de matrices : création d'une matrice avec un nombre de lignes et de colonnes défini.
Initialisation : remplissage d'une matrice avec des valeurs saisies par l'utilisateur.
Modification : modification d'un élément précis grâce à la méthode put().
Lecture : récupération d'une valeur grâce à la méthode get().
Affichage : affichage d'une matrice dans la console.
Addition : addition de deux matrices de mêmes dimensions.
Multiplication : multiplication de deux matrices compatibles.
Transposition : échange des lignes et des colonnes d'une matrice.
Multiplication par un scalaire : multiplication de chaque élément par un nombre réel.
🏗️ Structure du projet

Le projet est organisé autour de deux fichiers principaux :

text
Matrice/
│
├── matrice.h       # Déclaration des classes et méthodes
├── matrice.cpp     # Implémentation des fonctionnalités
├── main.cpp        # Programme principal
├── CMakeLists.txt  # Configuration de compilation
└── README.md       # Documentation du projet

🧮 Classes principales
matrice

Classe principale permettant de représenter une matrice à deux dimensions.

Elle gère :

Les dimensions de la matrice.
L'allocation dynamique de mémoire.
L'initialisation et l'affichage.
La lecture et la modification des éléments.
La copie et l'affectation des matrices.
Trans

Classe permettant de calculer la transposée d'une matrice.

Add

Classe permettant d'effectuer l'addition de deux matrices compatibles.

Mult

Classe permettant d'effectuer le produit matriciel de deux matrices compatibles.

multScal

Classe permettant de multiplier une matrice par un nombre réel.

🛠️ Technologies utilisées
Langage : C++
IDE : CLion
Système de compilation : CMake
Gestion de versions : Git et GitHub
🚀 Compilation et exécution
Avec CLion
Cloner ou télécharger le dépôt GitHub.
Ouvrir le projet dans CLion.
Laisser CLion configurer CMake.
Lancer le programme depuis main.cpp.
Avec un terminal

Si un compilateur C++ et CMake sont installés :

bash
mkdir build
cd build
cmake ..
cmake --build .


L'exécutable généré dépend du système d'exploitation et de la configuration CMake.

🎯 Objectifs pédagogiques

Ce projet permet de travailler plusieurs notions fondamentales du C++ :

Programmation orientée objet.
Gestion dynamique de la mémoire avec new et delete.
Constructeurs et destructeurs.
Constructeur de copie.
Surcharge de l'opérateur d'affectation =.
Héritage.
Gestion des exceptions avec std::invalid_argument et std::out_of_range.
👨‍💻 Auteur

Projet développé dans le cadre d'un apprentissage du C++ et de la programmation orientée objet.
