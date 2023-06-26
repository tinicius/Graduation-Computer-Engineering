//
// Created by vinic on 16/11/2022.
//

#include "Airport.h"

Airport::Airport() {
  this->time = 0;
  this->emergencies_number = 0;
}

void Airport::addMinute() { this->time += 1; }

void Airport::printAllWaitingQueues() {
  this->printWaitingQueue(this->waiting_runway, 0);
  this->printWaitingQueue(this->waiting_runway, 1);
  this->printWaitingQueue(this->waiting_runway, 2);
  this->printWaitingQueue(this->waiting_runway, 3);
  cout << endl;
}

void Airport::printWaitingQueue(
    array<priority_queue<Airplane, vector<Airplane>, OrderByFuel>, 4>
        waiting_runway,
    int i) {

  cout << "Fila de Espera " << to_string(i + 1) << ":";

  priority_queue<Airplane, vector<Airplane>, OrderByFuel> w1;

  if (!waiting_runway[i].empty()) {
    w1 = waiting_runway[i];
  }

  while (!w1.empty()) {
    auto top = w1.top();
    cout << "\t" << top.get_id();
    w1.pop();
  }

  cout << endl;
};

void Airport::printAllWaitingTakingOff() {
  int count = 0;

  for (auto queue : this->taking_off_runway) {
    count++;
    cout << "Fila de Decolagem " << count << ":";
    while (!queue.empty()) {
      auto top = queue.top();
      cout << '\t' << top.get_id();
      queue.pop();
    }
    cout << endl;
  }

  cout << endl;
}

void Airport::printAllRunways() {
  if (!this->runway[0].get_airline().empty()) {
    if (this->runway[0].get_landing()) {
      cout << this->runway[0].get_airline() << " " << this->runway[0].get_fuel()
           << " pousou na pista 1" << endl;
    } else {
      cout << this->runway[0].get_airline() << " " << this->runway[0].get_fuel()
           << " decolou na pista 1" << endl;
    }
  }

  if (!this->runway[1].get_airline().empty()) {
    if (this->runway[1].get_landing()) {
      cout << this->runway[1].get_airline() << " " << this->runway[1].get_fuel()
           << " pousou na pista 2" << endl;
    } else {
      cout << this->runway[1].get_airline() << " " << this->runway[1].get_fuel()
           << " decolou na pista 2" << endl;
    }
  }

  if (!this->runway[2].get_airline().empty()) {
    if (this->runway[2].get_landing()) {
      cout << this->runway[2].get_airline() << " " << this->runway[2].get_fuel()
           << " pousou na pista 3" << endl;
    } else {
      cout << this->runway[2].get_airline() << " " << this->runway[2].get_fuel()
           << " decolou na pista 3" << endl;
    }
  }

  cout << endl;
}

void Airport::distribute_new_airplanes(vector<Airplane> airplanes) {
  vector<Airplane> landings;
  vector<Airplane> taking_offs;

  // Distruibuindo as aeronaves em pousos e decolagens
  for (auto airplane : airplanes) {

    airplane.set_entry_time(this->time);

    if (airplane.get_taking_off()) {
      taking_offs.push_back(airplane);
      continue;
    }

    if (airplane.get_landing()) {
      landings.push_back(airplane);
      continue;
    }
  }

  // Distribuindo listas de espera para pouso
  for (auto airplane : landings) {

    int index = 0;
    int size = -1;

    for (int i = 0; i < this->waiting_runway.size(); i++) {
      auto waiting = this->waiting_runway[i];

      if (size == -1) {
        index = i;
        size = waiting.size();
      }

      if (waiting.size() <= size) {
        index = i;
        size = waiting.size();
      }
    }

    this->waiting_runway[index].push(airplane);
  }

  // Distruibuindo lista de espera para decolagem
  for (auto airplane : taking_offs) {

    int index = 0;
    int size = -1;

    for (int i = 0; i < this->taking_off_runway.size(); i++) {
      auto taking_off = this->taking_off_runway[i];

      if (size == -1) {
        index = i;
        size = taking_off.size();
      }

      if (taking_off.size() <= size) {
        index = i;
        size = taking_off.size();
      }
    }

    this->taking_off_runway[index].push(airplane);
  }
}

void Airport::runway3() {

  if (this->runway[2].empty()) {

    if (!this->taking_off_runway[2].empty()) {

      auto top = this->taking_off_runway[2].top();

      this->runway[2] = top;

      this->tracking_off_times[2].push_back(this->time - top.get_entry_time());

      this->taking_off_runway[2].pop();
    }
  }
}

void Airport::runway2() {
  if (this->runway[1].get_airline().empty()) {

    Airplane waiting4;
    Airplane waiting3;
    Airplane tacking_off;

    if (!this->waiting_runway[3].empty()) {
      waiting4 = this->waiting_runway[3].top();
    } else {
      waiting4 = Airplane();
    }

    if (!this->waiting_runway[2].empty()) {
      waiting3 = this->waiting_runway[2].top();
    } else {
      waiting3 = Airplane();
    }

    if (!this->taking_off_runway[1].empty()) {
      tacking_off = this->taking_off_runway[1].top();
    } else {
      tacking_off = Airplane();
    }

    vector<int> fuels = {0, 0, 0};

    if (!waiting4.empty()) {
      fuels[0] = waiting4.get_fuel();
    } else {
      fuels[0] = -1;
    }

    if (!waiting3.empty()) {
      fuels[1] = waiting3.get_fuel();
    } else {
      fuels[1] = -1;
    }

    if (!tacking_off.empty()) {
      fuels[2] = tacking_off.get_fuel();
    } else {
      fuels[2] = -1;
    }

    int index = -1;
    int menor = 16;

    for (int i = 0; i < 3; ++i) {
      if (fuels[i] != -1 && fuels[i] < menor) {
        index = i;
        menor = fuels[i];
      }
    }

    switch (index) {
    case -1:
      // Nenhum avião esperando
      break;
    case 0:
      this->runway[1] = waiting4;

      this->landing_times[3].push_back(this->time - waiting4.get_entry_time());

      this->waiting_runway[3].pop();
      break;
    case 1:
      this->runway[1] = waiting3;

      this->landing_times[2].push_back(this->time - waiting3.get_entry_time());

      this->waiting_runway[2].pop();
      break;
    case 2:
      this->runway[1] = tacking_off;

      this->tracking_off_times[1].push_back(this->time -
                                            tacking_off.get_entry_time());

      this->taking_off_runway[1].pop();
      break;
    default:
      // Default case
      break;
    }
  }
}

void Airport::runway1() {
  if (this->runway[0].get_airline().empty()) {
    Airplane waiting2;
    Airplane waiting1;
    Airplane tacking_off;

    if (!this->waiting_runway[1].empty()) {
      waiting2 = this->waiting_runway[1].top();
    } else {
      waiting2 = Airplane();
    }

    if (!this->waiting_runway[0].empty()) {
      waiting1 = this->waiting_runway[0].top();
    } else {
      waiting1 = Airplane();
    }

    if (!this->taking_off_runway[0].empty()) {
      tacking_off = this->taking_off_runway[0].top();
    } else {
      tacking_off = Airplane();
    }

    vector<int> fuels = {0, 0, 0};

    if (!waiting2.empty()) {
      fuels[0] = waiting2.get_fuel();
    } else {
      fuels[0] = -1;
    }

    if (!waiting1.empty()) {
      fuels[1] = waiting1.get_fuel();
    } else {
      fuels[1] = -1;
    }

    if (!tacking_off.empty()) {
      fuels[2] = tacking_off.get_fuel();
    } else {
      fuels[2] = -1;
    }

    int index = -1;
    int menor = 16;

    for (int i = 0; i < 3; ++i) {
      if (fuels[i] != -1 && fuels[i] < menor) {
        index = i;
        menor = fuels[i];
      }
    }

    switch (index) {
    case -1:
      // Nenhum avião esperando
      break;
    case 0:
      this->runway[0] = waiting2;

      this->landing_times[1].push_back(this->time - waiting2.get_entry_time());

      this->waiting_runway[1].pop();
      break;
    case 1:
      this->runway[0] = waiting1;

      this->landing_times[0].push_back(this->time - waiting1.get_entry_time());

      this->waiting_runway[0].pop();
      break;
    case 2:
      this->runway[0] = tacking_off;

      this->tracking_off_times[0].push_back(this->time -
                                            tacking_off.get_entry_time());

      this->taking_off_runway[0].pop();
      break;
    default:
      // Default
      break;
    }
  }
}

void Airport::reduceFuel() {

  for (int i = 0; i < this->waiting_runway.size(); i++) {
    auto waiting = this->waiting_runway[i];

    priority_queue<Airplane, vector<Airplane>, OrderByFuel> aux;

    while (!waiting.empty()) {
      auto top = waiting.top();
      top.set_fuel(top.get_fuel() - 1);
      aux.push(top);
      waiting.pop();
    }

    this->waiting_runway[i] = aux;
  }
}

void Airport::clean_all_runways() {
  this->runway[0] = Airplane();
  this->runway[1] = Airplane();
  this->runway[2] = Airplane();
}

void Airport::search_emergencie_landing(int i) {
  while (!this->waiting_runway[i].empty()) {

    Airplane top = waiting_runway[i].top();

    if (top.get_fuel() < 3) {
      this->emergencies.push(top);
      this->waiting_runway[i].pop();
      this->emergencies_number += 1;
    } else {
      return;
    }
  }
}

bool Airport::insertAirplanes(vector<Airplane> airplanes) {

  this->addMinute();

  this->distribute_new_airplanes(airplanes);

  cout << "Minuto " << this->time << endl << endl;

  printAllWaitingQueues();
  printAllWaitingTakingOff();

  for (int i = 0; i < this->waiting_runway.size(); i++) {
    search_emergencie_landing(i);
  }

  while (!this->emergencies.empty()) {

    auto top = this->emergencies.top();

    if (this->runway[2].empty()) {
      this->runway[2] = top;
      this->emergencies.pop();
      continue;
    } else if (this->runway[1].empty()) {
      this->runway[1] = top;
      this->emergencies.pop();
      continue;
    } else if (this->runway[1].empty()) {
      this->runway[1] = top;
      this->emergencies.pop();
      continue;
    }

    return false;
  }

  this->runway3();

  this->runway2();

  this->runway1();

  this->printAllRunways();

  cout << "Médias de Tempo\n";

  double global_sum = 0;
  double global_size = 0;

  for (int i = 0; i < 3; i++) {
    double mean = 0;
    double sum = 0;

    for (int value : this->tracking_off_times[i])
      sum += value;

    global_sum += sum;

    double total = this->tracking_off_times[i].size();
    global_size += total;

    if (total != 0)
      mean = sum / total;

    cout << endl << "Decolagem " << i + 1 << ": " << mean;
  }

  cout << endl;

  for (int i = 0; i < 4; i++) {
    double mean = 0;
    double sum = 0;

    for (int value : this->landing_times[i])
      sum += value;

    global_sum += sum;

    double total = this->landing_times[i].size();
    global_size += total;

    if (total != 0)
      mean = sum / total;

    cout << endl << "Espera " << i + 1 << ": " << mean;
  }

  cout << endl << endl;
  cout << "Global: " << global_sum / global_size << endl;
  cout << "Emergências: " << this->emergencies_number;

  cout << endl;

  cout << "------------------------" << endl;

  this->reduceFuel();

  this->clean_all_runways();

  return true;
}
