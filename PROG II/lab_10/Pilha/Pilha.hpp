//
// Created by vinic on 07/11/2022.
//

#ifndef LAB_10_PILHA_HPP
#define LAB_10_PILHA_HPP

#include "Livro.hpp"

class Pilha {
private:
    Livro *ultimo;
    int lenght;
public:
    Pilha();

    void inserir(Livro *livro);

    void remover();

    void mostrarTopo();

    bool isVazia();
};


#endif //LAB_10_PILHA_HPP
