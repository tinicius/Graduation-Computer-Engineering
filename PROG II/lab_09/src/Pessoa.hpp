//
// Created by vinic on 31/10/2022.
//

#ifndef LAB_08_PESSOA_HPP
#define LAB_08_PESSOA_HPP

#include "iostream"

using namespace std;

class Pessoa {
protected:
    string nome;
    double rendaBruta;
public:
    Pessoa();
    Pessoa(string nome);
    Pessoa(string nome, double rendaBruta);
    double getRendaBruta();

    void setRendaBruta(double rendaBruta);

    void setNome(string nome);

    string getNome();

};


#endif //LAB_08_PESSOA_HPP
