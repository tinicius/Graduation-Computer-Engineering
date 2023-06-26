//
// Created by vinic on 17/10/2022.
//

#include "Contas.hpp"
#include "iostream"

using namespace std;

void Contas::inserir(string nome, string tipo) {

    string numeroDaConta = to_string(this->length + 1) + "-" + tipo;

    switch (stoi(tipo)) {
        case 1: {
            Corrente *novaConta = new Corrente(numeroDaConta, nome);
            this->listaCorrente.inserir(novaConta);
        }
            break;
        case 2: {
            double limite;

            cout << "Digite o limite da conta: ";
            cin >> limite;

            CorrenteLimite *novaConta = new CorrenteLimite(numeroDaConta, nome, limite);
            this->listaCorrenteLimite.inserir(novaConta);

        }
            break;
        case 3: {
            int diaAniversario;

            cout << "Digite o dia de aniversário: ";
            cin >> diaAniversario;
            cin.ignore();

            Poupanca *novaConta = new Poupanca(numeroDaConta, nome, diaAniversario);
            this->listaPoupanca.inserir(novaConta);
        }
            break;
    }

    this->length = this->length + 1;
    cout << "Conta criada!\n";
    cout << "Número: " << numeroDaConta << endl;

}

Contas::Contas() {
    this->length = 0;
}

void Contas::imprimir(string conta) {

    int tipo = (int) conta[conta.length() - 1] - 48;

    switch (tipo) {
        case 1:
            this->listaCorrente.imprimir(conta);
            break;
        case 2:
            this->listaCorrenteLimite.imprimir(conta);
            break;
        case 3:
            this->listaPoupanca.imprimir(conta);
            break;
    }
}

void Contas::deposito(string conta, double valor) {

    int tipo = (int) conta[conta.length() - 1] - 48;

    switch (tipo) {
        case 1:
            this->listaCorrente.deposito(conta, valor);
            break;
        case 2:
            this->listaCorrenteLimite.deposito(conta, valor);
            break;
        case 3:
            this->listaPoupanca.deposito(conta, valor);
            break;
    }

}

void Contas::retirada(string conta, double valor) {

    int tipo = (int) conta[conta.length() - 1] - 48;

    switch (tipo) {
        case 1:
            this->listaCorrente.retirada(conta, valor);
            break;
        case 2:
            this->listaCorrenteLimite.retirada(conta, valor);
            break;
        case 3:
            this->listaPoupanca.retirada(conta, valor);
            break;
    }

}
