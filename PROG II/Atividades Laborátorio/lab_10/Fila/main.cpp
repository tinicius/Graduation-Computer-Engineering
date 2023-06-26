//
// Created by vinic on 07/11/2022.
//

#include <iostream>

using namespace std;

#include "Fila.hpp"

void mostrarMenu() {
    cout << "[0] - Sair\n";
    cout << "[1] - Inserir Pessoa\n";
    cout << "[2] - Inserir Pessoa prioritária\n";
    cout << "[3] - Remover\n";
    cout << "[4] - Imprimir\n";
    cout << "[5] - Verificar fila vazia\n";
}

void inserirPessoa(Fila *pessoas) {
    string nome, cpf;

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite o CPF: ";
    getline(cin, cpf);

    Pessoa *novaPessoa = new Pessoa(nome, cpf);
    pessoas->inserir(novaPessoa);

};

void inserirPessoaPrioritaria(Fila *pessoas) {
    string nome, cpf;

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite o CPF: ";
    getline(cin, cpf);

    Pessoa *novaPessoa = new Pessoa(nome, cpf);
    pessoas->inserirP(novaPessoa);

};

void removerPessoa(Fila *pessoas) {
    pessoas->remover();
}

void mostrarTopo(Fila *pessoas) {
    pessoas->imprimir();
};

void verificarFilaVazia(Fila *pessoas) {

    if (pessoas->isVazia())
        cout << "Fila vazia!\n";
    else
        cout << "Fila com pessoas!\n";
}

int main() {

    int op;
    Fila pessoas;

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
                inserirPessoa(&pessoas);
                break;

            case 2:
                inserirPessoaPrioritaria(&pessoas);
                break;

            case 3:
                removerPessoa(&pessoas);
                break;

            case 4:
                mostrarTopo(&pessoas);
                break;

            case 5:
                verificarFilaVazia(&pessoas);
                break;

            default:
                cout << "Opção inválida!\n";
                break;
        }


    } while (op != 0);


}
