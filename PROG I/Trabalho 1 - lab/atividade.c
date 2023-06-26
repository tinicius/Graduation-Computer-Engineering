#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define length 4

int getExits(int cities[length][length], int city) {
    
    int exits = 0;

    for (int i = 0; i < length; i++) {  
        if (cities[city][i] == 1 && city != i)
            exits++;
    }

    return exits;
}

int getEntrances(int cities[length][length], int city) {
    
    int entrances = 0;

    for (int i = 0; i < length; i++) {
        if (cities[i][city] == 1 && city != i)
            entrances++;
    }

    return entrances;
}

void scanfCity(int* city) {
    printf("Digite o valor de k: ");
    scanf("%d", city);
}

void printfExitsAndEntrances(int exits, int entrances) {
    printf("Saídas = %d\n", exits);
    printf("Entradas = %d\n", entrances);
}

void showExitsAndEntrancesOfCity(int cities[length][length], int city) {
    int inputCityexits = 0, inputCityentrances = 0;
    
    inputCityexits = getExits(cities, city);
    inputCityentrances = getEntrances(cities, city);

    printfExitsAndEntrances(inputCityexits, inputCityentrances);
}

void showIsAllTwoWayOfCity(int cities[length][length], int city) {
    
    bool isAllTwoWay = true;

    if(getExits(cities, city) > 0 && getEntrances(cities, city) > 0) {
        for(int i = 0; i < length; i++) {
            if(cities[city][i] == 1 && city != i) {
                if(cities[city][i] != cities[i][city]) 
                    isAllTwoWay = false;
            }
                
        }

        if (isAllTwoWay == true) {
            printf("Todas as ligações são de mão dupla!\n\n");
        } else {
            printf("Nem todas as ligações são de mão dupla!\n");
        }
    } else {
        printf("Nem todas as ligações são de mão dupla!\n");
    }

}

int getMostEntracesCity(int cities[length][length]) {

    int entrancesForCity[length] = {0, 0, 0, 0};
    int mostEntrancesCity = 0;

    for (int cityFrom = 0; cityFrom < length; cityFrom++) {
        for (int cityTo = 0; cityTo < length; cityTo++) {
            if (cities[cityFrom][cityTo] == 1 && cityFrom != cityTo)
                entrancesForCity[cityTo] += 1;
        }
    }   

    for(int city = 0; city < length; city++) {
        if (entrancesForCity[city] > entrancesForCity[mostEntrancesCity])
            mostEntrancesCity = city;
    }

    return mostEntrancesCity;
}

void showMostEntrancesCity(int cities[length][length]) {
    int mostEntrancesCity;

    mostEntrancesCity = getMostEntracesCity(cities);

    printf("A cidade com maior número de entradas é a cidade %d\n", mostEntrancesCity);
}

void showCitiesWithDirectExitToCity(int cities[length][length], int city) {

    int hasExitToCity[length] = {0, 0, 0, 0};

    printf("Cidades que possuem saída direta para a cidade %d: ", city);

    for (int i = 0; i < length; i++) {
        if(cities[i][city] == 1 && city != i) {
            hasExitToCity[i] = 1;
        }
    }

    for(int i = 0; i < length; i++) {
        if (hasExitToCity[i] == 1)
            printf("Cidade %d ", i);
    }    

    printf("\n");
}
void printfIsolatedCities(int isolatedCities[length]) {
    
    bool hasIsolatedCities = false;

    for (int i = 0; i < length; i++) {
        if(isolatedCities[i] == 1)
            hasIsolatedCities = true;
    }

    if(hasIsolatedCities) {

        printf("Cidades Isoladas: ");

        for(int i = 0; i < length; i++) {
            if(isolatedCities[i] == 1)
                printf("Cidade %d ", i);
        }

        printf("\n\n");

    } else {
        printf("Não há cidades isoladas!\n");
    }
    


}

int showIsolatedCities(int cities[length][length]) {

    int isolatedCities[length] = {1, 1, 1, 1};

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            if (cities[i][j] == 1 && i != j) {
                isolatedCities[i] = 0;
                isolatedCities[j] = 0;
            }
        }
    }

    printfIsolatedCities(isolatedCities);
}

void printfCitiesWithoutExit(int cities[length]) {

    printf("Cidades onde não há saída, apesar de haver entrada: ");

    for(int i = 0; i < length; i++) {
        if(cities[i] == 1)
            printf("Cidade %d", i);
    }

    printf("\n");

}

void showCitiesWithoutExitButWithEntrance(int cities[length][length]) {
    int noExitCities[length] = {0, 0, 0, 0};

    for(int i = 0; i < length; i++) {
        if(getEntrances(cities, i) > 0) {
            if(getExits(cities, i) == 0)
                noExitCities[i] = 1;
        }
    }

    printfCitiesWithoutExit(noExitCities);

}

void printfCitiesWithExit(int cities[length]) {

    printf("Cidades onde há saída, apesar de não haver entrada: ");

    for(int i = 0; i < length; i++) {
        if(cities[i] == 1)
            printf("Cidade %d", i);
    }

    printf("\n");

}

void showCitiesWithExitButWithoutEntrance(int cities[length][length]) {
    int citiesWithExit[length] = {0, 0, 0, 0};

    for (int i = 0; i < length; i++) {
        if(getExits(cities, i) > 0) {
            if (getEntrances(cities, i) == 0) {
                citiesWithExit[i] = 1;
            }
            
        }
    }
    
    printfCitiesWithExit(citiesWithExit);

}

void showIsPossibleWayM(int cities[length][length]) {
    int m;
    bool isPossible = true;
    int citiesWay[80];

    printf("Digite o número de termos: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        printf(": ");
        scanf("%d", &citiesWay[i]);
    }

    for(int i = 0; i < m - 1; i++) { 

        if (cities[citiesWay[i]][citiesWay[i + 1]] == 0) {
            isPossible = false;
        }
        
    }

    if(isPossible == true) {
        printf("O roteiro M é possível!\n");
    } else {
        printf("O roteiro M é impossível!\n");
    }

}

int searchP(int k, int p, int f, int cities[length][length]) {

    if(cities[k][p] == 1) {
        return 0;
    } else {
        for (int i = 0; i < length; i++) {
            if (cities[k][i] == 1 && k != i && i != f) {
                if(searchP(i, p, k, cities) == 0) {
                    return 0;
                }
            }
        }

        return 1;
    }
}

void showIsPossibleWayKtoP(int cities[length][length]) {
    int k, p;
    printf("Digite k: ");
    scanf("%d", &k);

    printf("Digite p: ");
    scanf("%d", &p);

    printf("%d", searchP(k, p, k, cities));
}

int main() {

    int cities[length][length] = {
        {1, 1, 1, 0}, // 00 01 02 03
        {0, 1, 1, 0}, // 10 11 12 13
        {1, 0, 1, 1}, // 20 21 22 23
        {0, 0, 1, 1}  // 30 31 32 33
    };

    int inputCity;
    scanfCity(&inputCity);

    showExitsAndEntrancesOfCity(cities, inputCity);

    showIsAllTwoWayOfCity(cities, inputCity);

    showMostEntrancesCity(cities);

    showCitiesWithDirectExitToCity(cities, inputCity);

    showIsolatedCities(cities);

    showCitiesWithoutExitButWithEntrance(cities);

    showCitiesWithExitButWithoutEntrance(cities);

    showIsPossibleWayM(cities);

    showIsPossibleWayKtoP(cities);

    return 0;
}



