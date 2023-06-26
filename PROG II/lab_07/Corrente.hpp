//
// Created by vinic on 17/10/2022.
//

#ifndef LPCI_CORRENTE_HPP
#define LPCI_CORRENTE_HPP

#include "string"

using namespace std;

class Corrente {

protected:
    string numeroDaConta;
    string nome;
    double saldo;
    string transacoes;
    Corrente *prox;
public:
    Corrente();

    Corrente(string numeroDaConta, string nome);

    void deposito(double valor);

    virtual void retirada(double valor);

    virtual void imprimirExtrato();

    string getConta();

    void setProx(Corrente *corrente);

    virtual Corrente *getProx();

};


#endif //LPCI_CORRENTE_HPP
