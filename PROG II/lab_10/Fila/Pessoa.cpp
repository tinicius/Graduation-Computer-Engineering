//
// Created by vinic on 07/11/2022.
//

#include "Pessoa.hpp"

string Pessoa::getNome() {
    return nome;
}

void Pessoa::setNome(string nome) {
    Pessoa::nome = nome;
}

string Pessoa::getCpf() {
    return cpf;
}

void Pessoa::setCpf(string cpf) {
    Pessoa::cpf = cpf;
}

Pessoa *Pessoa::getProx() {
    return prox;
}

void Pessoa::setProx(Pessoa *prox) {
    Pessoa::prox = prox;
}

Pessoa::Pessoa() {
    this->nome = "";
    this->cpf = "";
    this->prox = nullptr;
    this->ant = nullptr;
}

Pessoa::Pessoa(string nome, string cpf) {
    this->nome = nome;
    this->cpf = cpf;
    this->prox = nullptr;
    this->ant = nullptr;
}

Pessoa *Pessoa::getAnt() {
    return this->ant;
}

void Pessoa::setAnt(Pessoa *ant) {
    Pessoa::ant = ant;
}

void Pessoa::imprimir() {
    cout << "Pessoa: " << this->nome << " " << this->cpf << endl;
}
