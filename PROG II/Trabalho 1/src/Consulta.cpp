//
// Created by vinic on 28/09/2022.
//

#include "Consulta.hpp"
#include "iostream"

using namespace std;

Paciente Consulta::getPaciente() {
    return paciente;
}

void Consulta::setPaciente(Paciente paciente) {
    Consulta::paciente = paciente;
}

Medico Consulta::getMedico() {
    return medico;
}

void Consulta::setMedico(Medico medico) {
    Consulta::medico = medico;
}

Data Consulta::getData() {
    return data;
}

void Consulta::setData(Data data) {
    Consulta::data = data;
}

Consulta::Consulta() {
    this->id = 0;
    this->prox = nullptr;
}

Consulta::Consulta(Paciente paciente, Medico medico, Data data, int id) {
    this->id = id;
    this->paciente = paciente;
    this->medico = medico;
    this->data = data;
    this->prox = nullptr;
}

void Consulta::imprimir() {
    cout << "[" << id << "] ";

    printf("Paciente: %s, Relato: %s, Medicacão: %s\n", paciente.getNome().c_str(), paciente.getRelato().c_str(),
           paciente.getMedicacao().c_str());

    if (!paciente.getUltimaConsulta().dataVazia()) {
        cout << "Última consulta: ";
        paciente.getUltimaConsulta().imprimirData();
    }

    printf("Doutor: %s, %s, CRM: %d\n", medico.getNome().c_str(), medico.getEspecialidade().c_str(), medico.getCrm());

    cout << "Data: ";
    data.imprimirData();

    cout << endl;
}

Consulta *Consulta::getProx() {
    return prox;
}

void Consulta::setProx(Consulta *consulta) {
    this->prox = consulta;
}

int Consulta::getId() {
    return this->id;
}
