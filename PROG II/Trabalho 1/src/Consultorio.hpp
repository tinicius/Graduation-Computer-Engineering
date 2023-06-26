//
// Created by vinic on 06/10/2022.
//

#ifndef TRABALHO_2_CONSULTORIO_HPP
#define TRABALHO_2_CONSULTORIO_HPP

#include <string>

using namespace std;

#include "ListaPacientes.hpp"
#include "ListaMedicos.hpp"
#include "ListaConsultas.hpp"

#include "Data.hpp"

class Consultorio
{
private:
    string nome;
    string endereco;
    string telefone;
    ListaPacientes pacientes;
    ListaMedicos medicos;
    ListaConsultas consultas;

public:
    Consultorio();

    Consultorio(string nome, string endereco, string telefone);

    int numeroDeConsultas();

    bool cadastrarPaciente(string nome, char sexo, string endereco, string cpf, string telefone, string relato, string medicacao);

    bool removerPaciente(string cpf);

    bool cadastrarMedico(int crm, string especialidade, string nome, char sexo, string endereco, string cpf, string telefone);

    bool removerMedico(string cpf);

    void imprimirDadosDoMedico(string cpf);

    void imprimirDadosDoPaciente(string cpf);

    bool cadastrarConsulta(string cpfPaciente, int crm);

    void removerConsulta(int consulta);

    void imprimirConsultas();
    void imprimirDadosDaConsulta(string cpfPaciente, string cpfMedico);
    void imprimirMedicos();
    void imprimirConsultasPorMedico(string cpf);
    void imprimirPacientes();

    string getNome();

    void setNome(string nome);

    string getEndereco();

    void setEndereco(string endereco);

    string getTelefone();

    void setTelefone(string telefone);

    ListaPacientes getPacientes();

    void setPacientes(ListaPacientes pacientes);

    ListaMedicos getMedicos();

    void setMedicos(ListaMedicos medicos);

    ListaConsultas getConsultas();

    void setConsultas(ListaConsultas consultas);
};

#endif // TRABALHO_2_CONSULTORIO_HPP
