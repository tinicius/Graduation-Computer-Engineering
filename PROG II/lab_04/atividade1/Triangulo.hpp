#ifndef __TRIANGULO_HPP
#define __TRIANGULO_HPP

#include <string>

using namespace std;

class Triangulo {
   private:
    float lado1;
    float lado2;
    float lado3;

   public:
    static int totalTriangulos;
    static bool verifica(float a, float b, float c);

    Triangulo(float l1, float l2, float l3);
    Triangulo();

    string getTipo();

    void setLado1(float valor);
    float getLado1();

    void setLado2(float valor);
    float getLado2();

    void setLado3(float valor);
    float getLado3();
};

#endif