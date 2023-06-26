//
// Created by vinic on 07/11/2022.
//

#include "Fila.hpp"

Fila::Fila() {
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->primeiroP = nullptr;
    this->ultimoP = nullptr;
    this->lenght = 0;
}

void Fila::inserir(Pessoa *pessoa) {

    Pessoa *primeiro = this->primeiro;

    pessoa->setProx(primeiro);

    if (primeiro != nullptr)
        primeiro->setAnt(pessoa);

    if (primeiro == nullptr)
        this->ultimo = pessoa;

    this->primeiro = pessoa;

    this->lenght = this->lenght + 1;

}

void Fila::inserirP(Pessoa *pessoa) {

    Pessoa *primeiroP = this->primeiroP;

    pessoa->setProx(primeiroP);

    if (primeiroP != nullptr)
        primeiroP->setAnt(pessoa);

    if (primeiroP == nullptr)
        this->ultimoP = pessoa;

    this->primeiroP = pessoa;

    this->lenght = this->lenght + 1;

}

void Fila::remover() {

    if (this->ultimoP != nullptr) {
        Pessoa *ultimoP = this->ultimoP;
        this->ultimoP = ultimoP->getAnt();

        if (ultimoP->getAnt() != nullptr)
            ultimoP->getAnt()->setProx(nullptr);

        ultimoP->imprimir();
        delete ultimoP;
        this->lenght = this->lenght - 1;
        return;
    }

    if (this->ultimo != nullptr) {
        Pessoa *ultimo = this->ultimo;
        this->ultimo = ultimo->getAnt();

        if (ultimo->getAnt() != nullptr)
            ultimo->getAnt()->setProx(nullptr);

        ultimo->imprimir();
        delete ultimo;
        this->lenght = this->lenght - 1;
        return;
    }

}

void Fila::imprimir() {

    if (this->ultimo == nullptr) {
        cout << "Fila comum vazia\n";
    } else {
        Pessoa *elemento = this->primeiro;

        while (elemento) {
            elemento->imprimir();
            elemento = elemento->getProx();
        }
    }

    if (this->ultimoP == nullptr) {
        cout << "Fila Prioritária Vazia\n";
        return;
    } else {
        Pessoa *elemento = this->primeiroP;

        while (elemento) {
            elemento->imprimir();
            elemento = elemento->getProx();
        }
    }


}

bool Fila::isVazia() {
    if (this->lenght == 0)
        return true;
    else
        return false;
}
