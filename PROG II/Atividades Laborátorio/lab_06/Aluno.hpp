//
// Created by vinic on 23/09/2022.
//

#ifndef LAB_06_ALUNO_HPP
#define LAB_06_ALUNO_HPP


#include "Pessoa.hpp"

class Aluno : public Pessoa {

private:
    int matricula;
    Aluno *prox;

public:
    Aluno();

    Aluno(string nome, string endereco, int matricula, string cpf);

    int getMatricula();

    void setMatricula(int matricula);

    Aluno *getProx();

    void setProx(Aluno *prox);
};


#endif //LAB_06_ALUNO_HPP
