//
// Created by vinic on 31/10/2022.
//

#ifndef LAB_08_PESSOAJURIDICA_HPP
#define LAB_08_PESSOAJURIDICA_HPP

#include "Pessoa.hpp"

class PessoaJuridica : public Pessoa {
private:
    string cnpj;
    PessoaJuridica *prox;
public:
    PessoaJuridica();

    PessoaJuridica(string nome, string cnpj);

    PessoaJuridica(string nome, double rendaBruta, string cnpj);

    double calcularIR();

    void imprimir();

    void setCnpj(string cnpj);

    string getCnpj();

    void setProx(PessoaJuridica *prox);

    PessoaJuridica *getProx();

};

#endif //LAB_08_PESSOAJURIDICA_HPP
