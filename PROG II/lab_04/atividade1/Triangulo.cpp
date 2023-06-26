#include <iostream>
#include <math.h>

#include "Triangulo.hpp"

using namespace std;

int Triangulo::totalTriangulos = 0;

Triangulo::Triangulo()
{
    this->totalTriangulos++;

    setLado1(1);
    setLado2(1);
    setLado3(1);
}

Triangulo::Triangulo(float l1, float l2, float l3)
{
    this->totalTriangulos++;
    setLado1(l1);
    setLado2(l2);
    setLado3(l3);
}

string Triangulo::getTipo()
{

    if ((this->lado1 == this->lado2) && (this->lado1 == this->lado3) && (this->lado2 == this->lado3))
    {
        return "Equilatero";
    }
    else if (this->lado1 != this->lado2 && this->lado1 != this->lado3)
    {
        return "Escaleno";
    }
    else
    {
        return "Isoceles";
    }
}

bool Triangulo::verifica(float a, float b, float c)
{

    bool caso1 = abs(b - c) < a && a < b + c;
    bool caso2 = abs(a - c) < b && b < a + c;
    bool caso3 = abs(a - b) < c && c < a + b;

    if (caso1 && caso2 && caso3)
    {
        return true;
    }

    return false;
}

void Triangulo::setLado1(float valor)
{
    this->lado1 = valor;
}

float Triangulo::getLado1()
{
    return this->lado1;
}

void Triangulo::setLado2(float valor)
{
    this->lado2 = valor;
}

float Triangulo::getLado2()
{
    return this->lado2;
}

void Triangulo::setLado3(float valor)
{
    this->lado3 = valor;
}

float Triangulo::getLado3()
{
    return this->lado3;
}