//
// Created by vinic on 28/09/2022.
//

#include "Pessoa.hpp"


Pessoa::Pessoa() {
    nome = "";
    sexo = ' ';
    endereco = "";
    cpf = "";
    telefone = "";
}

Pessoa::Pessoa(string nome, char sexo, string endereco, string cpf, string telefone) {
    this->nome = nome;
    this->sexo = sexo;
    this->endereco = endereco;
    this->cpf = cpf;
    this->telefone = telefone;
}

string Pessoa::getNome() {
    return nome;
}

void Pessoa::setNome(string nome) {
    Pessoa::nome = nome;
}

char Pessoa::getSexo() {
    return sexo;
}

void Pessoa::setSexo(char sexo) {
    this->sexo = sexo;
}

string Pessoa::getEndereco() {
    return endereco;
}

void Pessoa::setEndereco(string endereco) {
    Pessoa::endereco = endereco;
}

string Pessoa::getCpf() {
    return cpf;
}

void Pessoa::setCpf(string cpf) {
    Pessoa::cpf = cpf;
}

string Pessoa::getTelefone() {
    return telefone;
}

void Pessoa::setTelefone(string telefone) {
    Pessoa::telefone = telefone;
}

void Pessoa::imprimir() {
    printf("%s, %c, %s, %s, %s\n", nome.c_str(), sexo, endereco.c_str(), cpf.c_str(), telefone.c_str());
}
