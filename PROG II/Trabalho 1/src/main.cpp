#include <iostream>
#include <clocale>

#include "Consultorio.hpp"

using namespace std;



void continuar() {
    cout << "Pressione qualquer tecla para continuar...";
    cin.ignore();
}

void mensagemBemVindo() {
    cout << "Seja bem-vindo ao sistema do nosso consultório" << endl;
    cout << "Pressione qualquer tecla para continuar...";
    cin.ignore();
}

void mostrarMenu() {
    cout << "[1] Cadastrar um médico\n";
    cout << "[2] Cadastrar um paciente\n";
    cout << "[3] Cadastrar uma consulta\n";
    cout << "[4] Imprimir dados do médico\n";
    cout << "[5] Imprimir consultas\n";
    cout << "[6] Imprimir dados do paciente\n";
    cout << "[7] Imprimir dados de uma consulta\n";
    cout << "[8] Remover um médico\n";
    cout << "[9] Remover um paciente\n";
    cout << "[10] Remover uma consulta\n";
    cout << "[11] Sair\n";
}

void cadastrarMedico(Consultorio *consultorio) {
    int crm;
    string especialidade, nome, endereco, cpf, telefone;
    char sexo;

    cout << "Digite o CRM: ";
    cin >> crm;
    cin.ignore();

    cout << "Digite a especialidade: ";
    getline(cin, especialidade);

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite o endereço: ";
    getline(cin, endereco);

    cout << "Digite o CPF: ";
    getline(cin, cpf);

    cout << "Digite o telefone: ";
    getline(cin, telefone);

    cout << "Digite o sexo (M ou F): ";
    cin >> sexo;
    cin.ignore();

    bool response = consultorio->cadastrarMedico(crm, especialidade, nome, sexo, endereco, cpf, telefone);

    if (response)
        cout << "Médico cadastrado com sucesso! \n";
}

void cadastrarPaciente(Consultorio *consultorio) {

    string nome, endereco, cpf, telefone, relato, medicacao;
    char sexo;

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite o endereço: ";
    getline(cin, endereco);

    cout << "Digite o CPF: ";
    getline(cin, cpf);

    cout << "Digite o telefone: ";
    getline(cin, telefone);

    cout << "Digite o sexo (M ou F): ";
    cin >> sexo;
    cin.ignore();

    cout << "Digite o relato: ";
    getline(cin, relato);

    cout << "Digite a medicacao: ";
    getline(cin, medicacao);

    bool response = consultorio->cadastrarPaciente(nome, sexo, endereco, cpf, telefone, relato, medicacao);

    if (response)
        cout << "Paciente cadastrado com sucesso! \n";
}

void imprimirDadosDoMedico(Consultorio *consultorio) {
    string cpf;

    cout << "Digite o cpf do médico: ";
    getline(cin, cpf);

    consultorio->imprimirDadosDoMedico(cpf);
}

void cadastrarConsulta(Consultorio *consultorio) {

    string cpfPaciente;
    int crm;

    cout << "Digite o CPF do paciente: ";
    getline(cin, cpfPaciente);

    consultorio->imprimirMedicos();
    cout << "Digite o CRM do médico escolhido: ";
    cin >> crm;
    cin.ignore();

    bool response = consultorio->cadastrarConsulta(cpfPaciente, crm);

    if (response)
        cout << "Consulta cadastrada com sucesso! \n";
}

void imprimirConsultas(Consultorio *consultorio) {
    consultorio->imprimirConsultas();
}

void imprimirDadosDoPaciente(Consultorio *consultorio) {
    string cpf;

    cout << "Digite o CPF do paciente: ";
    getline(cin, cpf);

    consultorio->imprimirDadosDoPaciente(cpf);
}

void imprimirDadosDaConsulta(Consultorio *consultorio) {

    string cpfPaciente, cpfMedico;

    cout << "Digite o CPF do paciente: ";
    getline(cin, cpfPaciente);

    cout << "Digite o CPF do médico: ";
    getline(cin, cpfMedico);

    consultorio->imprimirDadosDaConsulta(cpfPaciente, cpfMedico);
}

void removerMedico(Consultorio *consultorio) {
    string cpf;

    cout << "Digite o CPF do médico que deseja remover: ";
    getline(cin, cpf);

    bool response = consultorio->removerMedico(cpf);

    if (response)
        cout << "Médico removido com sucesso! \n";
}

void removerPaciente(Consultorio *consultorio) {
    string cpf;

    cout << "Digite o CPF do paciente que deseja remover: ";
    getline(cin, cpf);

    bool response = consultorio->removerPaciente(cpf);

    if (response)
        cout << "Paciente removido com sucesso! \n";
}

void removerConsulta(Consultorio *consultorio) {
    int consulta;

    consultorio->imprimirConsultas();

    if (consultorio->numeroDeConsultas() == 0)
        return;

    cout << "Digite o número da consulta que deseja remover:";
    cin >> consulta;

    consultorio->removerConsulta(consulta);
    cout << "Consulta removida com sucesso! \n";
}

Consultorio *inicializarConsultorio() {
    string nome, endereco, telefone;

    cout << "Digite o nome do consultório: ";
    getline(cin, nome);

    cout << "Digite o endereco do consultorio: ";
    getline(cin, endereco);

    cout << "Digite o telefone do consultorio: ";
    getline(cin, telefone);

    Consultorio *novoConsultorio = new Consultorio(nome, endereco, telefone);
    return novoConsultorio;
}

int main() {

    setlocale(LC_ALL, "");
    mensagemBemVindo();

    Consultorio *consultorio = inicializarConsultorio();
    int opcao;

    do {
        mostrarMenu();
        cout << "Digite uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cadastrarMedico(consultorio);
                break;
            case 2:
                cadastrarPaciente(consultorio);
                break;
            case 3:
                cadastrarConsulta(consultorio);
                break;
            case 4:
                imprimirDadosDoMedico(consultorio);
                break;
            case 5:
                imprimirConsultas(consultorio);
                break;
            case 6:
                imprimirDadosDoPaciente(consultorio);
                break;
            case 7:
                imprimirDadosDaConsulta(consultorio);
                break;
            case 8:
                removerMedico(consultorio);
                break;
            case 9:
                removerPaciente(consultorio);
                break;
            case 10:
                removerConsulta(consultorio);
                break;
            case 11:
                cout << "Até mais!\n";
                break;

            default:
                cout << "Opção inválida!\n";
                break;
        }

        if (opcao != 11)
            continuar();

    } while (opcao != 11);

    return 0;
}
