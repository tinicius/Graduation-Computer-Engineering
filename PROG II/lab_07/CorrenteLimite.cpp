//
// Created by vinic on 17/10/2022.
//

#include <iostream>
using namespace std;

#include "CorrenteLimite.hpp"
#include "ExceptionLimite.hpp"

CorrenteLimite::CorrenteLimite() : Corrente() {
    this->limite = 0;
    this->prox = nullptr;
}

CorrenteLimite::CorrenteLimite(string numeroDaConta, string nome, double limite) : Corrente(numeroDaConta, nome) {
    this->limite = limite;
    this->prox = nullptr;
}

void CorrenteLimite::retirada(double valor) {

    double min = 0.0 - limite;

    if ((this->saldo - valor) < min) {
        throw ExceptionLimite();
    } else {
        this->saldo -= valor;
        time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);

        printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

        string data = "Data: " + to_string(tm.tm_mday) + "/" + to_string(tm.tm_mon + 1) + "/" + to_string(tm.tm_year + 1900);

        this->transacoes += "Retirada - " + data + " " + to_string(valor) + "\n";
    }

}

void CorrenteLimite::imprimirExtrato() {
    Corrente::imprimirExtrato();
    cout << "Limite: R$ -" << this->limite << endl;
}

void CorrenteLimite::setProx(CorrenteLimite *prox) {
    this->prox = prox;
}

CorrenteLimite *CorrenteLimite::getProx() {
    return this->prox;
}
