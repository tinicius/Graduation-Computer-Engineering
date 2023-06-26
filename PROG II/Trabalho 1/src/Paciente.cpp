//
// Created by vinic on 28/09/2022.
//

#include "Paciente.hpp"
#include "iostream"

using namespace std;

string Paciente::getRelato() {
    return relato;
}

void Paciente::setRelato(string relato) {
    Paciente::relato = relato;
}

Data Paciente::getUltimaConsulta() {
    return ultimaConsulta;
}

void Paciente::setUltimaConsulta(Data ultimaConsulta) {
    Paciente::ultimaConsulta = ultimaConsulta;
}

string Paciente::getMedicacao() {
    return medicacao;
}

void Paciente::setMedicacao(string medicacao) {
    Paciente::medicacao = medicacao;
}

Paciente::Paciente() : Pessoa() {
    relato = "";
    medicacao = "";
    prox = nullptr;
}

Paciente::Paciente(string relato, string medicacao, string nome, char sexo, string endereco,
                   string cpf, string telefone) : Pessoa(nome, sexo, endereco, cpf, telefone) {
    this->relato = relato;
    this->ultimaConsulta = ultimaConsulta;
    this->medicacao = medicacao;
    this->prox = nullptr;
}

Paciente *Paciente::getProx() {
    return prox;
}

void Paciente::setProx(Paciente *paciente) {
    this->prox = paciente;
}
