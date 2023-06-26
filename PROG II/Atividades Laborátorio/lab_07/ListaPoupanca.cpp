//
// Created by vinic on 18/10/2022.
//

#include "ListaPoupanca.hpp"
#include "ExceptionLimite.hpp"
#include "iostream"

using namespace std;

ListaPoupanca::ListaPoupanca() {
    this->length = 0;
    this->primeiro = nullptr;
}

void ListaPoupanca::inserir(Poupanca *poupanca) {

    if (this->length == 0) {
        this->primeiro = poupanca;
    } else {
        poupanca->setProx(primeiro);
        this->primeiro = poupanca;
    }

    this->length = this->length + 1;
}

void ListaPoupanca::imprimir(string conta) {
    if (this->length == 0) {
        cout << "Não há contas poupança cadastradas \n";
        return;
    }

    Corrente *elemento = this->primeiro;

    while (elemento) {

        if (elemento->getConta() == conta) {
            elemento->imprimirExtrato();
            return;
        }

        elemento = elemento->getProx();
    }

}

void ListaPoupanca::deposito(string conta, double valor) {

    if (this->length == 0) {
        cout << "Não há contas poupança cadastradas \n";
        return;
    }

    Corrente *elemento = this->primeiro;

    while (elemento) {

        if (elemento->getConta() == conta) {
            elemento->deposito(valor);
            return;
        }

        elemento = elemento->getProx();
    }

}

void ListaPoupanca::retirada(string conta, double valor) {

    if (this->length == 0) {
        cout << "Não há contas poupança cadastradas \n";
        return;
    }

    Corrente *elemento = this->primeiro;

    while (elemento) {

        if (elemento->getConta() == conta) {
            try {
                elemento->retirada(valor);
                cout << "Retirada realizada com sucesso!" << endl;
            } catch (ExceptionLimite &error) {
                cout << error.what() << endl;
            }

            return;
        }

        elemento = elemento->getProx();
    }

}


