//
// Created by vinic on 22/09/2022.
//

#ifndef LAB_06_PESSOA_HPP
#define LAB_06_PESSOA_HPP

#include "string"

using namespace std;

class Pessoa {
   private:
    string nome;
    string endereco;
    string cpf;

   public:
    Pessoa();

    Pessoa(string nome, string endereco, string cpf);

    string getNome();

    void setNome(string nome);

    string getEndereco();

    void setEndereco(string endereco);

    string getCpf();

    void setCpf(string cpf);
};

#endif  // LAB_06_PESSOA_HPP
