//
// Created by vinic on 28/09/2022.
//
#include "iostream"
#include "ListaMedicos.hpp"

using namespace std;

int ListaMedicos::length = 0;

ListaMedicos::ListaMedicos() {
    primeiro = nullptr;
}

void ListaMedicos::inserirMedico(Medico *medico) {

    medico->setProx(primeiro);
    primeiro = medico;
    length++;

}

void ListaMedicos::removerMedico(string cpfPaciente) {

    if (length == 0) {
        cout << "Lista vazia!" << endl;
        return;
    }

    if (primeiro->getCpf() == cpfPaciente) {

        Medico *aux = primeiro;
        primeiro = primeiro->getProx();

        delete aux;
        length--;
        return;
    }

    Medico *aux = primeiro;
    Medico *elemento = primeiro->getProx();

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

void ListaMedicos::imprimirMedicos() {

    Medico *elemento = primeiro;

    while (elemento) {
        printf("Doutor %s, %s, CRM: %d\n", elemento->getNome().c_str(), elemento->getEspecialidade().c_str(), elemento->getCrm());
        elemento = elemento->getProx();
    }

}

int ListaMedicos::numeroMedicos() {
    return length;
}

Medico *ListaMedicos::buscarMedico(string cpf) {
    if (length == 0) {
        return nullptr;
    }

    Medico *aux = primeiro;

    while (aux) {

        if (aux->getCpf() == cpf) {
            return aux;
        }

        aux = aux->getProx();
    }

    return nullptr;
}

Medico* ListaMedicos::buscarMedico(int crm) {
    if (length == 0) {
        return nullptr;
    }

    Medico *aux = primeiro;

    while (aux) {

        if (aux->getCrm() == crm) {
            return aux;
        }

        aux = aux->getProx();
    }

    return nullptr;
}
