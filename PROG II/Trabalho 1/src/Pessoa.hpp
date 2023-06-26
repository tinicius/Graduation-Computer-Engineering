//
// Created by vinic on 28/09/2022.
//

#ifndef TRABALHO_2_PESSOA_HPP
#define TRABALHO_2_PESSOA_HPP

#include "string"

using namespace std;

class Pessoa {

protected:
    string nome;
    char sexo;
    string endereco;
    string cpf;
    string telefone;
public:
    Pessoa();
    Pessoa(string nome, char sexo, string endereco, string cpf, string telefone);

    void imprimir();

    string getNome();

    void setNome(string nome);

    char getSexo();

    void setSexo(char sexo);

    string getEndereco();

    void setEndereco(string endereco);

    string getCpf();

    void setCpf(string cpf);

    string getTelefone();

    void setTelefone(string telefone);
    
};


#endif //TRABALHO_2_PESSOA_HPP
