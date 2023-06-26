//
// Created by vinic on 28/09/2022.
//

#ifndef TRABALHO_2_LISTACONSULTAS_HPP
#define TRABALHO_2_LISTACONSULTAS_HPP


#include "Consulta.hpp"

class ListaConsultas {
private:
    static int length;
    Consulta *primeiro;
public:

    ListaConsultas();

    int buscarConsultasPorMedico(string cpf);
    Data buscarProximaData(string cpf);
    Data buscarUltimaConsulta(string cpf);
    int buscarProximoId();

    void inserirConsulta(Consulta *consulta);

    void removerConsulta(int consulta);

    void removerTodasConsultasMedicoOuPaciente(string cpf);

    void imprimirConsultas();
    void imprimirConsultasPorMedicoOuPaciente(string cpf);

    int numeroConsultas();

};


#endif //TRABALHO_2_LISTACONSULTAS_HPP
