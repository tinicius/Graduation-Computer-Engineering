#include "Item.hpp"

using namespace std;

Item::Item(int id, string nome, float valor, int quantidade) {
    this->prox = NULL;

    this->id = id;
    this->nome = nome;
    this->valor = valor;
    this->quantidade = quantidade;
}

void Item::mostrarDados() {
    cout << this->id << " " << this->nome << " " << this->valor << " "
         << this->quantidade << endl;
};

int Item::getId() { return this->id; };

void Item::setNome(string nome) { this->nome = nome; };
string Item::getNome() { return this->nome; };

void Item::setValor(float valor) { this->valor = valor; };
float Item::getValor() { return this->valor; };

void Item::setQuantidade(int quantidade) { this->quantidade = quantidade; };
int Item::getQuantidade() { return this->quantidade; };

void Item::setProx(Item* prox) { this->prox = prox; };
Item* Item::getProx() { return this->prox; };