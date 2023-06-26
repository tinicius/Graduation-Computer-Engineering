//
// Created by vinic on 23/09/2022.
//

#ifndef LAB_06_PROFESSOR_HPP
#define LAB_06_PROFESSOR_HPP

#include "string"
#include "Pessoa.hpp"

using namespace std;

class Professor : public Pessoa {

public:

    Professor();

    Professor(string nome, string endereco, string titulacao, string cpf);

    string getTitulacao();

    void setTitulacao(string titulacao);

    Professor *getProx();

    void setProx(Professor *prox);

private:
    string titulacao;
    Professor *prox;
};


#endif //LAB_06_PROFESSOR_HPP
