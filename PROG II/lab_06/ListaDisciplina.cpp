//
// Created by vinic on 23/09/2022.
//

#include "iostream"

#include "ListaDisciplina.hpp"

using namespace std;

int ListaDisciplina::length = 0;

ListaDisciplina::ListaDisciplina() {
    this->primeiro = nullptr;
}

void ListaDisciplina::inserirDisciplina(Disciplina* disciplina) {

    if (length == 0) {
        primeiro = disciplina;
        length++;
        return;
    } else {
        Disciplina *elemento = primeiro;

        while (elemento) {

            if (!elemento->getProx()) {
                elemento->setProx(disciplina);
                length++;
                return;
            }

            elemento = elemento->getProx();
        }
    }

}

void ListaDisciplina::imprimirDisciplinas() {
    Disciplina *elemento = primeiro;

    while (elemento) {
        cout << elemento->getNome() << " - " << elemento->getCargaHoraria() << " - "
             << elemento->getProfessor().getNome() << endl;

        elemento = elemento->getProx();
    }
}