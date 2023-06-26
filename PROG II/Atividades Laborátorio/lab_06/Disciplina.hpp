//
// Created by vinic on 23/09/2022.
//

#ifndef LAB_06_DISCIPLINA_HPP
#define LAB_06_DISCIPLINA_HPP

#include "string"
#include "Professor.hpp"

using namespace std;


class Disciplina {
public:
    Disciplina();

    Disciplina(string nome, int cargaHoraria, Professor professor);

    string getNome();

    void setNome(string nome);

    int getCargaHoraria();

    void setCargaHoraria(int cargaHoraria);

    Professor getProfessor();

    void setProfessor(Professor professor);

    Disciplina *getProx();
    void setProx(Disciplina *prox);

private:
    string nome;
    int cargaHoraria;
    Professor professor;
    Disciplina* prox;

};


#endif //LAB_06_DISCIPLINA_HPP
