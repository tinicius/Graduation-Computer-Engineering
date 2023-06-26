//
// Created by vinic on 28/09/2022.
//

#ifndef TRABALHO_2_DATA_HPP
#define TRABALHO_2_DATA_HPP


class Data {
private:
    int dia;
    int mes;
    int ano;
    int horas;
    int minutos;
public:
    Data();

    Data(int dia, int mes, int ano, int horas, int minutos);

    void imprimirData();

    bool dataVazia();

    int getDia();

    void setDia(int dia);

    int getMes();

    void setMes(int mes);

    int getAno();

    void setAno(int ano);

    int getHoras();

    void setHoras(int horas);

    int getMinutos();

    void setMinutos(int minutos);
};


#endif //TRABALHO_2_DATA_HPP
