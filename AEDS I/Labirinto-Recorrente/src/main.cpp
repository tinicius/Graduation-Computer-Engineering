#include <chrono>

#include "Maze.hpp"

int main() {
    auto start = chrono::high_resolution_clock::now();

    int startLine, startColumn;

    cout << "Digite uma posição inicial" << endl;
    cout << "Linha: ";
    cin >> startLine;
    cout << "Coluna: ";
    cin >> startColumn;

    Maze maze(startLine, startColumn);

    maze.play();
    maze.review();

    auto end = chrono::high_resolution_clock::now();

    double time_ms =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_ms *= 1e-9;

    cout << "--------------" << endl;
    cout << "Tempo de execução: " << fixed << time_ms;
    cout << " s" << endl;

    return 0;
}