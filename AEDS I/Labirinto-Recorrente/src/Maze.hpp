#ifndef MAZE_HPP
#define MAZE_HPP

#include <random>
#include <set>
#include <vector>

#include "File.hpp"

#define START_MATRIX 1

using namespace std;

class Maze {
   private:
    int lines;            // Número de linhas em cada matrix
    int columns;          // Número de colunas em cada matrix
    int numberOfMatrixs;  // Número de matrizes

    int startLine;
    int startColumn;

    int life;                // Vida do jogador
    int bag;                 // Items na bolsa
    int itemsCounter;        // Total de items coletados ao longo do caminho
    int dangersCounter = 0;  // Total de perigos encontrados ao longo do caminho
    bool collectedItem;      // Marcador para saber se passou por posições
                             // diferentes de zero
    int positionsCounter;

    vector<vector<Item>> matrix;  // Matrix atual na memória
    int line;                     // Linha atual na matrix
    int column;                   // Coluna atual na matrix
    int matrixIndex;              // Index da matriz atual
    set<int> exploredMatrixes;    // Indexs das matrizes que foram percorridas

    File file;

    // Gera um inteiro entre os limites min e max, inclusivo
    int randomInteger(int min, int max);

    pair<int, int> randomMove();  // Função que gera o próximo passo

    pair<int, int> teleportBack();  // Muda para matriz anterior
    pair<int, int> teleportNext();  // Muda para próxima matriz

    void changeMatrix(int newMatrixIndex);  // Salva o estado da matriz atual e
                                            // carrega uma outra
    void
    checkPosition();  // Verifica a posição atual e faz a ação correspondente

   public:
    Maze();
    Maze(int startLine, int startColumn);

    bool verifyStartPosition(
        int startLine,
        int startColumn);  // Verifica se a posição inicial é válida
    void play();           // Roda o programa principal
    void review();         // Mostra as estatisticas do jogo
};

#endif