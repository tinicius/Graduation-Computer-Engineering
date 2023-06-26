#include <math.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;

int MAX = 13;

vector<int> vetor(MAX, -1);

const int inc = 1024;

int hash2(int key, int it, int max) {
    int value = (key + inc) * it;

    int quad = pow(value, 2);

    string s = to_string(quad);

    if (s.size() % 2 == 0) s += '0';

    string mid;

    int m = s.size() / 2;

    mid += s[m - 1];
    mid += s[m];
    mid += s[m + 1];

    int index = atoi(mid.c_str()) % max;

    return index;
}

int hash_duplo(int key, int max) {
    int index;

    index = key % max;

    int it = 0;

    while (vetor[index] != -1) {
        index = hash2(index, it, max);
        it++;
    }

    return index;
}

int main() {
    int n;

    while (cin >> n) {
        int index = hash_duplo(n, MAX);

        vetor[index] = n;

        for (auto i : vetor) {
            if (i != -1) cout << " ";
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
