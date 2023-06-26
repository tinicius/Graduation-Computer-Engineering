//
// Created by vinic on 07/11/2022.
//

#ifndef LAB_10_FILA_HPP
#define LAB_10_FILA_HPP

#include "Pessoa.hpp"

class Fila {
private:
    Pessoa *primeiro;
    Pessoa *ultimo;

    //Fila prioritaria
    Pessoa *primeiroP;
    Pessoa *ultimoP;
    int lenght;
public:
    Fila();

    void inserir(Pessoa *pessoa);

    void inserirP(Pessoa *pessoa);

    void remover();

    void imprimir();

    bool isVazia();

};


#endif //LAB_10_FILA_HPP
