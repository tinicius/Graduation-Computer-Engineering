//
// Created by vinic on 23/09/2022.
//

#include "iostream"

#include "ListaAluno.hpp"

using namespace std;

int ListaAluno::length = 0;

ListaAluno::ListaAluno() {
    this->primeiro = nullptr;
}

void ListaAluno::inserirAluno(Aluno* aluno) {

    if (length == 0) {
        primeiro = aluno;
        length++;
        return;
    } else {
        Aluno *elemento = primeiro;

        while (elemento) {

            if (!elemento->getProx()) {
                elemento->setProx(aluno);
                length++;
                return;
            }

            elemento = elemento->getProx();
        }
    }

}

void ListaAluno::imprimirAlunos() {
    Aluno *elemento = primeiro;

    while (elemento) {
        cout << elemento->getNome() << " - " << elemento->getCpf() << " - "
             << elemento->getEndereco() << " - " << elemento->getMatricula()
             << endl;

        elemento = elemento->getProx();
    }
}