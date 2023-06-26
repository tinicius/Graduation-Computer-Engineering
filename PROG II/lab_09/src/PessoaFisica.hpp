//
// Created by vinic on 31/10/2022.
//

#ifndef LAB_08_PESSOAFISICA_HPP
#define LAB_08_PESSOAFISICA_HPP

#include "Pessoa.hpp"

class PessoaFisica : public Pessoa {
private:
    string cpf;
    PessoaFisica *prox;
public:
    PessoaFisica();

    PessoaFisica(string nome, string cpf);

    PessoaFisica(string nome, double rendaBruta, string cpf);

    void imprimir();

    double calcularIR();

    void setCpf(string cpf);

    string getCpf();

    void setProx(PessoaFisica *prox);

    PessoaFisica *getProx();


};


#endif //LAB_08_PESSOAFISICA_HPP
