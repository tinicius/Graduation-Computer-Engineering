//
// Created by vinic on 17/10/2022.
//

#ifndef LPCI_POUPANCA_HPP
#define LPCI_POUPANCA_HPP

#include "Corrente.hpp"

class Poupanca : public Corrente {
private:
    int diaAniversario;
    Poupanca *prox;
public:
    Poupanca();

    Poupanca(string numeroDaConta, string nome, int diaAniversario);

    void imprimirExtrato();

    void setProx(Poupanca *prox);

    Poupanca *getProx();
};


#endif //LPCI_POUPANCA_HPP
