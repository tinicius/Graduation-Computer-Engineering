//
// Created by vinic on 28/09/2022.
//

#include "Medico.hpp"
#include "iostream"

using namespace std;

int Medico::getCrm() {
    return crm;
}

void Medico::setCrm(int crm) {
    Medico::crm = crm;
}

string Medico::getEspecialidade() {
    return especialidade;
}

void Medico::setEspecialidade(string especialidade) {
    Medico::especialidade = especialidade;
}

Medico::Medico() : Pessoa() {
    crm = 0;
    especialidade = "";
}

Medico::Medico(int crm, string especialidade, string nome, char sexo, string endereco, string cpf, string telefone) : Pessoa(nome,
                                                                                                                             sexo,
                                                                                                                             endereco,
                                                                                                                             cpf,
                                                                                                                             telefone) {

    this->crm = crm;
    this->especialidade = especialidade;

}

Medico *Medico::getProx() {
    return prox;
}

void Medico::setProx(Medico *medico) {
    this->prox = medico;
}
