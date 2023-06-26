//
// Created by vinic on 17/10/2022.
//

#ifndef LPCI_CORRENTELIMITE_HPP
#define LPCI_CORRENTELIMITE_HPP

#include "Corrente.hpp"

class CorrenteLimite : public Corrente {
protected:
    double limite;
    CorrenteLimite *prox;
public:
    CorrenteLimite();

    CorrenteLimite(string numeroDaConta, string nome, double limite);

    void retirada(double valor);

    void imprimirExtrato();

    void setProx(CorrenteLimite *prox);

    CorrenteLimite *getProx();
};

#endif //LPCI_CORRENTELIMITE_HPP
