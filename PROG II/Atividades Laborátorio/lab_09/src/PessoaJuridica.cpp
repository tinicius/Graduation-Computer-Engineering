//
// Created by vinic on 31/10/2022.
//

#include "PessoaJuridica.hpp"

PessoaJuridica::PessoaJuridica() : Pessoa() {
    this->cnpj = "";
    this->prox = nullptr;
}

PessoaJuridica::PessoaJuridica(string nome, string cnpj) : Pessoa(nome) {
    this->cnpj = "";
    this->prox = nullptr;
}

PessoaJuridica::PessoaJuridica(string nome, double rendaBruta, string cnpj) : Pessoa(nome, rendaBruta) {
    this->cnpj = cnpj;
    this->prox = nullptr;
}

void PessoaJuridica::setCnpj(string cnpj) {
    this->cnpj = cnpj;
}

string PessoaJuridica::getCnpj() {
    return this->cnpj;
}

void PessoaJuridica::setProx(PessoaJuridica *prox) {
    this->prox = prox;
}

PessoaJuridica *PessoaJuridica::getProx() {
    return this->prox;
}

void PessoaJuridica::imprimir() {
    cout << "Nome: " << this->nome << endl;
    cout << "CNPJ: " << this->cnpj << endl;
    cout << "Renda Bruta: R$ " << this->rendaBruta << endl;
    cout << "IR: R$ " << this->calcularIR() << endl;
    cout << endl;
}

double PessoaJuridica::calcularIR() {
    return this->rendaBruta * (10.0 / 100);
}
