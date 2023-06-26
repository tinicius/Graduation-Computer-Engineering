#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define tam 100

 typedef struct car {

	char model[80];
	char manufacturer[80];
	
	int fabricationYear;
	
	double consumption;

} Car;

void printfCar(Car car) {
	printf("\n");

	printf("Modelo: %s", car.model);
	printf("Fabricante: %s", car.manufacturer);
	printf("Ano de Fabricação: %d\n", car.fabricationYear);
	printf("Consumo: %lf\n", car.consumption);
}

void printfCars(Car cars[tam], int length) {

	for (int i = 0; i < length; i++) {
		printfCar(cars[i]);
	}
	
}

void printfMenu() {

	printf("\n");
    	
	printf("Menu\n");
	
	printf("[1] Cadastrar carro\n");
	printf("[2] Remover carro\n");
	printf("[3] Listar carros de determinado fabricante\n");
	printf("[4] Listar carro mais econômico\n");
	printf("[5] Listar carro com o maior consumo\n");
	printf("[6] Listar o carro mais novo\n");

	printf("\n");

}

Car readCar() {

	Car newCar;

	printf("Digite o modelo: ");
	fgets(newCar.model, 80, stdin);

	printf("Digite o fabricante: ");
	fgets(newCar.manufacturer, 80, stdin);

	printf("Digite o ano de fabricação: ");
	scanf("%d", &newCar.fabricationYear);

	printf("Digite o consumo: ");
	scanf("%lf", &newCar.consumption);

	return newCar;

}

void registerCar(Car cars[tam], int* carsLength) {

	if (carsLength >= 100) {
		printf("Já existem 100 carros armazenados!\n");
		exit(1);
	}

	Car newCar;
	newCar = readCar();

	cars[*carsLength] = newCar;
	*carsLength = *carsLength + 1;
	
 
}

void removeCar(Car cars[tam], int* carsLength) {
	char modelToRemove[80];
	int newLength = 0;

	printf("Digite o model do carro que deseja remover: ");
	fgets(modelToRemove, 80, stdin);

	for (int i = 0; i < *carsLength; i++) {
		if(!(strcmp(cars[i].model, modelToRemove) == 0)) {
			cars[newLength] = cars[i];
			newLength++; 
		}
	}

	*carsLength = newLength;
}

void showCarsOfManufacturer(Car cars[tam], int carsLength) {
	char manufacturer[80];
	Car carsManufacturer[tam];
	int carsManufacturerLength = 0;

	printf("Digite o fabricante que deseja listar: ");
	fgets(manufacturer, 80, stdin);

	for (int i = 0; i < carsLength; i++) {
		if (strcmp(cars[i].manufacturer, manufacturer) == 0) 
				printfCar(cars[i]);
	}
}

void showMoreEconomicalCar(Car cars[tam], int carsLength) {
	int consumption = 0;
	int moreEconomicalPosition;

	for (int i = 0; i < carsLength; i++) {
		if (cars[i].consumption >= consumption) {
			moreEconomicalPosition = i;
			consumption = cars[i].consumption;
		}
	}

	printfCar(cars[moreEconomicalPosition]);
}

void showLessEconomicalCar(Car cars[tam], int carsLength) {
	double lessEconomicalConsumption;
	int lessEconomicalPosition;

	for (int i = 0; i < carsLength; i++) {

		if (i == 0) {
			lessEconomicalConsumption = cars[i].consumption;
		}

		if (cars[i].consumption <= lessEconomicalConsumption) {
			lessEconomicalPosition = i;
			lessEconomicalConsumption = cars[i].consumption;
		}
	}

	printfCar(cars[lessEconomicalPosition]);
}

void showNewestCar(Car cars[tam], int carsLength) {
	int year = 0;
	int newestPosition;

	for (int i = 0; i < carsLength; i++) {

		if (cars[i].fabricationYear >= year) {
			newestPosition = i;
			year = cars[i].fabricationYear;
		}
	}

	printfCar(cars[newestPosition]);
}

void readSavedCarsLength(int* carsLength) {
	FILE* arq = fopen("data.bin", "rb");

	Car savedCars[tam];
	int length = 0;

	while (1) {

		fread(savedCars, sizeof(Car), 1, arq);
		
		if (feof(arq)) {
			break;
		}

		length++;
		
	}

	fclose(arq);

	*carsLength = length;
}

void checkFileExistAndCreateCaseNot() {
	FILE* arq = fopen("data.bin", "a+b");
	fclose(arq);
}

void readAllSavedCars(Car cars[tam], int carsLength) {
	FILE* arq = fopen("data.bin", "rb");
	fread(cars, sizeof(Car), carsLength, arq);
	fclose(arq);
}

void saveCars(Car cars[tam], int carsLength) {
	FILE* arq = fopen("data.bin", "wb");

	fwrite(cars, sizeof(Car), carsLength, arq);
	
	fclose(arq);
}

void readMenuOption(char* option) {

	printf("Digite um uma opção: ");
	scanf("%c", option);

	getchar();
}

void showDefaultMessage(char selectedOption) {
	if (selectedOption != '0') {
		printf("Opcao invalida!");
	} else {
		printf("Ate mais!");
	}
}

int main() {
	
	Car allCars[tam];
	int carsLength;
	char menuOption;

	checkFileExistAndCreateCaseNot();

	readSavedCarsLength(&carsLength);
	
	readAllSavedCars(allCars, carsLength);

    do {
    
    	printfMenu();
		readMenuOption(&menuOption);

		switch (menuOption) {
	
			case '1': ;

				registerCar(allCars, &carsLength);
				getchar();
						
				break;
		
			case '2': ;

				removeCar(allCars, &carsLength);

				break;
				
			case '3': ;

				showCarsOfManufacturer(allCars, carsLength);
				
				break;
			
			case '4': ;
			
				showMoreEconomicalCar(allCars, carsLength);

				break;
				
			case '5': ;
			
				showLessEconomicalCar(allCars, carsLength);
				
				break;
			
			case '6': ;

				showNewestCar(allCars, carsLength);
				
				break;
				
			default:

				showDefaultMessage(menuOption);
				
				break;
	
		}
 
    } while (menuOption != '0');

	saveCars(allCars, carsLength);

	return 0;

}
