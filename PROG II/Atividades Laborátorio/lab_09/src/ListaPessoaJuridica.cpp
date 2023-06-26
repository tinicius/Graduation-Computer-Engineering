//
// Created by vinic on 31/10/2022.
//

#include "ListaPessoaJuridica.hpp"

int ListaPessoaJuridica::getLength() {
    return this->length;
}

void ListaPessoaJuridica::inserir(PessoaJuridica *pessoaJuridica) {

    if (this->length == 0) {
        this->primeiro = pessoaJuridica;
        this->length = this->length + 1;
    } else {
        pessoaJuridica->setProx(primeiro);
        this->primeiro = pessoaJuridica;
        this->length = this->length + 1;
    }

}

void ListaPessoaJuridica::remover(string cnpj) {

    if (this->length == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    if (this->primeiro->getCnpj() == cnpj){
        PessoaJuridica* atual = this->primeiro;
        this->primeiro = this->primeiro->getProx();
        delete atual;
        this->length = this->length - 1;
        return;
    }

    PessoaJuridica *anterior = this->primeiro;
    PessoaJuridica *atual = anterior->getProx();

    while (atual) {

        if (atual->getCnpj() == cnpj) {
            anterior->setProx(atual->getProx());
            delete atual;
            return;
        }

        anterior = atual;
        atual = atual->getProx();
    }

}

ListaPessoaJuridica::ListaPessoaJuridica() {
    this->length = 0;
    this->primeiro = nullptr;
}

void ListaPessoaJuridica::imprimir() {

    if (this->length == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    PessoaJuridica *aux = this->primeiro;

    while (aux) {
        aux->imprimir();
        aux = aux->getProx();
    }

}

void ListaPessoaJuridica::buscar(string cnpj) {

    if (this->length == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    PessoaJuridica *aux = this->primeiro;

    while (aux) {
        if (aux->getCnpj() == cnpj) {
            aux->imprimir();
            return;
        }
        aux = aux->getProx();
    }

}
