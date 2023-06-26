//
// Created by vinic on 07/11/2022.
//

#ifndef LAB_10_PESSOA_HPP
#define LAB_10_PESSOA_HPP

#include "iostream"

using namespace std;

class Pessoa {
private:
    string nome;
    string cpf;
    Pessoa *prox;
    Pessoa *ant;

public:
    Pessoa();

    Pessoa(string nome, string cpf);

    void imprimir();

    string getNome();

    void setNome(string nome);

    string getCpf();

    void setCpf(string cpf);

    Pessoa *getProx();


    void setProx(Pessoa *prox);

    Pessoa *getAnt();

    void setAnt(Pessoa *ant);

};


#endif //LAB_10_PESSOA_HPP
