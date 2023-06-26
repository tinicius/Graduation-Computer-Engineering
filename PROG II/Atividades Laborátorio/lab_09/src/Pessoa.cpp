//
// Created by vinic on 31/10/2022.
//

#include "Pessoa.hpp"

double Pessoa::getRendaBruta() {
    return rendaBruta;
}

void Pessoa::setRendaBruta(double rendaBruta) {
   this->rendaBruta = rendaBruta;
}

void Pessoa::setNome(string nome) {
    this->nome = nome;
}

string Pessoa::getNome() {
    return this->nome;
}

Pessoa::Pessoa() {
    this->nome = "";
    this->rendaBruta = 0;
}

Pessoa::Pessoa(string nome) {
    this->nome = nome;
    this->rendaBruta = 0;
}

Pessoa::Pessoa(string nome, double rendaBruta) {
    this->nome = nome;
    this->rendaBruta = rendaBruta;
}
