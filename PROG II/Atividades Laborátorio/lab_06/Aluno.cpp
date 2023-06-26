//
// Created by vinic on 23/09/2022.
//

#include "Aluno.hpp"

int Aluno::getMatricula() { return this->matricula; }

void Aluno::setMatricula(int matricula) { this->matricula = matricula; }

Aluno::Aluno(string nome, string endereco, int matricula, string cpf)
        : Pessoa(nome, endereco, cpf) {
    this->matricula = matricula;
    this->prox = nullptr;
}

Aluno::Aluno() : Pessoa() {
    this->matricula = 0;
    this->prox = nullptr;
}

Aluno *Aluno::getProx() { return this->prox; }

void Aluno::setProx(Aluno *prox) { this->prox = prox; }
