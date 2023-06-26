#ifndef LPCI_ITEM_H
#define LPCI_ITEM_H

#include "iostream"

using namespace std;

class Item {
   private:
    int id;
    string nome;
    float valor;
    int quantidade;

    Item* prox;

   public:
    Item(int id, string nome, float valor, int quantidade);

    void mostrarDados();

    int getId();

    void setNome(string nome);
    string getNome();

    void setValor(float valor);
    float getValor();

    void setQuantidade(int quantidade);
    int getQuantidade();

    void setProx(Item* prox);
    Item* getProx();
};

#endif  // LPCI_ITEM_H
