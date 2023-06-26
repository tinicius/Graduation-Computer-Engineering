//
// Created by vinic on 06/10/2022.
//
#include "iostream"
#include "Consultorio.hpp"

string Consultorio::getNome() {
    return nome;
}

void Consultorio::setNome(string nome) {
    Consultorio::nome = nome;
}

string Consultorio::getEndereco() {
    return endereco;
}

void Consultorio::setEndereco(string endereco) {
    Consultorio::endereco = endereco;
}

string Consultorio::getTelefone() {
    return telefone;
}

void Consultorio::setTelefone(string telefone) {
    Consultorio::telefone = telefone;
}

ListaPacientes Consultorio::getPacientes() {
    return pacientes;
}

void Consultorio::setPacientes(ListaPacientes pacientes) {
    Consultorio::pacientes = pacientes;
}

ListaMedicos Consultorio::getMedicos() {
    return medicos;
}

void Consultorio::setMedicos(ListaMedicos medicos) {
    Consultorio::medicos = medicos;
}

ListaConsultas Consultorio::getConsultas() {
    return consultas;
}

void Consultorio::setConsultas(ListaConsultas consultas) {
    Consultorio::consultas = consultas;
}

Consultorio::Consultorio() {
    this->nome = "";
    this->endereco = "";
    this->telefone = "";
}

Consultorio::Consultorio(string nome, string endereco, string telefone) {
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
}

bool
Consultorio::cadastrarPaciente(string nome, char sexo, string endereco, string cpf, string telefone, string relato, string medicacao) {

    Paciente *paciente = pacientes.buscarPaciente(cpf);

    if (paciente != nullptr) {
        cout << "CPF já utilizado! \n";
        return false;
    }

    Paciente *novoPaciente = new Paciente(relato, medicacao, nome, sexo, endereco, cpf, telefone);

    pacientes.inserirPaciente(novoPaciente);
    return true;
}

bool Consultorio::removerPaciente(string cpf) {

    Paciente *paciente = pacientes.buscarPaciente(cpf);

    if (paciente == nullptr) {
        cout << "Paciente não cadastrado! \n";
        return false;
    }

    consultas.removerTodasConsultasMedicoOuPaciente(cpf);
    pacientes.removerPaciente(cpf);
    return true;
}

bool Consultorio::cadastrarMedico(int crm, string especialidade, string nome, char sexo, string endereco, string cpf,
                                  string telefone) {

    Medico *medico = medicos.buscarMedico(cpf);

    if (medico != nullptr) {
        cout << "CPF já utilizado! \n";
        return false;
    }

    medico = medicos.buscarMedico(crm);

    if (medico != nullptr) {
        cout << "CRM já utilizado! \n";
        return false;
    }

    Paciente *paciente = pacientes.buscarPaciente(cpf);

    if (paciente != nullptr) {
        cout << "CPF já utilizado! \n";
        return false;
    }

    Medico *novoMedico = new Medico(crm, especialidade, nome, sexo, endereco, cpf, telefone);
    medicos.inserirMedico(novoMedico);
    return true;
}

bool Consultorio::cadastrarConsulta(string cpfPaciente, int crm) {

    Paciente *paciente = pacientes.buscarPaciente(cpfPaciente);

    if (paciente == nullptr) {
        cout << "Paciente não cadastrado!\n";
        return false;
    }

    Medico *medico = medicos.buscarMedico(crm);

    if (medico == nullptr) {
        cout << "Medico não cadastrado!\n";
        return false;
    }

    Data ultimaConsulta = consultas.buscarUltimaConsulta(paciente->getCpf());

    if (!ultimaConsulta.dataVazia())
        paciente->setUltimaConsulta(ultimaConsulta);

    Data data = consultas.buscarProximaData(medico->getCpf());
    int id = consultas.buscarProximoId();

    Consulta *novaConsuta = new Consulta(*paciente, *medico, data, id);
    consultas.inserirConsulta(novaConsuta);
    return true;
}

void Consultorio::removerConsulta(int consulta) {
    consultas.removerConsulta(consulta);
}

void Consultorio::imprimirPacientes() {
    pacientes.imprimirPacientes();
}

void Consultorio::imprimirConsultas() {
    consultas.imprimirConsultas();
}

void Consultorio::imprimirConsultasPorMedico(string cpf) {
    consultas.imprimirConsultasPorMedicoOuPaciente(cpf);
}

void Consultorio::imprimirMedicos() {
    medicos.imprimirMedicos();
}

void Consultorio::imprimirDadosDoMedico(string cpf) {

    Medico *medico = medicos.buscarMedico(cpf);

    if (medico == nullptr) {
        cout << "Médico não cadastrado! \n";
        return;
    }

    medico->imprimir();

}

void Consultorio::imprimirDadosDoPaciente(string cpf) {
    Paciente *paciente = pacientes.buscarPaciente(cpf);

    if (paciente == nullptr) {
        cout << "Paciente não cadastrado! \n";
        return;
    }

    paciente->imprimir();
}

bool Consultorio::removerMedico(string cpf) {

    Medico *medico = medicos.buscarMedico(cpf);

    if (medico == nullptr) {
        cout << "Médico não cadastrado! \n";
        return false;
    }

    consultas.removerTodasConsultasMedicoOuPaciente(cpf);
    medicos.removerMedico(cpf);

    return true;
}

void Consultorio::imprimirDadosDaConsulta(string cpfPaciente, string cpfMedico) {
    consultas.imprimirConsultasPorMedicoOuPaciente(cpfPaciente);
    consultas.imprimirConsultasPorMedicoOuPaciente(cpfMedico);
}

int Consultorio::numeroDeConsultas() {
    return consultas.numeroConsultas();
}
