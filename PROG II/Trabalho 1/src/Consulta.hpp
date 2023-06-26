//
// Created by vinic on 28/09/2022.
//

#ifndef TRABALHO_2_CONSULTA_HPP
#define TRABALHO_2_CONSULTA_HPP

#include "Paciente.hpp"
#include "Medico.hpp"

class Consulta {
private:
    Paciente paciente;
    Medico medico;
    Data data;
    Consulta *prox;
    int id;
public:
    Consulta();

    Consulta(Paciente paciente, Medico medico, Data data, int id);

    void imprimir();

    int getId();

    Consulta *getProx();

    void setProx(Consulta *consulta);

    Paciente getPaciente();

    void setPaciente(Paciente paciente);

    Medico getMedico();

    void setMedico(Medico medico);

    Data getData();

    void setData(Data data);

};


#endif //TRABALHO_2_CONSULTA_HPP
