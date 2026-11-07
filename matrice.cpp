//
// Created by bgbja on 02-11-26.
//
#include <iostream>
#include <stdexcept>
#include "matrice.h"


    //constructeur
matrice::matrice(int i, int j) : ligne(i) , colonne(j) {
    if (i <= 0 || j <= 0) {
        throw std::invalid_argument("Dimensions invalides");
    }
        tab = new float*[ligne]{};
    try {
        for (int k = 0; k < ligne; k++) {
            tab[k] = new float[colonne]{};
        }
    }
    catch (...) {
        for (int k = 0; k < ligne; k++) {
            delete[] tab[k];
        }

        delete[] tab;

        throw;
    }
}

//remplissage de la matrice
void matrice::init() {
        for (int k=0; k < ligne; k++) {
            for (int l=0; l<colonne; l++) {
                std::cout<<"quelle est la valeur de la celulle " <<  k << " , " << l << " : ";
                std::cin >> tab[k][l];
            }
        }
    }

void matrice::put(int i, int j, float nbr) {
    if (i >= ligne || j >= colonne || i<0 || j<0) {
        std::cout<<"erreur matrice pas definie en: ( " << i << "," << j << " )";
    }
    else {
        tab[i][j] = nbr; //modifier une valeur de la matrice extérieurement
    }

}

void matrice::multScal(float nbr) {
    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            tab[i][j] = get(i,j)*nbr;
        }
    }
}

//retourner les lignes
int matrice::getLignes() const{

        return ligne;
}
//retourner les colonnes
int matrice::getColonne() const{
    return colonne;
}
//retourner les données
float matrice::get(int i, int j) const{
    if (i < 0 || i >= ligne || j < 0 || j >= colonne) {
            throw std::out_of_range("Indice hors limites");
    }
    return tab[i][j];
}

//afficher la matrice
    void matrice::show() {
        for (int k = 0; k < ligne; k++) {
            for (int j = 0; j < colonne; j++) {
                std::cout << tab[k][j] << " ";
            }
            std::cout << std::endl;
        }
    }

matrice::matrice(const matrice& autre)
    : ligne(autre.ligne), colonne(autre.colonne) {

    tab = new float*[ligne];

    for (int i = 0; i < ligne; i++) {
        tab[i] = new float[colonne];

        for (int j = 0; j < colonne; j++) {
            tab[i][j] = autre.tab[i][j];
        }
    }
}
matrice& matrice::operator=(const matrice& autre) {

    // Éviter de s'affecter à soi-même
    if (this == &autre) {
        return *this;
    }

    // Libérer l'ancienne mémoire
    for (int i = 0; i < ligne; i++) {
        delete[] tab[i];
    }
    delete[] tab;

    // Copier les dimensions
    ligne = autre.ligne;
    colonne = autre.colonne;

    // Réallouer la mémoire
    tab = new float*[ligne];

    for (int i = 0; i < ligne; i++) {
        tab[i] = new float[colonne];

        for (int j = 0; j < colonne; j++) {
            tab[i][j] = autre.tab[i][j];
        }
    }

    return *this;
}
//destructeur
    matrice::~matrice() {
        for (int k = 0; k<ligne; k++) {
                delete[] tab[k];
        }
        delete[] tab;
     }



//constructeur de Trans

Trans::Trans(const matrice& matriceOrigine):matrice(matriceOrigine.getColonne(),matriceOrigine.getLignes()) {
    for (int j = 0; j < ligne; ++j) {
        for (int i = 0; i < colonne; ++i) {
            tab[i][j] = matriceOrigine.get(i, j);
        }
    }
}

void Trans::show() {
    matrice::show(); // Appelle l'affichage de la classe mère
}

Trans::~Trans() = default;

Add::Add(const matrice& matriceOrigine1, const matrice& matriceOrigine2):matrice(matriceOrigine1.getLignes(),matriceOrigine1.getColonne()){

    if (matriceOrigine1.getLignes() != matriceOrigine2.getLignes() or matriceOrigine1.getColonne() != matriceOrigine2.getColonne()) {
         throw std::invalid_argument("matrice incompatible");
    }
    else {
        for (int i = 0; i < ligne; ++i) {
            for (int j = 0; j < colonne; ++j) {
                tab[i][j] = matriceOrigine1.get(i, j) + matriceOrigine2.get(i,j);
            }
        }
    }
}

void Add::show() {
    matrice::show();
}

Add::~Add() = default;

Mult::Mult(const matrice &matriceOrigine1, const matrice &matriceOrigine2) : matrice(matriceOrigine1.getLignes(), matriceOrigine2.getColonne()){
    if (matriceOrigine1.getColonne() != matriceOrigine2.getLignes()) {
        throw std::invalid_argument("matrice incompatible");
    }
    else {
        for (int i = 0; i < matriceOrigine1.getLignes(); i++) {
            for (int j = 0;j<matriceOrigine2.getColonne(); j++) {
                float somme = 0;
                for (int k = 0; k < matriceOrigine1.getColonne(); k++) {

                    somme += matriceOrigine1.get(i, k)
                           * matriceOrigine2.get(k, j);
                }

                tab[i][j] = somme;
            }
        }
    }
}

void Mult::show() {
    matrice::show();
}

Mult::~Mult() = default;

multScal::multScal(const matrice &matriceOrigine, float nbr) : matrice(matriceOrigine.getLignes(),matriceOrigine.getColonne()){
    for (int i = 0; i < getLignes(); i++) {
        for (int j = 0; j < getColonne(); j++) {
            tab[i][j] = matriceOrigine.get(i,j)*nbr;
        }
    }
}

void multScal::show() {
    matrice::show();
}

multScal::~multScal() = default;
