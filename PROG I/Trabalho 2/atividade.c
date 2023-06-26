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

void readLinesAndColumnsFromFile(FILE* arq, int* lines, int* columns) {

    fscanf(arq, "%d", lines);
    fscanf(arq, "%d", columns);

}

void skipOneLine(FILE* arq) {
    char aux[80];
    fgets(aux, 80, arq);
}

char getValidChar(FILE* arq) {
    //next char different of \n

    char character;

    do {
        fscanf(arq, "%c", &character);
    } while (character == '\n');

    return character;

}

void readMap(FILE* arq, char map[10][10], int lines, int columns) {

    for (int line = 0; line < lines; ++line) {
        for (int column = 0; column < columns; ++column) {
            map[line][column] = getValidChar(arq);
        }
    }

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

void searchStartPosition(char map[10][10], int lines, int columns, Position* startPosition) {

    for (int line = 0; line < lines; ++line) {
        for (int column = 0; column < columns; ++column) {

            if(map[line][column] == '@') {
                startPosition->x = line;
                startPosition->y = column;
            }

        }
    }

}

int isRepeat(Position positions[100], int positionsLength, Position testPos) {

    int repeats = 0;

    for(int i=0; i < positionsLength; i++) {

        if((positions[i].x == testPos.x) && (positions[i].y == testPos.y)) {
            repeats = 1;
        }

    }

    return repeats;

}

int containsAllTreasures(Route route, Position treasurePositions[100], int treasurePositionsLength) {

    int treasures = 0;
    Position positions[100];
    int positionsLength = 0;

    for(int i=0; i < treasurePositionsLength; i++) {

        for(int j=0; j < route.length; j++) {

            if((treasurePositions[i].x == route.routes[j].x) && (treasurePositions[i].y == route.routes[j].y)) {

                Position newPosition;
                newPosition.x = route.routes[j].x;
                newPosition.y = route.routes[j].y;

                if (isRepeat(positions, positionsLength, newPosition) == 0) {
                    treasures++;
                }

                positions[positionsLength] = newPosition;
                positionsLength++;

            }

        }

    }

    if(treasures >= treasurePositionsLength) {
        return 0;
    }

    return 1;

}

int canMove(char map[10][10], Position position) {

    if(map[position.x][position.y] == '.' || map[position.x][position.y] == '!' || map[position.x][position.y] == '@') {
        return  0;
    }

    return 1;

}

void getRouteFromUpperTreasureToStart(char map[10][10], int start_line, int start_column, Position end, Route route, int last_line, int last_column, Route allRoutes[1030], int* allRoutesLength, Position treasurePositions[100], int treasurePositionsLength) {

    Position new_pos;
    new_pos.x = start_line;
    new_pos.y = start_column;

    route.routes[route.length] = new_pos;
    route.length = route.length + 1;

    if(new_pos.x == end.x && new_pos.y == end.y) {
        allRoutes[*allRoutesLength] = route;
        *allRoutesLength = *allRoutesLength + 1;
    }

    if((map[start_line - 1][start_column] == '.' || map[start_line - 1][start_column] == '!' || map[start_line - 1][start_column] == '@') && ((start_line - 1) != last_line || start_column != last_column)) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == (start_line - 1) && route.routes[i].y == start_column) {
                repeats++;
            }
        }

        if(repeats == 0) {
            getRouteFromUpperTreasureToStart(map, start_line - 1, start_column, end, route, start_line, start_column,
                                             allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
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
            getRouteFromUpperTreasureToStart(map, start_line, start_column + 1, end, route, start_line, start_column,
                                             allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
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
            getRouteFromUpperTreasureToStart(map, start_line + 1, start_column, end, route, start_line, start_column,
                                             allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
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
            getRouteFromUpperTreasureToStart(map, start_line, start_column - 1, end, route, start_line, start_column,
                                             allRoutes, allRoutesLength, treasurePositions, treasurePositionsLength);
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

    return steps;

}

int endsOnStartPosition(Route route, Position startPosition) {

    if (route.routes[route.length - 1].x == startPosition.x && route.routes[route.length - 1].y == startPosition.y) {
        return 0;
    }

    return 1;
}

void getRouteFromLowerTreasureToStart(char map[10][10], Position now, Position startPosition, Route route, Position treasurePositions[100], int treasurePositionsLength, int* steps2) {

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

    if(endsOnStartPosition(route, startPosition) == 0 && route.length > 1) {
        
        if (*steps2 == 0) {
            *steps2 = route.length - 1;
        }

        if (*steps2 > route.length - 1) {
            *steps2 = route.length - 1;
        }
        
    }

    if(canMove(map, top) == 0) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == top.x && route.routes[i].y == top.y) {
                repeats++;
            }
        }

        if(repeats == 0) {
            getRouteFromLowerTreasureToStart(map, top, startPosition, route, treasurePositions, treasurePositionsLength, steps2);
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
            getRouteFromLowerTreasureToStart(map, bottom, startPosition, route, treasurePositions, treasurePositionsLength, steps2);
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
            getRouteFromLowerTreasureToStart(map, left, startPosition, route, treasurePositions, treasurePositionsLength, steps2);
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
            getRouteFromLowerTreasureToStart(map, right, startPosition, route, treasurePositions, treasurePositionsLength, steps2);
        }

    }

}

void getStepsFromLowerTreasureToAllTreasures(char map[10][10], Position now, Position startPosition, Route route, Position treasurePositions[100], int treasurePositionsLength, int* steps) {

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

        } else if (*steps >= (route.length - 1)) {

            int oldValue = *steps;

            *steps = route.length - 1;

            if(*steps >= oldValue) {
                *steps = oldValue;
            }

        }

    }

    if(canMove(map, top) == 0) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == top.x && route.routes[i].y == top.y) {
                repeats++;
            }
        }

        if(repeats == 0) {
            getStepsFromLowerTreasureToAllTreasures(map, top, startPosition, route, treasurePositions, treasurePositionsLength, steps);
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
            getStepsFromLowerTreasureToAllTreasures(map, bottom, startPosition, route, treasurePositions, treasurePositionsLength, steps);
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
            getStepsFromLowerTreasureToAllTreasures(map, left, startPosition, route, treasurePositions, treasurePositionsLength, steps);
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
            getStepsFromLowerTreasureToAllTreasures(map, right, startPosition, route, treasurePositions, treasurePositionsLength, steps);
        }

    }

}

void getStepsStartToFirstTreasure(char map[10][10], Position now, Position startPosition, Route route, Position treasurePositions[100], int treasurePositionsLength, int* steps2) {

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

    if(endsOnStartPosition(route, startPosition) == 0 && route.length > 1) {
        
        if (*steps2 == 0) {
            *steps2 = route.length - 1;
        }

        if (*steps2 > route.length - 1) {
            *steps2 = route.length - 1;
        }
        
    }

    // if(isEndLine(map, top, bottom, left, right) == 0) {
    //     getStepsStartToFirstTreasure(map, route.routes[route.length - 2], startPosition, route, treasurePositions, treasurePositionsLength, steps, lastTreasure);
    // }

    if(canMove(map, top) == 0) {

        int repeats = 0;

        for (int i = 0; i < route.length; ++i) {
            if(route.routes[i].x == top.x && route.routes[i].y == top.y) {
                repeats++;
            }
        }

        if(repeats == 0) {
            getStepsStartToFirstTreasure(map, top, startPosition, route, treasurePositions, treasurePositionsLength, steps2);
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
            getStepsStartToFirstTreasure(map, bottom, startPosition, route, treasurePositions, treasurePositionsLength, steps2);
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
            getStepsStartToFirstTreasure(map, left, startPosition, route, treasurePositions, treasurePositionsLength, steps2);
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
            getStepsStartToFirstTreasure(map, right, startPosition, route, treasurePositions, treasurePositionsLength, steps2);
        }

    }

}


void removeCanibals(char map[10][10], int lines, int columns) {

    for (int line = 0; line < lines; ++line) {
        for (int column = 0; column < columns; ++column) {

            if(map[line][column] == '*') {

                if(map[line - 1][column - 1] != '*') {
                    map[line - 1][column - 1] = '#';
                }

                if(map[line - 1][column + 1] != '*') {
                    map[line - 1][column + 1] = '#';
                }

                if(map[line + 1][column - 1] != '*') {
                    map[line + 1][column - 1] = '#';
                }

                if(map[line + 1][column + 1] != '*') {
                    map[line + 1][column + 1] = '#';
                }

                if(map[line - 1][column] != '*') {
                    map[line - 1][column] = '#';
                }

                if(map[line + 1][column] != '*') {
                    map[line + 1][column] = '#';
                }

                if(map[line][column - 1] != '*') {
                    map[line][column - 1] = '#';
                }

                if(map[line][column + 1] != '*') {
                    map[line][column + 1] = '#';
                }

            }

        }
    }

}

void searchAllTreasures(Position treasuresPositions[100], int* treasuresPositionsLength, char map[10][10], int lines, int columns) {

    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j) {
            if(map[i][j] == '!') {
                treasuresPositions[*treasuresPositionsLength].x = i;
                treasuresPositions[*treasuresPositionsLength].y = j;
                *treasuresPositionsLength = *treasuresPositionsLength + 1;
            }
        }
    }
}

void searchUpperAndLowerTreasure(Position treasuresPositions[100], int treasuresPositionsLength, Position* upperPosition, Position* lowerPosition) {

    upperPosition->x = 0;
    upperPosition->y = 0;

    lowerPosition->x = 0;
    lowerPosition->y = 0;

    for (int i = 0; i < treasuresPositionsLength; ++i) {

        if(upperPosition->x == 0) {
            upperPosition->x = treasuresPositions[i].x;
            upperPosition->y = treasuresPositions[i].y;
        } else if(treasuresPositions[i].x <= upperPosition->x) {
            upperPosition->x = treasuresPositions[i].x;
            upperPosition->y = treasuresPositions[i].y;
        }

        if(lowerPosition->x <= treasuresPositions[i].x) {
            lowerPosition->x = treasuresPositions[i].x;
            lowerPosition->y = treasuresPositions[i].y;
        }

    }


}

int calculateSteps(char map[10][10], Position startPosition, Position treasurePositions[100], int treasurePositionsLength, Position lowerTreasure, Position upperTreasure) {

    int allSteps = 0;

    Route route;
    route.length = 0;

    int step1 = 0, step2 = 0, step3 = 0;

    route.length = 0;

    if (treasurePositionsLength > 1) 
        getStepsFromLowerTreasureToAllTreasures(map, lowerTreasure, startPosition, route, treasurePositions, treasurePositionsLength, &step1);
    
    getRouteFromLowerTreasureToStart(map, lowerTreasure, startPosition, route, treasurePositions, treasurePositionsLength, &step2);
    
    getStepsStartToFirstTreasure(map, upperTreasure, startPosition, route, treasurePositions, treasurePositionsLength, &step3);

    return step1 + step2 + step3;

}

int main() {

    FILE* arq;
    arq = fopen(FILENAME, "r");

    do {
        char map[10][10];
        int lines = 0, columns = 0;

        readLinesAndColumnsFromFile(arq, &lines, &columns);

        if (lines == 0 && columns == 0) {
            continue;
        }
        
        readMap(arq, map, lines, columns);
        removeCanibals(map, lines, columns);

        Position startPosition;

        searchStartPosition(map, lines, columns, &startPosition);

        Position treasurePositions[100];
        int treasurePositionsLength = 0;

        searchAllTreasures(treasurePositions, &treasurePositionsLength, map, lines, columns);

        Position upperTreasure;
        Position lowerTreasure;

        searchUpperAndLowerTreasure(treasurePositions, treasurePositionsLength, &upperTreasure, &lowerTreasure);

        int allSteps = calculateSteps(map, startPosition, treasurePositions, treasurePositionsLength, lowerTreasure, upperTreasure);
        
        printf("%d\n", allSteps);

    } while (!feof(arq));
    
    fclose(arq);

    

    /*
    “Embora os piratas sejam espertos, falta-nos imaginação para dar nome às coisas.”
    Capitão Jack Sparrow
    */

    return 0;
}
