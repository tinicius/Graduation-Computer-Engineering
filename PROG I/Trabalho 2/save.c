#include <stdlib.h>
#include <stdio.h>

#define FILENAME "jack.txt"

typedef struct position {
    int x;
    int y;
} Position;

typedef struct route {
    Position routes[100];
    int length;
} Route;

void readLinesAndColumnsFromFile(int* lines, int* columns) {

    FILE* arq;

    arq = fopen(FILENAME, "r");

    fscanf(arq, "%d", lines);
    fscanf(arq, "%d", columns);

    fclose(arq);

}

void skipOneLine(FILE* arq) {
    char aux[80];
    fgets(aux, 80, arq);
}

char getValidChar(FILE* arq) {

    char character;

    do {
        fscanf(arq, "%c", &character);
    } while (character == '\n');

    return character;

}

void readMap(char map[10][10], int lines, int columns) {

    FILE* arq;

    arq = fopen(FILENAME, "r");

    skipOneLine(arq);

    for (int line = 0; line < lines; ++line) {
        for (int column = 0; column < columns; ++column) {
            map[line][column] = getValidChar(arq);
        }
    }

    fclose(arq);

}

void printMap(char map[10][10], int lines, int columns) {
    for (int line = 0; line < lines; ++line) {
        for (int column = 0; column < columns; ++column) {
            printf("%c ", map[line][column]);
        }
        printf("\n");
    }
}

void printfRoute(Route route) {

    for (int i = 0; i < route.length; ++i) {
        printf("%d%d ", route.routes[i].x, route.routes[i].y);
    }
    printf("\n");

}

void searchStartPoint(char map[10][10], int lines, int columns, int* start_line, int* start_column) {

    for (int line = 0; line < lines; ++line) {
        for (int column = 0; column < columns; ++column) {

            if(map[line][column] == '@') {
                *start_line = line;
                *start_column = column;
            }

        }
    }

}

int isRepeat(Position f[100], int fLength, Position testPos) {

    int r = 0;

    for(int i=0; i < fLength; i++) {

        if((f[i].x == testPos.x) && (f[i].y == testPos.y)) {
            r = 1;
        }

    }

    return r;

}

int containsAllTreasures(Route route, Position treasurePositions[100], int treasurePositionsLength) {

    int t = 0;
    Position f[100];
    int fLength = 0;

    for(int i=0; i < treasurePositionsLength; i++) {

        for(int j=0; j < route.length; j++) {

            if((treasurePositions[i].x == route.routes[j].x) && (treasurePositions[i].y == route.routes[j].y)) {

                Position new_t;
                new_t.x = route.routes[j].x;
                new_t.y = route.routes[j].y;

                if (isRepeat(f, fLength, new_t) == 0) {
                    t++;
                }

                f[fLength] = new_t;
                fLength++;

            }

        }

    }

    if(t >= treasurePositionsLength) {
        return 0;
    }

    return 1;

}

int canMove(char map[10][10], Position position) {

    if(map[position.x][position.y] == '.' || map[position.x][position.y] == '!') {
        return  0;
    }

    return 1;

}

int isEndLine(char map[10][10], Position top, Position bottom, Position left, Position right) {

    if(map[top.x][top.y] != '.' && map[top.x][top.y] != '!') {

        if(map[left.x][left.y] != '.' && map[left.x][left.y] != '!') {

            if(map[bottom.x][bottom.y] != '.' && map[bottom.x][bottom.y] != '!') {

                return 0;

            }

        }

    }

    return 1;

}

void move2(char map[10][10], int start_line, int start_column, Position end, Route route, int last_line, int last_column, Route allRoutes[1030], int* allRoutesLength, Position treasurePositions[100], int treasurePositionsLength) {

    Position new_pos;
    new_pos.x = start_line;
    new_pos.y = start_column;

    route.routes[route.length] = new_pos;
    route.length = route.length + 1;

    if(new_pos.x == end.x && new_pos.y == end.y) {
        allRoutes[*allRoutesLength] = route;
        *allRoutesLength = *allRoutesLength + 1;
    }

    // movendo pra tudo conte lado aoooo coisa boa!!!!

    if((map[start_line - 1][start_column] == '.' || map[start_line - 1][start_column] == '!' || map[start_line - 1][start_column] == '@') && ((start_line - 1) != last_line || start_column != last_column)) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == (start_line - 1) && route.routes[i].y == start_column) {
                repeats++;
            }
        }

        if(repeats == 0) {
            move2(map, start_line - 1, start_column, end, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
        }

    }

    if((map[start_line][start_column + 1]  == '.' || map[start_line][start_column + 1]  == '!' || map[start_line][start_column + 1]  == '@') && (start_line != last_line || (start_column + 1) != last_column)) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == start_line && route.routes[i].y == (start_column + 1)) {
                repeats++;
            }
        }

        if(repeats == 0) {
            move2(map, start_line, start_column + 1, end, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
        }

    }

    if((map[start_line + 1][start_column] == '.' || map[start_line + 1][start_column] == '!' || map[start_line + 1][start_column] == '@') && ((start_line + 1) != last_line || start_column != last_column)) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == (start_line + 1) && route.routes[i].y == start_column) {
                repeats++;
            }
        }

        if(repeats == 0) {
            move2(map, start_line + 1, start_column, end, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
        }

    }

    if((map[start_line][start_column - 1] == '.' || map[start_line][start_column - 1] == '!' || map[start_line][start_column - 1] == '@') && (start_line != last_line || ((start_column - 1) != last_column))) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if((route.routes[i].x == start_line) && (route.routes[i].y == (start_column - 1))) {
                repeats++;
            }
        }

        if(repeats == 0) {
            move2(map, start_line, start_column - 1, end, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
        }

    }

}

int getsBackFromUpperTreasure(int start_x, int start_y, Route allRoutes[1024], int allRoutesLength) {

    int steps = 0;
    int lasp = 0;

    for (int i = 0; i < allRoutesLength; ++i) {

        for (int j = 0; j < allRoutes[i].length; ++j) {

            if((allRoutes[i].routes[allRoutes[i].length - 1].x == start_x) && (allRoutes[i].routes[allRoutes[i].length - 1].y == start_y)) {

                if(steps == 0) {
                    steps = allRoutes[i].length - 1;
                    lasp = i;
                } else if(steps > allRoutes[i].length) {
                    steps = allRoutes[i].length - 1;
                    lasp = i;
                }

            }

        }

    }

    //printfRoute(allRoutes[lasp]);

    return steps;

}

int getAllSteps (char map[10][10], Position treasure, Position end, Position treasurePositions[100], int treasurePositionsLength) {

    Route route1;
    route1.length = 0;

    Route allRoutes1[1030];
    int allRoutes1Length = 0;

    move2(map, treasure.x, treasure.y, end, route1 , -1, -1, allRoutes1, &allRoutes1Length, treasurePositions, treasurePositionsLength);

    int stepAux = getsBackFromUpperTreasure(end.x, end.y, allRoutes1, allRoutes1Length);

    return stepAux;
}

void moving(char map[10][10], Position now, Position startPosition, Route route, Position treasurePositions[100], int treasurePositionsLength, int* steps, Position* lastTreasure) {

    route.routes[route.length] = now;
    route.length = route.length + 1;

    Position top;
    top.x = now.x - 1;
    top.y = now.y;

    Position bottom;
    bottom.x = now.x + 1;
    bottom.y = now.y;

    Position left;
    left.x = now.x;
    left.y = now.y - 1;

    Position right;
    right.x = now.x;
    right.y = now.y + 1;

    if(containsAllTreasures(route, treasurePositions, treasurePositionsLength) == 0) {

        if(*steps == 0) {
            *steps = route.length - 1;

            lastTreasure->x = now.x;
            lastTreasure->y = now.y;

            int stepAux = getAllSteps(map, *lastTreasure, startPosition, treasurePositions, treasurePositionsLength);

            *steps += stepAux;

        } else if (*steps >= (route.length - 1)) {

            int oldValue = *steps;

            *steps = route.length - 1;

            lastTreasure->x = now.x;
            lastTreasure->y = now.y;

            int stepAux = getAllSteps(map, *lastTreasure, startPosition, treasurePositions, treasurePositionsLength);

            *steps += stepAux;

            if(*steps >= oldValue) {
                *steps = oldValue;
            }

        }

    }

    if(isEndLine(map, top, bottom, left, right) == 0) {
        moving(map, route.routes[route.length - 2], startPosition, route, treasurePositions, treasurePositionsLength, steps, lastTreasure);
    }

    if(canMove(map, top) == 0) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == top.x && route.routes[i].y == top.y) {
                repeats++;;
            }
        }

        if(repeats == 0) {
            moving(map, top, startPosition, route, treasurePositions, treasurePositionsLength, steps, lastTreasure);
        }

    }

    if(canMove(map, bottom) == 0) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == bottom.x && route.routes[i].y == bottom.y) {
                repeats++;
            }
        }

        if(repeats == 0) {
            moving(map, bottom, startPosition, route, treasurePositions, treasurePositionsLength, steps, lastTreasure);
        }

    }

    if(canMove(map, left) == 0) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == left.x && route.routes[i].y == left.y) {
                repeats++;
            }
        }

        if(repeats == 0) {
            moving(map, left, startPosition, route, treasurePositions, treasurePositionsLength, steps, lastTreasure);
        }

    }

    if(canMove(map, right) == 0) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == right.x && route.routes[i].y == right.y) {
                repeats++;
            }
        }

        if(repeats == 0) {
            moving(map, right, startPosition, route, treasurePositions, treasurePositionsLength, steps, lastTreasure);
        }

    }

}

void move(char map[10][10], int start_line, int start_column, Route route, int last_line, int last_column, Route allRoutes[1030], int* allRoutesLength, Position treasurePositions[100], int treasurePositionsLength) {

    Position new_pos;
    new_pos.x = start_line;
    new_pos.y = start_column;

    route.routes[route.length] = new_pos;
    route.length = route.length + 1;

    if(containsAllTreasures(route, treasurePositions, treasurePositionsLength) == 0) {
        allRoutes[*allRoutesLength] = route;
        *allRoutesLength = *allRoutesLength + 1;
    }

    // movendo pra tudo conte lado aoooo coisa boa!!!!

    if((map[start_line - 1][start_column] == '.' || map[start_line - 1][start_column] == '!' || map[start_line - 1][start_column] == '@') && ((start_line - 1) != last_line || start_column != last_column)) {

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == (start_line - 1) && route.routes[i].y == start_column) {
                return;
            }
        }

        move(map, start_line - 1, start_column, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
    }

    if((map[start_line][start_column + 1]  == '.' || map[start_line][start_column + 1]  == '!' || map[start_line][start_column + 1]  == '@') && (start_line != last_line || (start_column + 1) != last_column)) {

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == start_line && route.routes[i].y == (start_column + 1)) {
                return;
            }
        }

        move(map, start_line, start_column + 1, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
    }

    if((map[start_line + 1][start_column] == '.' || map[start_line + 1][start_column] == '!' || map[start_line + 1][start_column] == '@') && ((start_line + 1) != last_line || start_column != last_column)) {

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == (start_line + 1) && route.routes[i].y == start_column) {
                return;
            }
        }

        move(map, start_line + 1, start_column, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
    }

    if((map[start_line][start_column - 1] == '.' || map[start_line][start_column - 1] == '!' || map[start_line][start_column - 1] == '@') && (start_line != last_line || ((start_column - 1) != last_column))) {

        for (int i = 0; i < route.length; ++i) {
            if((route.routes[i].x == start_line) && (route.routes[i].y == (start_column - 1))) {
                return;
            }
        }

        move(map, start_line, start_column - 1, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
    }


    //procurando meu tesouro

    if(map[start_line - 1][start_column] == '!') {

        Position end_pos;
        end_pos.x = start_line - 1;
        end_pos.y = start_column;

        route.routes[route.length] = end_pos;
        route.length = route.length + 1;

        allRoutes[*allRoutesLength] = route;
        *allRoutesLength++;

    }

    if(map[start_line][start_column + 1]  == '!') {

        Position end_pos;
        end_pos.x = start_line;
        end_pos.y = start_column + 1;

        route.routes[route.length] = end_pos;
        route.length = route.length + 1;

        allRoutes[*allRoutesLength] = route;
        *allRoutesLength++;

    }

    if(map[start_line + 1][start_column] == '!') {

        Position end_pos;
        end_pos.x = start_line + 1;
        end_pos.y = start_column;

        route.routes[route.length] = end_pos;
        route.length = route.length + 1;

        allRoutes[*allRoutesLength] = route;
        *allRoutesLength++;

    }

    if(map[start_line][start_column - 1] == '!') {

        Position end_pos;
        end_pos.x = start_line;
        end_pos.y = start_column - 1;

        route.routes[route.length] = end_pos;
        route.length = route.length + 1;

        allRoutes[*allRoutesLength] = route;
        *allRoutesLength++;

    }

}

int getStepsFromLowerTreasureToAllTreasures(Position treasurePositions[100], int treasurePositionsLength, Route allRoutes[1024], int allRoutesLength) {

    int steps = 0;
    int lasp = 0;

    for (int i = 0; i < allRoutesLength; ++i) {

        if (allRoutes[i].length >= treasurePositionsLength) {

            if(containsAllTreasures(allRoutes[i], treasurePositions, treasurePositionsLength) == 0) {

                //printfRoute(allRoutes[i]);

                if(steps == 0) {

                    steps = allRoutes[i].length;
                    lasp = i;
                } else if(allRoutes[i].length <= steps) {

                    steps = allRoutes[i].length;
                    lasp = i;
                }
            }

        }

    }

    printfRoute(allRoutes[lasp]);

    return steps;

}

int getStepsStartToFirstTreasure(int start_x, int start_y, Route allRoutes[1024], int allRoutesLength) {

    int steps = 0;
    int lasp = 0;

    for (int i = 0; i < allRoutesLength; ++i) {

        for (int j = 0; j < allRoutes[i].length; ++j) {

            if((allRoutes[i].routes[allRoutes[i].length - 1].x == start_x) && (allRoutes[i].routes[allRoutes[i].length - 1].y == start_y)) {

                if(steps == 0) {
                    steps = allRoutes[i].length;
                    lasp = i;
                } else if(steps > allRoutes[i].length) {
                    steps = allRoutes[i].length;
                    lasp = i;
                }

            }

        }

    }

    printfRoute(allRoutes[lasp]);

    return steps;

}

void move3(char map[10][10], int start_line, int start_column, Route route, int last_line, int last_column, Route allRoutes[1030], int* allRoutesLength, Position treasurePositions[100], int treasurePositionsLength) {

    Position new_pos;
    new_pos.x = start_line;
    new_pos.y = start_column;

    route.routes[route.length] = new_pos;
    route.length = route.length + 1;

    if(new_pos.x == 7 && new_pos.y == 7) {
        allRoutes[*allRoutesLength] = route;
        *allRoutesLength = *allRoutesLength + 1;
    }

    // movendo pra tudo conte lado aoooo coisa boa!!!!

    if((map[start_line - 1][start_column] == '.' || map[start_line - 1][start_column] == '!' || map[start_line - 1][start_column] == '@') && ((start_line - 1) != last_line || start_column != last_column)) {

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == (start_line - 1) && route.routes[i].y == start_column) {
                return;
            }
        }

        move3(map, start_line - 1, start_column, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
    }

    if((map[start_line][start_column + 1]  == '.' || map[start_line][start_column + 1]  == '!' || map[start_line][start_column + 1]  == '@') && (start_line != last_line || (start_column + 1) != last_column)) {

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == start_line && route.routes[i].y == (start_column + 1)) {
                return;
            }
        }

        move3(map, start_line, start_column + 1, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
    }

    if((map[start_line + 1][start_column] == '.' || map[start_line + 1][start_column] == '!' || map[start_line + 1][start_column] == '@') && ((start_line + 1) != last_line || start_column != last_column)) {

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == (start_line + 1) && route.routes[i].y == start_column) {
                return;
            }
        }

        move3(map, start_line + 1, start_column, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
    }

    if((map[start_line][start_column - 1] == '.' || map[start_line][start_column - 1] == '!' || map[start_line][start_column - 1] == '@') && (start_line != last_line || ((start_column - 1) != last_column))) {

        for (int i = 0; i < route.length; ++i) {
            if((route.routes[i].x == start_line) && (route.routes[i].y == (start_column - 1))) {
                return;
            }
        }

        move3(map, start_line, start_column - 1, route, start_line, start_column, allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
    }


    //procurando meu tesouro

    if(map[start_line - 1][start_column] == '!') {

        Position end_pos;
        end_pos.x = start_line - 1;
        end_pos.y = start_column;

        route.routes[route.length] = end_pos;
        route.length = route.length + 1;

        allRoutes[*allRoutesLength] = route;
        *allRoutesLength++;

    }

    if(map[start_line][start_column + 1]  == '!') {

        Position end_pos;
        end_pos.x = start_line;
        end_pos.y = start_column + 1;

        route.routes[route.length] = end_pos;
        route.length = route.length + 1;

        allRoutes[*allRoutesLength] = route;
        *allRoutesLength++;

    }

    if(map[start_line + 1][start_column] == '!') {

        Position end_pos;
        end_pos.x = start_line + 1;
        end_pos.y = start_column;

        route.routes[route.length] = end_pos;
        route.length = route.length + 1;

        allRoutes[*allRoutesLength] = route;
        *allRoutesLength++;

    }

    if(map[start_line][start_column - 1] == '!') {

        Position end_pos;
        end_pos.x = start_line;
        end_pos.y = start_column - 1;

        route.routes[route.length] = end_pos;
        route.length = route.length + 1;

        allRoutes[*allRoutesLength] = route;
        *allRoutesLength++;

    }

}

int main() {

    char map[10][10];
    int lines, columns;

    int start_line, start_column;

    readLinesAndColumnsFromFile(&lines, &columns);

    readMap(map, lines, columns);

    searchStartPoint(map, lines, columns, &start_line, &start_column);

    Position lowerTreasure;
    lowerTreasure.x = 0;
    lowerTreasure.y = 0;

    Position upperTreasure;
    upperTreasure.x = 0;
    upperTreasure.y = 0;

    Position treasurePositions[100];
    int treasurePositionsLength = 0;

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {

            if(map[i][j] == '!') {
                treasurePositions[treasurePositionsLength].x = i;
                treasurePositions[treasurePositionsLength].y = j;
                treasurePositionsLength++;

                if(i > lowerTreasure.x) {
                    lowerTreasure.x = i;
                    lowerTreasure.y = j;
                }

                if(upperTreasure.y == 0) {
                    upperTreasure.x = i;
                    upperTreasure.y = j;
                } else {

                    if(upperTreasure.y > j) {
                        upperTreasure.x = i;
                        upperTreasure.y = j;
                    }

                }

            }

        }
    }

    Route route;
    route.length = 0;

    Position startPosition;
    startPosition.x = start_line;
    startPosition.y = start_column;

    int rSteps = 0;
    Position lastTreasure;
    lastTreasure.x = 0;
    lastTreasure.y = 0;

    moving(map, startPosition, startPosition, route, treasurePositions, treasurePositionsLength, &rSteps, &lastTreasure);

    if (rSteps > 0) {
        printf("all steps = %d", rSteps );
    } else {

        Route allRoutes[1050];
        int allRoutesLength = 0;

        int step1 = 0, step2 = 0, step3 = 0;

        move(map, lowerTreasure.x, lowerTreasure.y, route, -1, -2, allRoutes, &allRoutesLength, treasurePositions, treasurePositionsLength);

        step1 = getStepsFromLowerTreasureToAllTreasures(treasurePositions, treasurePositionsLength, allRoutes, allRoutesLength);

        printf("%d \n", step1);

        allRoutesLength = 0;

        move3(map, upperTreasure.x, upperTreasure.y, route, -1, -2, allRoutes, &allRoutesLength, treasurePositions, treasurePositionsLength);
        step2 = getsBackFromUpperTreasure(start_line, start_column, allRoutes, allRoutesLength);
        allRoutesLength = 0;

        move3(map, lowerTreasure.x, lowerTreasure.y, route, -1, -2, allRoutes, &allRoutesLength, treasurePositions, treasurePositionsLength);
        step3 = getStepsStartToFirstTreasure(start_line, start_column, allRoutes, allRoutesLength);

        printf(" a=> %d", (step1 + step2 + step3) - 3);

    }

    
    return 0;
}
