#ifndef LPCI_CARRINHO_H
#define LPCI_CARRINHO_H

#include "Item.hpp"

using namespace std;

class Carrinho {
   private:
    float total;
    Item* primeiro;

   public:
    Carrinho();

    static int length;

    void inserirProduto(Item* item);
    void consultarProduto(int id);
    void consultarTodos();
    void removerProduto(int id);
    void editarProduto(int id);

    float valorTotal();
};

#endif  // LPCI_CARRINHO_H
