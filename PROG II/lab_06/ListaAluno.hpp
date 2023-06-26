//
// Created by vinic on 23/09/2022.
//

#ifndef LAB_06_LISTA_ALUNO_HPP
#define LAB_06_LISTA_ALUNO_HPP

#include "Aluno.hpp"
class ListaAluno {

private:
    static int length;
    Aluno* primeiro;
public:
    ListaAluno();
    void inserirAluno(Aluno* Aluno);
    void imprimirAlunos();
};

#endif //LAB_06_ALUNO_HPP
