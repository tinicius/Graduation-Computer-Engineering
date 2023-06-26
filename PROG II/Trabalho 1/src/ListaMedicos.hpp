//
// Created by vinic on 28/09/2022.
//

#ifndef TRABALHO_2_LISTAMEDICOS_HPP
#define TRABALHO_2_LISTAMEDICOS_HPP

#include "Medico.hpp"

class ListaMedicos {
private:
    static int length;
    Medico *primeiro;
public:

    ListaMedicos();

    Medico* buscarMedico(string cpf);
    Medico* buscarMedico(int crm);

    void inserirMedico(Medico *medico);

    void removerMedico(string cpfMedico);

    void imprimirMedicos();

    int numeroMedicos();

};


#endif //TRABALHO_2_LISTAMEDICOS_HPP
