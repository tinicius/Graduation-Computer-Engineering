//
// Created by vinic on 07/11/2022.
//

#include <iostream>
#include "Pilha.hpp"

void mostrarMenu() {
    cout << "[0] - Sair\n";
    cout << "[1] - Inserir\n";
    cout << "[2] - Remover\n";
    cout << "[3] - Mostrar topo\n";
    cout << "[4] - Verificar pilha vazia\n";
}

void inserirLivro(Pilha *livros) {
    string nome, isbn;

    cout << "Digite o nome do livro: ";
    getline(cin, nome);

    cout << "Digite o ISBN: ";
    getline(cin, isbn);

    Livro *novoLivro = new Livro(nome, isbn);
    livros->inserir(novoLivro);

};

void removerLivro(Pilha *livros) {
    livros->remover();
}

void mostrarTopo(Pilha *livros) {
    livros->mostrarTopo();
};

void verificarPilhaVazia(Pilha *livros) {

    if (livros->isVazia())
        cout << "Pilha vazia!\n";
    else
        cout << "Pilha com livros!\n";
}

int main() {

    int op;
    Pilha livros;

    do {
        mostrarMenu();
        cout << "Digite uma opção: ";
        cin >> op;
        cin.ignore();

        switch (op) {
            case 0:
                cout << "Até mais!\n";
                break;

            case 1:
                inserirLivro(&livros);
                break;

            case 2:
                removerLivro(&livros);
                break;

            case 3:
                mostrarTopo(&livros);
                break;

            case 4:
                verificarPilhaVazia(&livros);
                break;

            default:
                cout << "Opção inválida!\n";
                break;
        }


    } while (op != 0);


}
