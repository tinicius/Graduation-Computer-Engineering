#include "Maze.hpp"

Maze::Maze() {
    file.readLinesColumnsNumberAndSaveMatrix(&this->lines, &this->columns,
                                             &this->numberOfMatrixs);

    this->matrix =
        file.loadMatrixFromFile(START_MATRIX, this->lines, this->columns);

    this->life = 10;
    this->bag = 0;
    this->itemsCounter = 0;
    this->dangersCounter = 0;
    this->collectedItem = false;
    this->positionsCounter = 0;

    this->startLine = 0;
    this->startColumn = 0;

    if (!verifyStartPosition(startLine, startColumn)) {
        cout << "Posição inicial inválida!";
        exit(-1);
    }

    this->line = startLine;
    this->column = startColumn;
    this->matrixIndex = START_MATRIX;
}

Maze::Maze(int startLine, int startColumn) {
    file.readLinesColumnsNumberAndSaveMatrix(&this->lines, &this->columns,
                                             &this->numberOfMatrixs);

    this->matrix =
        file.loadMatrixFromFile(START_MATRIX, this->lines, this->columns);

    this->life = 10;
    this->bag = 0;
    this->itemsCounter = 0;
    this->dangersCounter = 0;
    this->collectedItem = false;
    this->positionsCounter = 0;

    this->startLine = startLine;
    this->startColumn = startColumn;

    if (!verifyStartPosition(startLine, startColumn)) {
        cout << "Posição inicial inválida!";
        exit(-1);
    }

    this->line = startLine;
    this->column = startColumn;
    this->matrixIndex = START_MATRIX;
}

bool Maze::verifyStartPosition(int startLine, int startColumn) {
    if ((this->matrix)[startLine][startColumn].value == "#") {
        return false;
    }

    bool canMoveUpperLeftDiag, canMoveUpper, canMoveUpperRightDiag;
    bool canMoveleft, canMoveRight;
    bool canMoveBottomLeftDiag, canMoveBottom, canMoveBottomRightDiag;

    bool isBorder = false;

    if (startLine - 1 >= 0 && startColumn - 1 >= 0) {
        canMoveUpperLeftDiag =
            (this->matrix)[startLine - 1][startColumn - 1].value != "#";
    } else {
        isBorder = true;
    }

    if (startLine - 1 >= 0) {
        canMoveUpper = (this->matrix)[startLine - 1][startColumn].value != "#";
    } else {
        isBorder = true;
    }

    if (startLine - 1 >= 0 && startColumn + 1 <= (columns - 1)) {
        canMoveUpperRightDiag =
            (this->matrix)[startLine - 1][startColumn + 1].value != "#";
    } else {
        isBorder = true;
    }

    if (startColumn - 1 >= 0) {
        canMoveleft = (this->matrix)[startLine][startColumn - 1].value != "#";
    } else {
        isBorder = true;
    }

    if (startColumn + 1 <= (columns - 1)) {
        canMoveRight = (this->matrix)[startLine][startColumn + 1].value != "#";
    } else {
        isBorder = true;
    }

    if (startLine + 1 <= (lines - 1) && startColumn - 1 >= 0) {
        canMoveBottomLeftDiag =
            (this->matrix)[startLine + 1][startColumn - 1].value != "#";
    } else {
        isBorder = true;
    }

    if (startLine + 1 <= (lines - 1)) {
        canMoveBottom = (this->matrix)[startLine + 1][startColumn].value != "#";
    } else {
        isBorder = true;
    }

    if (startLine + 1 <= (lines - 1) && startColumn + 1 <= (columns - 1)) {
        canMoveBottomRightDiag =
            (this->matrix)[startLine + 1][startColumn + 1].value != "#";
    } else {
        isBorder = true;
    }

    // TODO
    // If you try teleport and have just 1 matrix,
    // you will win one valid random position on the same matrix
    // bool canTeleport = (numberOfMatrixs > 1) && isBorder;

    bool canTeleport = isBorder;

    if (canTeleport || canMoveUpperLeftDiag || canMoveUpper ||
        canMoveUpperRightDiag || canMoveleft || canMoveRight ||
        canMoveBottomLeftDiag || canMoveBottom || canMoveBottomRightDiag) {
        return true;
    }

    return false;
}

int Maze::randomInteger(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

void Maze::changeMatrix(int newMatrixIndex) {
    this->exploredMatrixes.insert(matrixIndex);

    this->file.saveMatrixOnFile(&matrix, matrixIndex, lines, columns);

    this->matrixIndex = newMatrixIndex;

    matrix = this->file.loadMatrixFromFile(matrixIndex, lines, columns);
}

pair<int, int> Maze::teleportBack() {
    // Verifica se é possivel ir para matriz anterior

    if (matrixIndex - 1 > 0) {
        changeMatrix(this->matrixIndex - 1);
    } else {
        // Se não é possível voltar, vai para última matriz
        changeMatrix(this->numberOfMatrixs);
    }

    string pos;
    int newLine;
    int newColumn;

    do {
        newLine = randomInteger(0, lines - 1);
        newColumn = randomInteger(0, columns - 1);

        pos = (this->matrix)[newLine][newColumn].value;
    } while (pos == "#");

    return {newLine, newColumn};
}

pair<int, int> Maze::teleportNext() {
    if (this->matrixIndex + 1 <= this->numberOfMatrixs) {
        // Verifica se é possível ir para próxima matriz
        changeMatrix(this->matrixIndex + 1);
    } else {
        // Se não é possível ir para próxima, vai para primeira
        changeMatrix(1);
    }

    string pos;
    int newLine;
    int newColumn;

    do {
        newLine = randomInteger(0, lines - 1);
        newColumn = randomInteger(0, columns - 1);

        pos = (this->matrix)[newLine][newColumn].value;
    } while (pos == "#");

    return {newLine, newColumn};
}

pair<int, int> Maze::randomMove() {
    pair<int, int> newPosition = {line, column};

    int auxIndex = this->matrixIndex;

    bool isSamePosition = (newPosition.first == line) &&
                          (newPosition.second == column) &&
                          (auxIndex == this->matrixIndex);

    bool isPositionBlock =
        (this->matrix)[newPosition.first][newPosition.second].value == "#";

    do {
        int move = randomInteger(1, 8);

        switch (move) {
            case 1:

                if (line - 1 < 0 || column - 1 < 0) {
                    newPosition = teleportBack();
                } else {
                    newPosition = {line - 1, column - 1};
                }

                break;
            case 2:

                if (line - 1 < 0) {
                    newPosition = teleportBack();
                } else {
                    newPosition = {line - 1, column};
                }

                break;
            case 3:

                if (line - 1 < 0 || column + 1 > (columns - 1)) {
                    newPosition = teleportBack();
                } else {
                    newPosition = {line - 1, column + 1};
                }

                break;
            case 4:

                if (column - 1 < 0) {
                    newPosition = teleportBack();
                } else {
                    newPosition = {line, column - 1};
                }

                break;
            case 5:

                if (column + 1 > (columns - 1)) {
                    newPosition = teleportNext();
                } else {
                    newPosition = {line, column + 1};
                }

                break;
            case 6:

                if (line + 1 > (lines - 1) || column - 1 < 0) {
                    newPosition = teleportNext();
                } else {
                    newPosition = {line + 1, column - 1};
                }

                break;
            case 7:
                if (line + 1 > (lines - 1)) {
                    newPosition = teleportNext();
                } else {
                    newPosition = {line + 1, column};
                }

                break;
            case 8:
                if (line + 1 > (lines - 1) || column + 1 > (columns - 1)) {
                    newPosition = teleportNext();
                } else {
                    newPosition = {line + 1, column + 1};
                }

                break;
        }

        isSamePosition = (newPosition.first == line) &&
                         (newPosition.second == column) &&
                         (auxIndex == matrixIndex);

        isPositionBlock =
            (this->matrix)[newPosition.first][newPosition.second].value == "#";

    } while (isSamePosition || isPositionBlock);

    return newPosition;
}

void Maze::checkPosition() {
    string position = matrix[line][column].value;
    this->positionsCounter++;

    matrix[line][column].explored = true;

    if (position == "*") {
        // Perigo
        life--;
        dangersCounter++;
    } else {
        // Como a função randomMove não retorna uma posição que seja
        // parede
        // (#) caso a posição não seja um perigo (*) ela vai ser um item
        // (1-10).

        int item = stoi(position);

        if (item != 0) {
            matrix[line][column].value = to_string(item - 1);
            bag++;
            itemsCounter++;
            this->collectedItem = true;

            if (bag == 4) {
                bag = 0;
                if (life < 10) life++;
            }
        }
    }
}

void Maze::play() {
    // Consumindo posição inicial
    checkPosition();

    while (life > 0) {
        pair<int, int> nextMove = randomMove();

        line = nextMove.first;
        column = nextMove.second;
        
        if (matrixIndex == START_MATRIX &&
            (int)exploredMatrixes.size() == numberOfMatrixs &&
            line == startLine && column == startColumn) {
            if (!this->collectedItem)
                break;
            else
                this->collectedItem = false;
        }
        checkPosition();
    }

    file.saveMatrixOnFile(&matrix, matrixIndex, lines, columns);
}

void Maze::review() {
    int notExploredCounter =
        file.saveOutputFile(numberOfMatrixs, lines, columns);

    cout << "-----FIM DE JOGO--------" << endl;

    cout << "Casas percorridas ao todo: " << positionsCounter << endl;

    cout << "Soma dos items percorridos pelo caminho: " << itemsCounter << endl;

    cout << "Casas não exploradas: " << notExploredCounter << endl;

    cout << "Perigos enfrentados: " << dangersCounter << endl;

    cout << "Vida ao final: " << life << endl;
}