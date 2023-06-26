//
// Created by vinic on 17/10/2022.
//

#ifndef LAB_07_LISTACORRENTELIMITE_HPP
#define LAB_07_LISTACORRENTELIMITE_HPP

#include "CorrenteLimite.hpp"

class ListaCorrenteLimite {
private:
    CorrenteLimite *primeiro;
    int length;
public:
    ListaCorrenteLimite();
    void inserir(CorrenteLimite* correnteLimite);
    void imprimir(string conta);
    void deposito(string conta, double valor);
    void retirada(string conta, double valor);
};

#endif //LAB_07_LISTACORRENTELIMITE_HPP
