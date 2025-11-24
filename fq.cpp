// FAIR QUEUING


#include <iostream>
using namespace std;

#define FLOWS 3
#define SIZE 5

int main() {
    int queues[FLOWS][SIZE] = {
        {1, 2, 3, -1, -1},
        {10, 20, -1, -1, -1},
        {100, 200, 300, 400, -1}
    };

    int index[FLOWS] = {0, 0, 0};
    bool done;

    cout << "\nFair Queue Transmission Order:\n";

    do {
        done = true;

        for (int i = 0; i < FLOWS; i++) {
            if (queues[i][index[i]] != -1) {
                cout << queues[i][index[i]] << " ";
                index[i]++;
                done = false;
            }
        }

    } while (!done);

    cout << "\n";
    return 0;
}