//
// Created by vinic on 28/09/2022.
//

#ifndef TRABALHO_2_LISTAPACIENTES_HPP
#define TRABALHO_2_LISTAPACIENTES_HPP

#include "Paciente.hpp"

class ListaPacientes {
private:
    static int length;
    Paciente* primeiro;
public:

    ListaPacientes();

    Paciente* buscarPaciente(string cpf);
    void inserirPaciente(Paciente* paciente);
    void removerPaciente(string cpfPaciente);
    void imprimirPacientes();
    int numeroPacientes();

};


#endif //TRABALHO_2_LISTAPACIENTES_HPP
