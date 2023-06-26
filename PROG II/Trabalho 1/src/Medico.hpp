//
// Created by vinic on 28/09/2022.
//

#ifndef TRABALHO_2_MEDICO_HPP
#define TRABALHO_2_MEDICO_HPP

#include "Pessoa.hpp"

class Medico : public Pessoa {

private:
    int crm;
    string especialidade;
    Medico* prox;
public:
    Medico();

    Medico(int crm, string especialidade, string nome, char sexo, string endereco, string cpf, string telefone);

    Medico* getProx();
    void setProx(Medico* medico);

    int getCrm();

    void setCrm(int crm);

    string getEspecialidade();

    void setEspecialidade(string especialidade);
};


#endif //TRABALHO_2_MEDICO_HPP
