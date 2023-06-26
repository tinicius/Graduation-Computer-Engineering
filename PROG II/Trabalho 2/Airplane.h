//
// Created by cesarhrs on 11/14/22.
//

#ifndef TRABALHO2_AIRPLANE_H
#define TRABALHO2_AIRPLANE_H

#include <iostream>

using namespace std;

/*
g. Em cada minuto, as entradas devem possuir as seguintes informações:
i. número de aviões (até três) chegando nas filas de aterrissagem.
ii. O número de passageiros em cada avião.
iii. Companhia aérea de cada avião que podem ser das seguintes
companhias (GOL, LATAM, AZUL e American Airlines)
iv. Reservas de combustível dos aviões entrando na fila (de 1 a 15 minutos).
v. número de aviões (até três) chegando nas filas de decolagem
*/

class Airplane {
private:
  // i, v
  bool landing, taking_off; // isso daqui se pa nem precisa
  // ii,
  unsigned short passengers;
  // iii
  string airline;
  // iv
  unsigned short fuel;

  unsigned short entry_time;

  // 1-d
  unsigned id;

public:
  Airplane();

  Airplane(bool landing, bool taking_off, unsigned short passengers,
           string airline, float fuel, unsigned id);

  bool get_landing();
  void set_landing(bool landing);

  bool get_taking_off();
  void set_taking_off(bool taking_off);

  unsigned short get_passengers();
  void set_passengers(unsigned short passengers);

  string get_airline();
  void set_airline(string airline);

  unsigned short get_fuel();
  void set_fuel(unsigned short fuel);

  unsigned short get_entry_time();
  void set_entry_time(unsigned short entry_time);

  int get_id();

  void print();
  bool empty();
};

#endif // TRABALHO2_AIRPLANE_H
