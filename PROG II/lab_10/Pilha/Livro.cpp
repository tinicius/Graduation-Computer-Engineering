//
// Created by vinic on 07/11/2022.
//

#include "Livro.hpp"

string Livro::getNome() {
    return nome;
}

void Livro::setNome(string nome) {
    Livro::nome = nome;
}

string Livro::getIsbn() {
    return isbn;
}

void Livro::setIsbn(string isbn) {
    Livro::isbn = isbn;
}

Livro *Livro::getProx() {
    return prox;
}

void Livro::setProx(Livro *prox) {
    Livro::prox = prox;
}

Livro::Livro() {
    this->nome = "";
    this->isbn = "";
    this->prox = nullptr;
}

Livro::Livro(string nome, string isbn) {
    this->nome = nome;
    this->isbn = isbn;
    this->prox = nullptr;
}

void Livro::imprimir() {
    cout << "Livro: " << this->nome << endl;
    cout << "ISBN: " << this->isbn << endl;
    cout << endl;
}
