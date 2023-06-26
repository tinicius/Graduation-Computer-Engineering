#include "File.hpp"

void File::readLinesColumnsNumberAndSaveMatrix(int* lines, int* columns,
                                               int* numberOfMatrixs) {
    ifstream input;
    input.open(INPUT_DATA, ios::in);

    input >> *lines;
    input >> *columns;
    input >> *numberOfMatrixs;

    saveAllMatrixOnSeparateFiles(&input, *numberOfMatrixs, *lines, *columns);

    input.close();
}

string File::generateMatrixFilename(int matrixIndex) {
    string filename = "";
    filename += to_string(matrixIndex);
    filename += ".txt";

    return filename;
}

vector<vector<Item>> File::loadMatrixFromFile(int matrixIndex, int lines,
                                              int columns) {
    string filename = generateMatrixFilename(matrixIndex);

    ifstream file;
    file.open(INDIVIDUAL_MATRIXS + filename);

    ifstream booleanFile;
    booleanFile.open(BOOLEAN_MATRIXS + filename, ios::out);

    vector<vector<Item>> matrix;

    for (int i = 0; i < lines; i++) {
        vector<Item> line;

        for (int j = 0; j < columns; j++) {
            string s;
            file >> s;

            int b;
            booleanFile >> b;

            Item item;
            item.value = s;

            if (b == 0)
                item.explored = false;
            else if (b == 1)
                item.explored = true;
            else
                item.explored = true;

            line.push_back(item);
        }

        matrix.push_back(line);
    }

    file.close();

    return matrix;
}

void File::saveMatrixOnFile(vector<vector<Item>>* matrix, int matrixIndex,
                            int lines, int columns) {
    string filename = generateMatrixFilename(matrixIndex);

    fstream matrixFile;
    matrixFile.open(INDIVIDUAL_MATRIXS + filename, ios::out);

    fstream booleanFile;
    booleanFile.open(BOOLEAN_MATRIXS + filename, ios::out);

    for (int j = 0; j < lines; j++) {
        for (int k = 0; k < columns; k++) {
            matrixFile << (*matrix)[j][k].value << " ";

            if ((*matrix)[j][k].value != "#") {
                if ((*matrix)[j][k].explored)
                    booleanFile << 1 << " ";
                else
                    booleanFile << 0 << " ";
            } else {
                booleanFile << -1 << " ";
            }
        }

        matrixFile << endl;
        booleanFile << endl;
    }

    matrixFile.close();
}

void File::saveAllMatrixOnSeparateFiles(ifstream* file, int numberOfMatrixs,
                                        int lines, int columns) {
    for (int i = 0; i < numberOfMatrixs; i++) {
        string filename = generateMatrixFilename(i + 1);

        fstream matrixFile;
        matrixFile.open(INDIVIDUAL_MATRIXS + filename, ios::out);

        fstream booleanFile;
        booleanFile.open(BOOLEAN_MATRIXS + filename, ios::out);

        for (int j = 0; j < lines; j++) {
            for (int k = 0; k < columns; k++) {
                string s;
                *file >> s;

                matrixFile << s << " ";
                booleanFile << 0 << " ";
            }

            matrixFile << endl;
            booleanFile << endl;
        }
        matrixFile.close();
    }
}

int File::saveOutputFile(int numberOfMatrixs, int lines, int columns) {
    int notExploredCounter = 0;

    fstream output;
    output.open(OUTPUT_DATA, ios::out);

    for (int index = 1; index <= numberOfMatrixs; index++) {
        string filename = generateMatrixFilename(index);

        vector<vector<Item>> matrix = loadMatrixFromFile(index, lines, columns);

        remove((INDIVIDUAL_MATRIXS + filename).c_str());
        remove((BOOLEAN_MATRIXS + filename).c_str());

        for (int i = 0; i < lines; i++) {
            for (int j = 0; j < columns; j++) {
                output << matrix[i][j].value << " ";
                if (!matrix[i][j].explored) notExploredCounter++;
            }

            output << endl;
        }

        output << endl;
    }

    output.close();
    return notExploredCounter;
}