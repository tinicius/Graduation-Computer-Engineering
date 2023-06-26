//
// Created by vinic on 28/09/2022.
//

#ifndef TRABALHO_2_PACIENTE_HPP
#define TRABALHO_2_PACIENTE_HPP

#include "Pessoa.hpp"
#include "Data.hpp"

class Paciente : public Pessoa {
private:
    string relato;
    Data ultimaConsulta;
    string medicacao;
    Paciente *prox;
public:
    Paciente();

    Paciente(string relato, string medicacao, string nome, char sexo, string endereco, string cpf, string telefone);

    Paciente *getProx();

    void setProx(Paciente *paciente);

    string getRelato();

    void setRelato(string relato);

    Data getUltimaConsulta();

    void setUltimaConsulta(Data ultimaConsulta);

    string getMedicacao();

    void setMedicacao(string medicacao);
};


#endif //TRABALHO_2_PACIENTE_HPP
