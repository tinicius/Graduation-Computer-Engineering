//
// Created by vinic on 17/10/2022.
//

#include "iostream"
#include <time.h>

using namespace std;

#include "Corrente.hpp"
#include "ExceptionLimite.hpp"

Corrente::Corrente() {
    this->nome = "";
    this->numeroDaConta = "";
    this->saldo = 0.0;
    this->transacoes = "";
    this->prox = nullptr;
}

Corrente::Corrente(string numeroDaConta, string nome) {
    this->nome = nome;
    this->numeroDaConta = numeroDaConta;
    this->saldo = 0.0;
    this->transacoes = "";
    this->prox = nullptr;
}

void Corrente::deposito(double valor) {
    this->saldo += valor;

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);

    printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    string data = "Data: " + to_string(tm.tm_mday) + "/" + to_string(tm.tm_mon + 1) + "/" + to_string(tm.tm_year + 1900);

    this->transacoes += "Deposito - " + data + " " + to_string(valor) + "\n";
}

void Corrente::retirada(double valor) {

    if (this->saldo - valor >= 0) {
        this->saldo -= valor;

        time_t mytime;
        mytime = time(NULL);
        struct tm tm = *localtime(&mytime);

        printf("Data: %d/%d/%d/\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

        string data = "Data: " + to_string(tm.tm_mday) + "/" + to_string(tm.tm_mon + 1) + "/" + to_string(tm.tm_year + 1900);

        this->transacoes += "Retirada - " + data + " " + to_string(valor) + "\n";
    } else {
        throw ExceptionLimite();
    }
}

void Corrente::imprimirExtrato() {
    cout << "Nome: " << this->nome << endl;
    cout << "Número da conta: " << this->numeroDaConta << endl;
    cout << "-----------------" << endl;
    if (this->transacoes == "") {
        cout << "Não há transações" << endl;
    } else {
        cout << this->transacoes;
    }
    cout << "-----------------" << endl;
    cout << "Saldo: R$ " << this->saldo << endl;
}

void Corrente::setProx(Corrente *corrente) {
    this->prox = corrente;
}

Corrente *Corrente::getProx() {
    return this->prox;
}

string Corrente::getConta() {
    return this->numeroDaConta;
}
