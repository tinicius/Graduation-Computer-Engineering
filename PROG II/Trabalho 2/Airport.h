//
// Created by vinic on 16/11/2022.
//

#ifndef TRABALHO2_AIRPORT_H
#define TRABALHO2_AIRPORT_H

#include "Airplane.h"

#include "array"
#include "iostream"
#include "queue"
#include "vector"

using namespace std;

struct OrderByFuel {
  bool operator()(Airplane &a, Airplane &b) {
    return a.get_fuel() >= b.get_fuel();
  }
};

struct OrderByEntryTime {
  bool operator()(Airplane &a, Airplane &b) {
    return a.get_entry_time() >= b.get_entry_time();
  }
};

class Airport {

public:
  Airport();

  bool insertAirplanes(vector<Airplane> airplanes);

  int time;

private:
  // Filas de espera para a pista 1 e 2
  array<priority_queue<Airplane, vector<Airplane>, OrderByFuel>, 4>
      waiting_runway;

  // Filas de decolagens
  array<priority_queue<Airplane, vector<Airplane>, OrderByEntryTime>, 3>
      taking_off_runway;

  // Pistas
  Airplane runway[3];

  // Emergencias
  priority_queue<Airplane, vector<Airplane>, OrderByFuel> emergencies;

  array<vector<int>, 3> tracking_off_times;
  array<vector<int>, 4> landing_times;
  int emergencies_number;

  void addMinute();
  void reduceFuel();

  void printWaitingQueue(
      array<priority_queue<Airplane, vector<Airplane>, OrderByFuel>, 4>
          waiting_runway,
      int i);

  void printAllWaitingQueues();

  void printAllWaitingTakingOff();

  void printAllRunways();

  void distribute_new_airplanes(vector<Airplane> airplanes);

  void runway3();

  void runway2();

  void runway1();

  void search_emergencie_landing(int i);
  void search_emergencie_tacking_off(int i);

  void clean_all_runways();
};

#endif // TRABALHO2_AIRPORT_H
