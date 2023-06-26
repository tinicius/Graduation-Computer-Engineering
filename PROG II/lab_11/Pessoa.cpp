//
// Created by vinic on 22/09/2022.
//

#include "Pessoa.hpp"

string Pessoa::getNome() {
    return this->nome;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

string Pessoa::getEndereco() {
    return this->endereco;
}

void Pessoa::setEndereco(string endereco) {
    this->endereco = endereco;
}

Pessoa::Pessoa() {
    this->nome = "";
    this->endereco = "";
    this->cpf = "";
}

Pessoa::Pessoa(string nome, string endereco, string cpf) {
    this->nome = nome;
    this->endereco = endereco;
    this->cpf = cpf;
}

string Pessoa::getCpf() {
    return this->cpf;
}

void Pessoa::setCpf(string cpf) {
    this->cpf = cpf;
}


