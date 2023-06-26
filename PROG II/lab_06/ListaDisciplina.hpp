//
// Created by vinic on 23/09/2022.
//

#ifndef LAB_06_LISTA_DISCIPLINA_HPP
#define LAB_06_LISTA_DISCIPLINA_HPP

#include "Disciplina.hpp"
class ListaDisciplina {

private:
    static int length;
    Disciplina* primeiro;
public:
    ListaDisciplina();
    void inserirDisciplina(Disciplina* disciplina);
    void imprimirDisciplinas();
};

#endif
