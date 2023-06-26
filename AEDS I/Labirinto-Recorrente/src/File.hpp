#ifndef FILE_HPP
#define FILE_HPP

#include "Item.hpp"

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <vector>

#define INPUT_DATA "./dataset/input.data"
#define OUTPUT_DATA "./dataset/output.data"
#define INDIVIDUAL_MATRIXS "./dataset/i"
#define BOOLEAN_MATRIXS "./dataset/b"

using namespace std;

class File {
   public:
    void readLinesColumnsNumberAndSaveMatrix(int* lines, int* columns,
                                             int* numberOfMatrixs);

    vector<vector<Item>> loadMatrixFromFile(int matrixIndex, int lines,
                                            int columns);

    void saveMatrixOnFile(vector<vector<Item>>* matrix, int matrixIndex,
                          int lines, int columns);

    void saveAllMatrixOnSeparateFiles(ifstream* file, int numberOfMatrixs,
                                      int lines, int columns);

    string generateMatrixFilename(int matrixIndex);

    int saveOutputFile(int numberOfMatrixs, int lines, int columns);
};

#endif