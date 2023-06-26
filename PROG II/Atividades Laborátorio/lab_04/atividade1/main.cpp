#include <iostream>

#include "Triangulo.hpp"

using namespace std;

int main()
{

    float lado1, lado2, lado3;

    cout << "Digite o lado 1: ";
    cin >> lado1;

    cout << "Digite o lado 2: ";
    cin >> lado2;

    cout << "Digite o lado 3: ";
    cin >> lado3;

    if (Triangulo::verifica(lado1, lado2, lado3))
    {

        Triangulo triangulo = Triangulo(lado1, lado2, lado3);

        cout << "Você criou um triangulo " << triangulo.getTipo();
    }
    else
    {
        cout << "Valores invalido para um triangulo!" << endl;
    }
}