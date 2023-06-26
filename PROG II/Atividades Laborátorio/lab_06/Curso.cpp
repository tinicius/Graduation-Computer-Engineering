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
    Professor *novoProfessor = new Professor(nome, endereco, titulacao, cpf);
    professores.inserirProfessor(novoProfessor);
}

void Curso::cadastrarAluno(string nome, string endereco, int matricula, string cpf) {

    Aluno *novoAluno = new Aluno(nome, endereco, matricula, cpf);
    alunos.inserirAluno(novoAluno);    

}

void Curso::cadastrarDisciplina(string nome, int cargaHoraria, string cpfProfessor) {

    Professor professor = professores.buscarProfessor(cpfProfessor);

    Disciplina *novaDisciplina = new Disciplina(nome, cargaHoraria, professor);

    disciplinas.inserirDisciplina(novaDisciplina);
}

void Curso::imprimirProfessores() {
    professores.imprimirProfessores();
}

void Curso::imprimirAlunos() {
    alunos.imprimirAlunos();
}

void Curso::imprimirDisciplinas() {
    disciplinas.imprimirDisciplinas();
}

Curso::Curso() {
    this->nome = "";
}
