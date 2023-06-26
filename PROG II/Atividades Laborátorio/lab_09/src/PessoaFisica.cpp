//
// Created by vinic on 31/10/2022.
//

#include "PessoaFisica.hpp"

void PessoaFisica::setCpf(string cpf) {
    this->cpf = cpf;
}

string PessoaFisica::getCpf() {
    return this->cpf;
}

PessoaFisica::PessoaFisica() : Pessoa() {
    this->cpf = "";
    this->prox = nullptr;
}

PessoaFisica::PessoaFisica(string nome, string cpf) : Pessoa(nome) {
    this->cpf = cpf;
    this->prox = nullptr;
}

PessoaFisica::PessoaFisica(string nome, double rendaBruta, string cpf) : Pessoa(nome, rendaBruta) {
    this->cpf = cpf;
    this->prox = nullptr;
}

void PessoaFisica::setProx(PessoaFisica *prox) {
    this->prox = prox;
}

PessoaFisica *PessoaFisica::getProx() {
    return this->prox;
}

void PessoaFisica::imprimir() {
    cout << "Nome: " << this->nome << endl;
    cout << "CPF: " << this->cpf << endl;
    cout << "Renda Bruta: R$ " << this->rendaBruta << endl;
    cout << "IR: R$ " << this->calcularIR() << endl;
    cout << endl;
}

double PessoaFisica::calcularIR() {

    double aliquota, deduzir;

    if (this->rendaBruta < 1903.98) {
        aliquota = 0.0;
        deduzir = 0.0;
    } else if (this->rendaBruta >= 1903.98 && this->rendaBruta < 2826.65) {
        aliquota = 7.5 / 100;
        deduzir = 142.80;
    } else if (this->rendaBruta >= 2826.65 && this->rendaBruta < 3751.06) {
        aliquota = 15.0 / 100;
        deduzir = 354.80;
    } else if (this->rendaBruta >= 3751.06 && this->rendaBruta < 4664.68) {
        aliquota = 22.5 / 100;
        deduzir = 636.13;
    } else {
        aliquota = 27.5 / 100;
        deduzir = 869.36;
    }

    return (rendaBruta * aliquota) - deduzir;

}
