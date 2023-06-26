//
// Created by vinic on 23/09/2022.
//

#include "iostream"

#include "ListaProfessor.hpp"

using namespace std;

int ListaProfessor::length = 0;

ListaProfessor::ListaProfessor() {
    this->primeiro = nullptr;
}

void ListaProfessor::inserirProfessor(Professor* professor) {

    if (length == 0) {
        primeiro = professor;
        length++;
        return;
    } else {
        Professor *elemento = primeiro;

        while (elemento) {

            if (!elemento->getProx()) {
                elemento->setProx(professor);
                length++;
                return;
            }

            elemento = elemento->getProx();
        }
    }

}

void ListaProfessor::imprimirProfessores() {
    Professor *elemento = primeiro;

    while (elemento) {
        cout << elemento->getNome() << " - " << elemento->getTitulacao()
             << " - " << elemento->getCpf() << " - " << elemento->getEndereco()
             << endl;

        elemento = elemento->getProx();
    }
}

Professor ListaProfessor::buscarProfessor(string cpf) {

    Professor professor;

    Professor* elemento = primeiro;

    while (elemento) {

        if (cpf == elemento->getCpf()) {
            professor = *elemento;
        }

        elemento = elemento->getProx();
    }

    return professor;

}