#include "Carrinho.hpp"

#include <iostream>

Carrinho::Carrinho() { this->primeiro = NULL; };

int Carrinho::length = 0;

void Carrinho::inserirProduto(Item* item) {
    if (!primeiro) {
        this->primeiro = item;
        this->length = this->length + 1;

        return;
    } else {
        item->setProx(this->primeiro);
        this->primeiro = item;

        this->length = this->length + 1;
        return;
    }
};

void Carrinho::consultarProduto(int id) {
    if (this->length == 0) {
        cout << "O carrinho está vazio! \n";
    } else {
        Item* elemento = primeiro;

        while (elemento) {
            if (elemento->getId() == id) {
                elemento->mostrarDados();
                return;
            }

            elemento = elemento->getProx();
        }

        cout << "ID invalido! \n";
    }
};

void Carrinho::consultarTodos() {
    if (this->length == 0) {
        cout << "O carrinho está vazio! \n";
    } else {
        Item* elemento = primeiro;

        while (elemento) {
            elemento->mostrarDados();
            elemento = elemento->getProx();
        }
    }
};

void Carrinho::removerProduto(int id) {
    if (this->length == 0) {
        cout << "O carrinho está vazio! \n";
    } else {
        if (this->primeiro->getId() == id) {
            Item* atual = this->primeiro;

            this->primeiro = atual->getProx();
            delete atual;
            this->length = this->length - 1;
            return;
        }

        Item* elemento = primeiro;
        Item* anterior = NULL;

        while (elemento) {
            if (elemento->getId() == id) {
                anterior->setProx(elemento->getProx());
                delete elemento;
                this->length = this->length - 1;
                return;
            }

            anterior = elemento;
            elemento = elemento->getProx();
        }

        cout << "ID invalido! \n";
    }
};

void Carrinho::editarProduto(int id) {
    if (this->length == 0) {
        cout << "O carrinho está vazio! \n";
    } else {
        Item* elemento = primeiro;

        while (elemento) {
            if (elemento->getId() == id) {
                int quantidade;
                string nome;
                float valor;

                cout << "Digite o nome do produto (" << elemento->getNome()
                     << "): ";
                cin.ignore();
                getline(cin, nome);

                cout << "Digite o valor do produto (" << elemento->getValor()
                     << "): ";
                cin >> valor;

                cout << "Digite a quantidade do produto ("
                     << elemento->getQuantidade() << "): ";
                cin >> quantidade;

                elemento->setNome(nome);
                elemento->setValor(valor);
                elemento->setQuantidade(quantidade);

                return;
            }

            elemento = elemento->getProx();
        }

        cout << "ID invalido! \n";
    }
};

float Carrinho::valorTotal() {
    float novoTotal = 0.0;

    Item* elemento = this->primeiro;

    while (elemento) {
        novoTotal += elemento->getValor() * elemento->getQuantidade();
        elemento = elemento->getProx();
    }

    this->total = novoTotal;

    return this->total;
};