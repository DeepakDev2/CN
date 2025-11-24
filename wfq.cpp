// WEIGHTED FAIR QUEUING

#include <iostream>
using namespace std;

#define FLOWS 3

int main() {
    int flows[FLOWS][5] = {
        {1, 2, 3, -1, -1},      // Flow 0
        {10, 20, -1, -1, -1},   // Flow 1
        {100, 200, 300, 400, -1} // Flow 2
    };

    int weight[FLOWS] = {1, 2, 3}; // Flow 2 gets most chance
    int index[FLOWS] = {0,0,0};

    cout << "\nWeighted Fair Queue Transmission Order:\n";

    bool done;
    do {
        done = true;
        for (int i = 0; i < FLOWS; i++) {
            for (int w = 0; w < weight[i]; w++) {
                if (flows[i][index[i]] != -1) {
                    cout << flows[i][index[i]] << " ";
                    index[i]++;
                    done = false;
                }
            }
        }
    } while (!done);

    return 0;
}