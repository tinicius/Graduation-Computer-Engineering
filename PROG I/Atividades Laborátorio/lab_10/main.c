#include <stdio.h>
#include <stdlib.h>

#define tam 3

void printfArray(int* array, int arrayLength) {

    printf("[");

    for (int i = 0; i < arrayLength; ++i) {

        if (i == (arrayLength - 1)) {
            printf(" %d", *array);
        } else {
            printf(" %d,", *array);
        }

        array++;
    }

    printf("]\n");

}

void setMaxAndMinFromArray(int* array, int arrayLength, int* max, int* min) {

    for (int i = 0; i < arrayLength; ++i) {

        if(*min == 0) {
            *min = *array;
        } else if(*min > *array) {
            *min = *array;
        }

        if(*max < *array) {
            *max = *array;
        }

        array++;
    }

}

void printfMaxAndMin(int max, int min) {
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
}

int* readArray(int* arrayLength) {

    printf("Digite o tamanho do vetor: ");
    scanf("%d", arrayLength);

    int *array = (int*) malloc(*arrayLength * sizeof(int));

    for (int i = 0; i < *arrayLength; ++i) {

        int newValue;

        printf("[%d]: ", i);
        scanf("%d", &newValue);
        array[i] = newValue;

    }

    return array;
}

int* sumArrays(int* array3, int* array4, int array3Length, int array4Length, int* resultArrayLength){

    if(array3Length >= array4Length) {
        *resultArrayLength = array3Length;
    } else {
        *resultArrayLength = array4Length;
    }

    int* resultArray = (int*) malloc(*resultArrayLength * sizeof(int));

    for (int i = 0; i < *resultArrayLength; ++i) {

        if(array3Length >= array4Length) {

            if(i < array4Length) {
                resultArray[i] = array3[i] + array4[i];
            } else {
                resultArray[i] = array3[i] + 0;
            }

        } else {

            if(i < array3Length) {
                resultArray[i] = array3[i] + array4[i];
            } else {
                resultArray[i] = 0 + array4[i];
            }

        }

    }

    return resultArray;

}

int main() {

    char menuOption;

    do {

        printf("Digite uma opcao: ");
        scanf("%c", &menuOption);
        getchar();

        switch (menuOption) {

            case '1': ;

                //Array to test first function
                int array1[tam] = {1, 2, 3};

                printfArray(array1, tam);
                break;

            case '2': ;

                //Array to test second function
                int array2[tam] = {1, 2, 3};

                int max = 0;
                int min = 0;

                setMaxAndMinFromArray(array2, tam, &max, &min);
                printfMaxAndMin(max, min);
                break;

            case '3': ;

                int array3Length;
                int array4Length;

                int* array3 = readArray(&array3Length);
                int* array4 = readArray( &array4Length);

                int array5Length;

                int* array5 = sumArrays(array3, array4, array3Length, array4Length, &array5Length);

                printfArray(array5, array5Length);

                getchar();
                break;

            default:
                printf("Opcao Invalida!\n");
                break;
        }

    } while (menuOption != '0');

    return 0;
}
