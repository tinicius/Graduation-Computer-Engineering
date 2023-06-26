//
// Created by vinic on 17/10/2022.
//

#ifndef LAB_07_CONTAS_HPP
#define LAB_07_CONTAS_HPP

#include "ListaCorrente.hpp"
#include "ListaCorrenteLimite.hpp"
#include "ListaPoupanca.hpp"

class Contas {

private:
    ListaCorrente listaCorrente;
    ListaCorrenteLimite listaCorrenteLimite;
    ListaPoupanca listaPoupanca;
    int length;
public:
    Contas();

    void inserir(string nome, string tipo);

    void imprimir(string conta);

    void deposito(string conta, double valor);

    void retirada(string conta, double valor);
};


#endif //LAB_07_CONTAS_HPP
