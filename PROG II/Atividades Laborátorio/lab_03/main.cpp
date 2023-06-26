#include <iostream>

#include "Corrida.hpp"

using namespace std;

int main() {

    Corrida corrida;
    string modelo, fabricante, motorista;
    double motor, inicioKm, finalKm;

    double valorPorKm;

    cout << "Digite o modelo: ";
    getline(cin, modelo);

    cout << "Digite o tipo de motor: ";
    cin >> motor;
    cin.ignore();

    cout << "Digite o fabricante: ";
    getline(cin, fabricante);

    cout << "Digite o motorista: ";
    getline(cin, motorista);

    cout << "Digite o quilometro inicial: ";
    cin >> inicioKm;

    cout << "Digite o quilometro final: ";
    cin >> finalKm;

    corrida.setModelo(modelo);
    corrida.setMotor(motor);
    corrida.setFabricante(fabricante);
    corrida.setMotorista(motorista);
    corrida.setInicioKm(inicioKm);
    corrida.setFinalKm(finalKm);

    cout << "Digite o valor por Km: ";
    cin >> valorPorKm;

    double valorDaCorrida = corrida.calcularCorrida(valorPorKm);

    cout << "Preço final: R$ " << valorDaCorrida << endl;

}