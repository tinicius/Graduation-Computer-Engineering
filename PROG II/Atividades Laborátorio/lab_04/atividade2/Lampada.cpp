#include "Lampada.hpp"

#include <iostream>

int Lampada::totalLampadas = 0;

Lampada::Lampada(string modelo, float tensao) {
    totalLampadas++;

    this->modelo = modelo;
    this->tensao = tensao;
    this->estado = false;
}

void Lampada::acender() { this->estado = true; }
void Lampada::apagar() { this->estado = false; }
void Lampada::printEstado() {
    if (this->estado) {
        cout << "A lampada esta acessa" << endl;
    } else {
        cout << "A lampada esta apagada" << endl;
    }
}

void Lampada::setModelo(string modelo) { this->modelo = modelo; }
string Lampada::getModelo() { return this->modelo; }

void Lampada::setTensao(float tensao) { this->tensao = tensao; }
float Lampada::getTensao() { return this->tensao; }

void Lampada::setEstado(bool estado) { this->estado = estado; }
bool Lampada::getEstado() { return this->estado; }
