//
// Created by vinic on 18/10/2022.
//

#ifndef LAB_07_LISTAPOUPANCA_HPP
#define LAB_07_LISTAPOUPANCA_HPP

#include "Poupanca.hpp"

class ListaPoupanca {
private:
    int length;
    Poupanca *primeiro;
public:
    ListaPoupanca();
    void inserir(Poupanca* poupanca);
    void imprimir(string conta);
    void deposito(string conta, double valor);
    void retirada(string conta, double valor);
};


#endif //LAB_07_LISTAPOUPANCA_HPP
