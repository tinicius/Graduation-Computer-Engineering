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

private:
    string nome;
    int cargaHoraria;
    Professor professor;
};


#endif //LAB_06_DISCIPLINA_HPP
