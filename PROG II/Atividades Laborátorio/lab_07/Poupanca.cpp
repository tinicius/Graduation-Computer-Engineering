//
// Created by vinic on 17/10/2022.
//

#include "iostream"

using namespace std;

#include "Poupanca.hpp"

void Poupanca::imprimirExtrato() {
    Corrente::imprimirExtrato();
    cout << "Dia: " << this->diaAniversario << endl;
}

void Poupanca::setProx(Poupanca *prox) {
    this->prox = prox;
}

Poupanca *Poupanca::getProx() {
    return this->prox;
}

Poupanca::Poupanca() : Corrente() {
    this->diaAniversario = 0;
    this->prox = nullptr;
}

Poupanca::Poupanca(string numeroDaConta, string nome, int diaAniversario) : Corrente(numeroDaConta, nome) {
    this->diaAniversario = diaAniversario;
    this->prox = nullptr;
}
