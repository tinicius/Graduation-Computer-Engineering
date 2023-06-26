//
// Created by vinic on 17/10/2022.
//

#include "string"
#include "iostream"

using namespace std;

#include "Contas.hpp"

void mostrarMenu() {
    cout << "[0] Sair" << endl;
    cout << "[1] Cadastrar conta" << endl;
    cout << "[2] Realizar deposito" << endl;
    cout << "[3] Realizar retirada" << endl;
    cout << "[4] Imprimir Extrato" << endl;
}

void cadastrarConta(Contas *contas) {

    string nome;
    string conta;

    cout << "Digite seu nome completo: ";
    getline(cin, nome);

    cout << "[1] Corrente \n";
    cout << "[2] Corrente com limite \n";
    cout << "[3] Poupança \n";

    cout << "Selecione o tipo de conta: ";
    cin >> conta;

    contas->inserir(nome, conta);

}

bool checkValidInput() {
    if (cin.fail()) {
        cout << "Entrada inváida! \n";
        cin.clear();
        cin.ignore(80, '\n');
        return false;
    }
    return true;
}

void realizarDeposito(Contas *contas) {

    string conta;
    double valor;

    cout << "Digite o número da conta: ";
    cin >> conta;

    cout << "Digite o valor do deposito: ";
    cin >> valor;

    if (checkValidInput()) {
        contas->deposito(conta, valor);
    }

}

void realizarRetirada(Contas *contas) {

    string conta;
    double valor;

    cout << "Digite o número da conta: ";
    cin >> conta;

    cout << "Digite o valor do retirada: ";
    cin >> valor;

    if (checkValidInput()) {
        contas->retirada(conta, valor);
    }
}

void imprimirExtrato(Contas *contas) {

    string conta;

    cout << "Digite o número da conta: ";
    cin >> conta;

    contas->imprimir(conta);

}

int main() {

    int opcao;
    Contas contas;

    do {

        mostrarMenu();
        cout << "Digite uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {

            case 0:
                cout << "Até mais! \n";
                break;

            case 1:
                cadastrarConta(&contas);
                break;

            case 2:
                realizarDeposito(&contas);
                break;

            case 3:
                realizarRetirada(&contas);
                break;

            case 4:
                imprimirExtrato(&contas);
                break;
            default:
                cout << "Opção inválida";
        }

    } while (opcao != 0);

    return 0;
}