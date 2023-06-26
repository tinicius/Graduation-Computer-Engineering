//
// Created by vinic on 31/10/2022.
//

#include "ListaPessoaFisica.hpp"

int ListaPessoaFisica::getLength() {
    return this->length;
}

void ListaPessoaFisica::inserir(PessoaFisica *pessoaFisica) {

    if (this->length == 0) {
        this->primeiro = pessoaFisica;
        this->length = this->length + 1;
    } else {
        pessoaFisica->setProx(primeiro);
        this->primeiro = pessoaFisica;
        this->length = this->length + 1;
    }

}

void ListaPessoaFisica::remover(string cpf) {

    if (this->length == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    if (this->primeiro->getCpf() == cpf){
        PessoaFisica* atual = this->primeiro;
        this->primeiro = this->primeiro->getProx();
        delete atual;
        this->length = this->length - 1;
        return;
    }
    
    PessoaFisica *anterior = this->primeiro;
    PessoaFisica *atual = anterior->getProx();

    while (atual) {

        if (atual->getCpf() == cpf) {
            anterior->setProx(atual->getProx());
            delete atual;
            this->length = this->length - 1;
            return;
        }

        anterior = atual;
        atual = atual->getProx();
    }

}

ListaPessoaFisica::ListaPessoaFisica() {
    this->length = 0;
    this->primeiro = nullptr;
}

void ListaPessoaFisica::imprimir() {

    if (this->length == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    PessoaFisica *aux = this->primeiro;

    while (aux) {
        aux->imprimir();
        aux = aux->getProx();
    }

}

void ListaPessoaFisica::buscar(string cpf) {

    if (this->length == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    PessoaFisica *aux = this->primeiro;

    while (aux) {
        if (aux->getCpf() == cpf) {
            aux->imprimir();
            return;
        }
        aux = aux->getProx();
    }

}
