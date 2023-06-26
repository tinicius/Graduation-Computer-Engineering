//
// Created by vinic on 07/11/2022.
//

#ifndef LAB_10_LIVRO_HPP
#define LAB_10_LIVRO_HPP

#include "iostream"

using namespace std;

class Livro {
private:
    string nome;
    string isbn;
    //*prox indica o livro abaixo
    Livro *prox;
public:
    Livro();

    Livro(string nome, string isbn);

    void imprimir();

    string getNome();

    void setNome(string nome);

    string getIsbn();

    void setIsbn(string isbn);

    Livro *getProx();

    void setProx(Livro *prox);

};


#endif //LAB_10_LIVRO_HPP
