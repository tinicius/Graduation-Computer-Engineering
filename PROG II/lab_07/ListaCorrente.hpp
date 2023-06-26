//
// Created by vinic on 17/10/2022.
//

#ifndef LAB_07_LISTACORRENTE_HPP
#define LAB_07_LISTACORRENTE_HPP

#include "Corrente.hpp"

class ListaCorrente {
private:
    Corrente *primeiro;
    int length;
public:
    ListaCorrente();
    void inserir(Corrente* corrente);
    void imprimir(string conta);
    void deposito(string conta, double valor);
    void retirada(string conta, double valor);
};


#endif //LAB_07_LISTACORRENTE_HPP
