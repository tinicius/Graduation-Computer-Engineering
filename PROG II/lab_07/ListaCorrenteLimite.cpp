//
// Created by vinic on 17/10/2022.
//

#include "ListaCorrenteLimite.hpp"
#include "ExceptionLimite.hpp"
#include "iostream"

using namespace std;

ListaCorrenteLimite::ListaCorrenteLimite() {
    this->length = 0;
    this->primeiro = nullptr;
}

void ListaCorrenteLimite::inserir(CorrenteLimite *correnteLimite) {

    if (this->length == 0) {
        this->primeiro = correnteLimite;
    } else {
        correnteLimite->setProx(primeiro);
        this->primeiro = correnteLimite;
    }

    this->length = this->length + 1;

}

void ListaCorrenteLimite::imprimir(string conta) {

    if (this->length == 0) {
        cout << "Não há contas correntes com limite cadastradas \n";
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

void ListaCorrenteLimite::deposito(string conta, double valor) {

    if (this->length == 0) {
        cout << "Não há contas corrente com limite cadastradas \n";
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

void ListaCorrenteLimite::retirada(string conta, double valor) {

    if (this->length == 0) {
        cout << "Não há contas corrente com limite cadastradas \n";
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
