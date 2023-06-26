
#include <iostream>
#include <queue>

using namespace std;

class Pessoa
{

public:
    int idade;
    string nome;

    Pessoa(string nome, int idade)
    {
        this->idade = idade;
        this->nome = nome;
    }
};

struct CompararPrioridade
{
    bool operator()(Pessoa const &p1, Pessoa const &p2)
    {
        return p1.idade < p2.idade;
    }
};

int main()
{
    priority_queue<Pessoa, vector<Pessoa>, CompararPrioridade> fila;

    Pessoa p1 = Pessoa("Jorge", 18);
    Pessoa p2 = Pessoa("Felipe", 61);
    Pessoa p3 = Pessoa("Pedro", 65);
    Pessoa p4 = Pessoa("senhor", 62);

    fila.push(p1);
    fila.push(p2);
    fila.push(p3);
    fila.push(p4);

    while (!fila.empty())
    {
        Pessoa p = fila.top();
        fila.pop();
        cout << p.nome << " " << p.idade << "\n";
    }

    return 0;
}