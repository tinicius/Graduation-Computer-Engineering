#include <iostream>

#include "Curso.hpp"
#include "string"

using namespace std;

void mostrarMenu() {
    cout << "[0] Sair\n";
    cout << "[1] Cadastrar professor\n";
    cout << "[2] Cadastrar aluno\n";
    cout << "[3] Cadastrar disciplina\n";
    cout << "[4] Mostrar alunos\n";
    cout << "[5] Mostrar professores\n";
    cout << "[6] Mostrar disciplinas\n";
}

void cadastrarProfessor(Curso *curso) {
    string nome, endereco, titulacao, cpf;

    cout << "Digite o nome do professor: ";
    getline(cin, nome);

    cout << "Digite o endereco do professor: ";
    getline(cin, endereco);

    cout << "Digite a titulacao do professor: ";
    getline(cin, titulacao);

    cout << "Digite o cpf do professor: ";
    getline(cin, cpf);

    curso->cadastrarProfessor(nome, endereco, titulacao, cpf);
}

void cadastrarAluno(Curso *curso) {
    string nome, endereco, titulacao, cpf;
    int matricula;

    cout << "Digite o nome do aluno: ";
    getline(cin, nome);

    cout << "Digite o endereco do aluno: ";
    getline(cin, endereco);

    cout << "Digite o cpf do aluno: ";
    getline(cin, cpf);

    cout << "Digite a matricula do aluno: ";
    cin >> matricula;

    curso->cadastrarAluno(nome, endereco, matricula, cpf);
}

void cadastrarDisciplina(Curso *curso) {

    string nome, cpfProfessor;
    int cargaHoraria;

    cout << "Digite o nome da disciplina: ";
    getline(cin, nome);

    cout << "Digite o cpf do professor responsavel: ";
    getline(cin, cpfProfessor);

    cout << "Digite a carga horaria:";
    cin >> cargaHoraria;

    curso->cadastrarDisciplina(nome, cargaHoraria, cpfProfessor);
}

int main() {
    Curso curso;
    int opcao;

    do {
        mostrarMenu();
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 0:
                cout << "Ate mais!\n";
                break;

            case 1:
                cadastrarProfessor(&curso);
                break;

            case 2:
                cadastrarAluno(&curso);
                break;

            case 3:
                cadastrarDisciplina(&curso);
                break;

            case 4:
                curso.imprimirAlunos();
                break;

            case 5:
                curso.imprimirProfessores();
                break;

            case 6:
                curso.imprimirDisciplinas();
                break;

            default:
                cout << "Opcao invalida!\n";
                break;
        }

    } while (opcao != 0);

    return 0;
}
