//
// Created by vinic on 23/09/2022.
//



#include <iostream>
#include "string.h"

#include "Curso.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Disciplina.hpp"

string Curso::getNome() { return this->nome; }

void Curso::setNome(string nome) { this->nome = nome; }

void Curso::cadastrarProfessor(string nome, string endereco, string titulacao, string cpf) {
    Professor novoProfessor = Professor(nome, endereco, titulacao, cpf);
    this->professores.push_back(novoProfessor);
}

void Curso::cadastrarAluno(string nome, string endereco, int matricula, string cpf) {

    Aluno novoAluno = Aluno(nome, endereco, matricula, cpf);
    this->alunos.push_back(novoAluno);

}

void Curso::cadastrarDisciplina(string nome, int cargaHoraria, string cpfProfessor) {

    Professor professor;

    for (auto prof: this->professores) {
        if(prof.getCpf() == cpfProfessor)
            professor = prof;
    }

    if (professor.getNome().empty())
        return;

    Disciplina novaDisciplina = Disciplina(nome, cargaHoraria, professor);

    this->disciplinas.push_back(novaDisciplina);
}

void Curso::imprimirProfessores() {
    for (auto prof : this->professores) {
        cout << prof.getNome() << " - " << prof.getTitulacao() << " - " << prof.getCpf() << " - " << prof.getEndereco()
        << endl;
    }
}

void Curso::imprimirAlunos() {
    for (auto aluno : this->alunos) {
        cout << aluno.getNome() << " - " << aluno.getCpf() << " - "
             << aluno.getEndereco() << " - " << aluno.getMatricula()
             << endl;
    }
}

void Curso::imprimirDisciplinas() {
    for (auto disciplina : this->disciplinas) {
        cout << disciplina.getNome() << " - " << disciplina.getCargaHoraria() << " - "
             << disciplina.getProfessor().getNome() << endl;
    }
}

Curso::Curso() {
    this->nome = "";
}
