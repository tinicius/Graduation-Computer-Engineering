#include <ctime>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <unistd.h>

#include "Airplane.h"
#include "Airport.h"

using namespace std;

bool read_option(bool *option) {
option:
  cout << "[0] Aleatório\n[1] Arquivo\n";
  cout << "Digite uma opção: ";
  cin >> *option;
  cin.ignore();

  if (cin.fail()) {
    cout << "Digite uma opção válida!" << endl;
    cin.clear();
    cin.ignore(80, '\n');
    goto option;
  }
  return *option;
}

int main() {
  const vector<string> AIRLINES = {"GOL", "LATAM", "AZUL",
                                   "American Airliness"};

  bool option, landing, taking_off;

  vector<Airplane> newAirplanes;

  unsigned short num, take_off, line_counter = 1, passengers, fuel;

  Airport airport;

  string line;

  int times, landing_id = 1, tracking_off_id = 2;

  srand(time(nullptr));

  if (read_option(&option)) {

    fstream file;
    string airline;

    file.open("input.txt", ios::in);

    file >> times;

    while (times--) {

      file >> num;

      while (num--) {

        file >> passengers;
        file >> airline;
        file >> fuel;

        Airplane new_airplane =
            Airplane(true, false, passengers, airline, fuel, landing_id);

        landing_id += 2;

        newAirplanes.push_back(new_airplane);
      }

      file >> num;

      while (num--) {

        file >> passengers;
        file >> airline;

        fuel = 15;

        Airplane new_airplane =
            Airplane(false, true, passengers, airline, fuel, tracking_off_id);

        tracking_off_id += 2;

        newAirplanes.push_back(new_airplane);
      }

      if (!airport.insertAirplanes(newAirplanes)) {
        cout << "Situação crítica!\n";
        return 0;
      }

      newAirplanes.erase(newAirplanes.begin(), newAirplanes.end());
    }

    file.close();

  } else {

    cout << "Digite o número de execuções: ";
    cin >> times;
    cout << endl;

    while (times--) {
      // Aleatorio entre 1-3
      num = rand() % 3 + 1;

      while (num--) {

        int passengers = rand() % 20 + 1;

        int airline_index = rand() % 4;
        string airline = AIRLINES[airline_index];

        int fuel = rand() % 15 + 1;

        Airplane new_airplane =
            Airplane(true, false, passengers, airline, fuel, landing_id);

        landing_id += 2;

        newAirplanes.push_back(new_airplane);
      }

      // Decolagens

      // Aleatorio entre 1-3
      num = rand() % 3 + 1;

      while (num--) {

        int passengers = rand() % 20 + 1;

        int airline_index = rand() % 4;
        string airline = AIRLINES[airline_index];

        int fuel = 15;

        Airplane new_airplane =
            Airplane(false, true, passengers, airline, fuel, tracking_off_id);

        tracking_off_id += 2;

        newAirplanes.push_back(new_airplane);
      }

      if (!airport.insertAirplanes(newAirplanes)) {
        cout << "Situação crítica!\n";
        return 0;
      }

      newAirplanes.erase(newAirplanes.begin(), newAirplanes.end());
    }
    return 0;
  }
}
