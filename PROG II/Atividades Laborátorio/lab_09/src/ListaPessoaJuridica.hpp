//
// Created by vinic on 31/10/2022.
//

#ifndef LAB_08_LISTAPESSOAJURIDICA_HPP
#define LAB_08_LISTAPESSOAJURIDICA_HPP

#include "PessoaJuridica.hpp"

class ListaPessoaJuridica {
private:
    int length;
    PessoaJuridica *primeiro;
public:
    ListaPessoaJuridica();

    int getLength();

    void inserir(PessoaJuridica *pessoaFisica);

    void remover(string cnpj);

    void buscar(string cnpj);

    void imprimir();

};


#endif //LAB_08_LISTAPESSOAJURIDICA_HPP
