//
// Created by vinic on 23/09/2022.
//

#ifndef LAB_06_LISTA_PROFESSOR_HPP
#define LAB_06_LISTA_PROFESSOR_HPP

#include "Professor.hpp"
class ListaProfessor {

private:
    static int length;
    Professor* primeiro;
public:
    ListaProfessor();
    void inserirProfessor(Professor* professor);
    void imprimirProfessores();
    Professor buscarProfessor(string cpf);
};

#endif
