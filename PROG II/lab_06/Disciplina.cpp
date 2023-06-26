//
// Created by vinic on 23/09/2022.
//

#include "Disciplina.hpp"

string Disciplina::getNome() {
    return this->nome;
}

void Disciplina::setNome(string nome) {
    this->nome = nome;
}

int Disciplina::getCargaHoraria() {
    return this->cargaHoraria;
}

void Disciplina::setCargaHoraria(int cargaHoraria) {
    this->cargaHoraria = cargaHoraria;
}

Professor Disciplina::getProfessor() {
    return this->professor;
}

void Disciplina::setProfessor(Professor professor) {
    this->professor = professor;
}

Disciplina::Disciplina() {
    this->nome = "";
    this->cargaHoraria = 0;
    this->professor = Professor();
    this->prox = nullptr;
}

Disciplina::Disciplina(string nome, int cargaHoraria, Professor professor) {
    this->nome = nome;
    this->cargaHoraria = cargaHoraria;
    this->professor = professor;
    this->prox = nullptr;
}

Disciplina *Disciplina::getProx() {
    return this->prox;
}

void Disciplina::setProx(Disciplina *prox) {
    this->prox = prox;
}
