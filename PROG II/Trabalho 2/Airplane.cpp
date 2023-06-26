//
// Created by cesarhrs on 11/14/22.
//

#include "Airplane.h"

#include <utility>

Airplane::Airplane() {
  landing = false;
  taking_off = false;
  passengers = 0;
  airline = "";
  fuel = 0.0;
}

Airplane::Airplane(bool landing, bool taking_off, unsigned short passengers,
                   std::string airline, float fuel, unsigned id) {
  this->landing = landing;
  this->taking_off = taking_off;
  this->passengers = passengers;
  this->airline = std::move(airline);
  this->fuel = fuel;
  this->id = id;
}

bool Airplane::get_landing() { return landing; }

void Airplane::set_landing(bool landing) { this->landing = landing; }

bool Airplane::get_taking_off() { return taking_off; }

void Airplane::set_taking_off(bool taking_off) {
  this->taking_off = taking_off;
}

unsigned short Airplane::get_passengers() { return passengers; }

void Airplane::set_passengers(unsigned short passengers) {
  this->passengers = passengers;
}

std::string Airplane::get_airline() { return airline; }

void Airplane::set_airline(std::string airline) { this->airline = airline; }

unsigned short Airplane::get_fuel() { return fuel; }

void Airplane::set_fuel(unsigned short fuel) { this->fuel = fuel; }

void Airplane::print() {
  cout << "Passageiros: " << this->passengers << endl;
  cout << "Companhia: " << this->airline << endl;
  cout << "Combustível: " << this->fuel << endl;
}

bool Airplane::empty() {
  if (this->get_airline().empty()) {
    return true;
  } else {
    return false;
  }
}

void Airplane::set_entry_time(unsigned short entry_time) {
  this->entry_time = entry_time;
}

int Airplane::get_id() { return this->id; }

unsigned short Airplane::get_entry_time() { return this->entry_time; }
