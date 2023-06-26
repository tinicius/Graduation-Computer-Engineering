//
// Created by vinic on 31/10/2022.
//

#ifndef LAB_08_LISTAPESSOAFISICA_HPP
#define LAB_08_LISTAPESSOAFISICA_HPP

#include "PessoaFisica.hpp"

class ListaPessoaFisica {
private:
    int length;
    PessoaFisica *primeiro;
public:
    ListaPessoaFisica();

    int getLength();

    void inserir(PessoaFisica *pessoaFisica);

    void remover(string cpf);

    void buscar(string cpf);

    void imprimir();

};


#endif //LAB_08_LISTAPESSOAFISICA_HPP
