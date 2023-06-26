//
// Created by vinic on 23/09/2022.
//

#include "Professor.hpp"

string Professor::getTitulacao() {
    return this->titulacao;
}

void Professor::setTitulacao(string titulacao) {
    this->titulacao = titulacao;
}

Professor::Professor() : Pessoa() {
    this->titulacao = "";
    this->prox = nullptr;
}

Professor::Professor(string nome, string endereco, string titulacao, string cpf) : Pessoa(nome, endereco, cpf) {
    this->titulacao = titulacao;
    this->prox = nullptr;
}

Professor *Professor::getProx() {
    return this->prox;
}

void Professor::setProx(Professor *prox) {
    this->prox = prox;
}

