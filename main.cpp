#include <iostream>
#include "matrice.h"


int main() {
    matrice tab(2,2);
    tab.init();
    Trans tabt(tab);
    std::cout << "matrice de base: " << std::endl;
    tab.show();
    std::cout<<"matrice transpose: "<<std::endl;
    tabt.show();


    return 0;
}
