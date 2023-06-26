#include <iostream>

#include "Carrinho.hpp"
#include "Item.hpp"

using namespace std;

void mostrarMenu() {
    cout << "[0] Sair \n";
    cout << "[1] Inserir um produto \n";
    cout << "[2] Consultar um produto \n";
    cout << "[3] Consultar todos produtos \n";
    cout << "[4] Retirar um produto \n";
    cout << "[5] Editar um produto \n";
    cout << "[6] Consultar valor total \n";
}

Item* lerNovoProduto() {
    int id, quantidade;
    string nome;
    float valor;

    cout << "Digite o ID do produto: ";
    cin >> id;

    cout << "Digite o nome do produto: ";
    cin.ignore();
    getline(cin, nome);

    cout << "Digite o valor do produto: ";
    cin >> valor;

    cout << "Digite a quantidade do produto: ";
    cin >> quantidade;

    Item* novoItem = new Item(id, nome, valor, quantidade);
    return novoItem;
}

int lerIdProduto() {
    int id;

    cout << "Digite o ID do produto: ";
    cin >> id;

    return id;
}

int main() {
    Carrinho carrinho = Carrinho();

    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Até mais! \n";
                break;

            case 1: {
                Item* novoProduto = lerNovoProduto();
                carrinho.inserirProduto(novoProduto);
            } break;

            case 2: {
                int produtoId = lerIdProduto();
                carrinho.consultarProduto(produtoId);
            } break;

            case 3:
                carrinho.consultarTodos();
                break;

            case 4: {
                int produtoId = lerIdProduto();
                carrinho.removerProduto(produtoId);
            } break;

            case 5: {
                int produtoId = lerIdProduto();
                carrinho.editarProduto(produtoId);
            } break;

            case 6: {
                cout << "Valot Total: " << carrinho.valorTotal() << endl;
                break;
            }

            default:
                cout << "Default";
                break;
        }

    } while (opcao != 0);
}