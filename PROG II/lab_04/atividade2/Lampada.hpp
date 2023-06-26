#ifndef __LAMPADA_HPP
#define __LAMPADA_HPP

using namespace std;

class Lampada {
   private:
    std::string modelo;
    float tensao;
    bool estado;

   public:
    static int totalLampadas;

    Lampada(std::string modelo, float tensao);

    void acender();
    void apagar();
    void printEstado();

    void setModelo(std::string modelo);
    std::string getModelo();

    void setTensao(float tensao);
    float getTensao();

    void setEstado(bool estado);
    bool getEstado();
};

#endif