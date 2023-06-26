//
// Created by vinic on 17/10/2022.
//

#include "ListaCorrente.hpp"
#include "ExceptionLimite.hpp"
#include "iostream"

using namespace std;

void ListaCorrente::inserir(Corrente *corrente) {

    if (this->length == 0) {
        this->primeiro = corrente;
    } else {
        corrente->setProx(primeiro);
        this->primeiro = corrente;
    }

    this->length = this->length + 1;

}

ListaCorrente::ListaCorrente() {
    this->primeiro = nullptr;
    this->length = 0;
}

void ListaCorrente::imprimir(string conta) {

    if (this->length == 0) {
        cout << "Não há contas correntes cadastradas \n";
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

void ListaCorrente::deposito(string conta, double valor) {

    if (this->length == 0) {
        cout << "Não há contas correntes cadastradas \n";
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

void ListaCorrente::retirada(string conta, double valor) {

    if (this->length == 0) {
        cout << "Não há contas correntes cadastradas \n";
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


