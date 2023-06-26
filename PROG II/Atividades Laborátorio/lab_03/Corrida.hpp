#ifndef __CORRIDA_HPP
#define __CORRIDA_HPP

#include <string>
using namespace std;

class Corrida {

    private:
        string modelo;
        double motor;
        string fabricante;

        string motorista;

        double inicioKm;
        double finalKm;

    public:
        void setModelo(string modelo);
        string getModelo();

        void setMotor(double motor);
        double getMotor();

        void setFabricante(string fabricante);
        string getFabricante();

        void setMotorista(string motorista);
        string getMotorista();

        void setInicioKm(double inicioKm);
        double getInicioKm();

        void setFinalKm(double finalKm);
        double getFinalKm();

        double calcularCorrida(double valorPorKm);
};

#endif 