#include <iostream>

#include "Corrida.hpp"

using namespace std;

void Corrida::setModelo(string modelo){
    this->modelo = modelo;
};

string Corrida::getModelo() {
    return this->modelo;
};

void Corrida::setMotor(double motor) {
    this->motor = motor;
};

double Corrida::getMotor() {
    return this->motor;
};

void Corrida::setFabricante(string fabricante) {
    this->fabricante = fabricante;
}

string Corrida::getFabricante() {
    return this->fabricante;
}

void Corrida::setMotorista(string motorista) {
    this->motorista = motorista;
}

string Corrida::getMotorista() {
    return this->motorista;
}

void Corrida::setInicioKm(double inicioKm) {
    this->inicioKm = inicioKm;
}

double Corrida::getInicioKm() {
    return this->inicioKm;
};

void Corrida::setFinalKm(double finalKm) {
    this->finalKm = finalKm;
}

double Corrida::getFinalKm() {
    return this->finalKm;
}

double Corrida::calcularCorrida(double valorPorKm) {
    
    double distanciaPercorrida = this->finalKm - this->inicioKm;
    double valorDaCorrida = distanciaPercorrida * valorPorKm;

    return valorDaCorrida;
}
