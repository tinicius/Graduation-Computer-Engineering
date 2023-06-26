//
// Created by vinic on 07/11/2022.
//

#include "Pilha.hpp"

Pilha::Pilha() {
    this->lenght = 0;
    this->ultimo = nullptr;
}

void Pilha::inserir(Livro *livro) {

    Livro *topo = this->ultimo;
    this->ultimo = livro;
    livro->setProx(topo);
    this->lenght = this->lenght + 1;

    livro->imprimir();
    cout << "Livros: " << this->lenght << endl;

}

void Pilha::remover() {

    if (this->ultimo == nullptr)
        return;

    Livro *topo = this->ultimo;
    this->ultimo = topo->getProx();
    this->lenght = this->lenght - 1;

    topo->imprimir();
    cout << "Livros: " << this->lenght << endl;

    delete topo;
}

void Pilha::mostrarTopo() {

    if (this->ultimo == nullptr) {
        cout << "Pilha vazia!\n";
        return;
    }

    this->ultimo->imprimir();
}

bool Pilha::isVazia() {
    if (this->ultimo == nullptr)
        return true;
    return false;
}
