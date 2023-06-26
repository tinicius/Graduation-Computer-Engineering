#include <iostream>

using namespace std;

#include "ListaPessoaFisica.hpp"
#include "ListaPessoaJuridica.hpp"

void mostrarMenu() {
    cout << "[0] Sair" << endl;
    cout << "[1] Cadastrar Pessoa Física" << endl;
    cout << "[2] Cadastrar Pessoa Jurídica" << endl;
    cout << "[3] Consultar IR Pessoa Física" << endl;
    cout << "[4] Consultar IR Pessoa Jurídica" << endl;
    cout << "[5] Listar IRs" << endl;
    cout << "[6] Excluir Pessoa Física" << endl;
    cout << "[7] Excluir Pessoa Jurídica" << endl;

    cout << endl;
}

void cadastrarPessoaFisica(ListaPessoaFisica *pessoasFisicas) {

    string nome, cpf;
    double rendaBruta;

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite o cpf: ";
    cin >> cpf;

    cout << "Digite a renda bruta: ";
    cin >> rendaBruta;

    PessoaFisica *pessoaFisica = new PessoaFisica(nome, rendaBruta, cpf);

    pessoasFisicas->inserir(pessoaFisica);

    cout << "Contribuente cadastrado!" << endl;
}

void cadastrarPessoaJuridica(ListaPessoaJuridica *pessoasJuridicas) {

    string nome, cnpj;
    double rendaBruta;

    cout << "Digite o nome: ";
    getline(cin, nome);

    cout << "Digite o cnpj: ";
    cin >> cnpj;

    cout << "Digite a renda bruta: ";
    cin >> rendaBruta;

    PessoaJuridica *pessoaJuridica = new PessoaJuridica(nome, rendaBruta, cnpj);

    pessoasJuridicas->inserir(pessoaJuridica);

    cout << "Contribuente cadastrado!" << endl;
}

void consultarIRPessoaFisica(ListaPessoaFisica *pessoasFisicas) {
    string cpf;

    cout << "Digite o cpf: " << endl;
    cin >> cpf;

    pessoasFisicas->buscar(cpf);
}

void consultarIRPessoaJuridica(ListaPessoaJuridica *pessoasJuridicas) {
    string cnpj;

    cout << "Digite o cnpj: " << endl;
    cin >> cnpj;

    pessoasJuridicas->buscar(cnpj);
}

void listarTodos(ListaPessoaFisica *pessoasFisicas, ListaPessoaJuridica *pessoasJuridicas) {
    pessoasFisicas->imprimir();
    pessoasJuridicas->imprimir();
}

void excluirPessoaFisica(ListaPessoaFisica *pessoasFisicas) {
    string cpf;

    cout << "Digite o cpf: " << endl;
    cin >> cpf;

    pessoasFisicas->remover(cpf);
}

void excluirPessoaJuridica(ListaPessoaJuridica *pessoasJuridicas) {
    string cnpj;

    cout << "Digite o cnpj: " << endl;
    cin >> cnpj;

    pessoasJuridicas->remover(cnpj);
}

int main() {

    ListaPessoaFisica pessoasFisicas;
    ListaPessoaJuridica pessoasJuridicas;

    int op;

    do {
        mostrarMenu();

        cout << "Digite uma opção: ";
        cin >> op;
        cin.ignore();

        switch (op) {

            case 0:
                cout << "Até mais!" << endl;
                break;

            case 1:
                cadastrarPessoaFisica(&pessoasFisicas);
                break;

            case 2:
                cadastrarPessoaJuridica(&pessoasJuridicas);
                break;

            case 3:
                consultarIRPessoaFisica(&pessoasFisicas);
                break;

            case 4:
                consultarIRPessoaJuridica(&pessoasJuridicas);
                break;

            case 5:
                listarTodos(&pessoasFisicas, &pessoasJuridicas);
                break;

            case 6:
                excluirPessoaFisica(&pessoasFisicas);
                break;

            case 7:
                excluirPessoaJuridica(&pessoasJuridicas);
                break;

            default:
                cout << "Opção inválida" << endl;
                break;

        }


    } while (op != 0);

    return 0;
}
