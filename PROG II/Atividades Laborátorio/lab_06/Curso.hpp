//
// Created by vinic on 23/09/2022.
//

#ifndef LAB_06_CURSO_HPP
#define LAB_06_CURSO_HPP

#include "ListaAluno.hpp"
#include "ListaProfessor.hpp"
#include "ListaDisciplina.hpp"

#include "string"

using namespace std;

class Curso {
public:
    Curso();
    void cadastrarProfessor(string nome, string endereco, string titulacao, string cpf);

    void cadastrarAluno(string nome, string endereco, int matricula, string cpf);

    void cadastrarDisciplina(string nome, int cargaHoraria, string cpfProfessor);

    void imprimirProfessores();

    void imprimirAlunos();

    void imprimirDisciplinas();

    string getNome();

    void setNome(string nome);

private:
    string nome;

    ListaProfessor professores;

    ListaAluno alunos;

    ListaDisciplina disciplinas;
};


#endif //LAB_06_CURSO_HPP
