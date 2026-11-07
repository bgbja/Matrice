//
// Created by audri on 02-11-26.
//

#ifndef CALCDET_MATRICE_H
#define CALCDET_MATRICE_H

class matrice{
protected:
    int ligne;
    int colonne;
    float **tab;

public:
    matrice(int i, int j); //constructeur
    void init(); //initialiser la matrice avec des valeurs
    void show(); //afficher la matrice
    void put(int i,int j, float nbr);
    void multScal(float nbr);
    int getLignes() const;//retourner les lignes de la matrice
    int getColonne() const;//retourner les colonnes de la matrice
    float get(int i,int j) const;//retourner les valeurs de la matrice
    matrice(const matrice& autre);//au cas ou que on veuille faire une copie
    matrice& operator=(const matrice& autre);
    virtual ~matrice();//destructeur de la matrice
};

class Trans : public matrice { //calcule de la transposée
public:
    Trans(const matrice& matriceOrigine); //constructeut de la transposée
    void show();
    virtual ~Trans() override;
};
class Add : public matrice { //calcule de l'addition entre les deux matrice
public:
    Add(const matrice& matriceOrigine1, const matrice& matriceOrigine2); //constructeur de l'addition
    void show();
    virtual ~Add() override;
};
class Mult : public matrice { //multiplication matricielle
public:
    Mult(const matrice& matriceOrigine1, const matrice& matriceOrigine2); //constructeur de la multiplication
    void show();
    virtual ~Mult();
};
class multScal : public matrice {
public:
    multScal(const matrice& matriceOrigine, float nbr);
    void show();
    virtual ~multScal();
};
#endif //CALCDET_MATRICE_H
