//
// Created by vinic on 28/09/2022.
//
#include "iostream"

using namespace std;

#include "Data.hpp"

int Data::getDia() {
    return dia;
}

void Data::setDia(int dia) {
    Data::dia = dia;
}

int Data::getMes() {
    return mes;
}

void Data::setMes(int mes) {
    Data::mes = mes;
}

int Data::getAno() {
    return ano;
}

void Data::setAno(int ano) {
    Data::ano = ano;
}

int Data::getHoras() {
    return horas;
}

void Data::setHoras(int horas) {
    Data::horas = horas;
}

int Data::getMinutos() {
    return minutos;
}

void Data::setMinutos(int minutos) {
    Data::minutos = minutos;
}

Data::Data() {
    dia = 0;
    mes = 0;
    ano = 0;
    horas = 0;
    minutos = 0;
}

Data::Data(int dia, int mes, int ano, int horas, int minutos) {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->horas = horas;
    this->minutos = minutos;
}

bool Data::dataVazia() {

    if (dia == 0 || mes == 0 || ano == 0) {
        return true;
    }

    return false;
}

void Data::imprimirData() {
    cout << dia << '/' << mes << '/' << ano << ' ' << horas << ":" << minutos << endl;
}
