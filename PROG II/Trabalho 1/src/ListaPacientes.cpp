//
// Created by vinic on 28/09/2022.
//

#include "ListaPacientes.hpp"
#include "iostream"

using namespace std;

int ListaPacientes::length = 0;

ListaPacientes::ListaPacientes() {
    primeiro = nullptr;
}

void ListaPacientes::inserirPaciente(Paciente *paciente) {

    paciente->setProx(primeiro);
    primeiro = paciente;
    length++;

}

void ListaPacientes::removerPaciente(string cpfPaciente) {

    if (length == 0) {
        return;
    }

    if (primeiro->getCpf() == cpfPaciente) {

        Paciente *aux = primeiro;
        primeiro = primeiro->getProx();

        delete aux;
        length--;
        return;
    }

    Paciente *aux = primeiro;
    Paciente *elemento = primeiro->getProx();

    while (elemento) {

        if (elemento->getCpf() == cpfPaciente) {
            aux->setProx(elemento->getProx());
            delete elemento;
            length--;
            return;
        }

        aux = elemento;
        elemento = elemento->getProx();
    }

}

void ListaPacientes::imprimirPacientes() {

    Paciente *elemento = primeiro;

    while (elemento) {
        elemento->imprimir();
        elemento = elemento->getProx();
    }

}

int ListaPacientes::numeroPacientes() {
    return length;
}

Paciente* ListaPacientes::buscarPaciente(string cpf) {

    if (length == 0) {
        return nullptr;
    }

    Paciente *aux = primeiro;

    while (aux) {

        if (aux->getCpf() == cpf) {
            return aux;
        }

        aux = aux->getProx();
    }

    return nullptr;

}
