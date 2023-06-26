#include <stdlib.h>
#include <stdio.h>

int isDateAfter(int day, int month, int year) {

    if ((year > 1582) || (year == 1582 && month > 10) || (year == 1582 && month == 10 && day >= 15)) 
        return 0;
    
    return 1;
}

void printWeekDay(int day, int month, int year) {
    int A, B, C = 0, D, E;
    int julianDay;

    if (month < 3) {
        year = year - 1;
        month = month + 12;
    }

    if (isDateAfter(day, month, year) == 0) {
        A = year / 100;
        B = A / 4;
        C = 2 - A + B;
    }

    D = 365.25 * (year + 4716);
    E = 30.6001 * (month + 1);

    julianDay = D + E + day + C - 1524;

    switch (julianDay % 7) {
    case 0:
        printf("Segunda-Feira!\n");
        break;
    
    case 1:
        printf("Terca-Feira\n");
        break;
    
    case 2:
        printf("Quarta-Feira\n");
        break;
    
    case 3:
        printf("Quinta-Feira\n");
        break;
    
    case 4:
        printf("Sexta-Feira\n");
        break;
    
    case 5:
        printf("Sábado\n");
        break;
    
    case 6:
        printf("Domingo\n");
        break;
    
    default:
        printf("Error\n");
        break;
    }
}

struct Date {
    int day;
    int month;
    int year;
};

void printNextYears(struct Date date, int years) {

    for (int i = 0; i <= years; i++) {
        printf("%d/%d/%d - ", date.day, date.month, date.year + i);
        printWeekDay(date.day, date.month, date.year + i);
    }

}

struct Date readDate() {

    int day, month, year;

    printf("Dia: ");
    scanf("%d", &day);

    printf("Mês: ");
    scanf("%d", &month);

    printf("Ano: ");
    scanf("%d", &year);

    struct Date date = {
        .day = day,
        .month = month,
        .year = year
    };

    return date;

}

char readOption(char* option) {
    
    printf("\nDeseja testar outra Data?\n");
    printf("'S' - Sim\n");
    printf("'N' - Não\n");
    getchar();
    scanf("%c", option);

}

int isOptionValid(char* option) {

    if(*option == 'S' || *option == 's')
        return 1;

    return 0;
}

int main() {

    char option; 

    do {

        struct Date date;
        date = readDate();

        printNextYears(date, 10);

        readOption(&option);

    } while (isOptionValid(&option));
    

    return 0;
}