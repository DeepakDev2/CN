// AIMD

#include <iostream>
using namespace std;

int main() {
    int cwnd = 1;   // initial congestion window size
    int threshold = 8; // congestion threshold for simulation

    cout << "AIMD Simulation:\n";
    cout << "-------------------------------------------\n";
    cout << "Step\tState\t\tCWND\n";

    for(int step = 1; step <= 20; step++) {

        // Random simulation of packet loss (occurs when cwnd exceeds threshold)
        if(cwnd >= threshold) {
            cout << step << "\tLoss Detected\t" << cwnd;
            cwnd /= 2; // Multiplicative decrease
            cout << " -> " << cwnd << endl;
        } 
        else {
            cout << step << "\tAdditive Inc\t" << cwnd;
            cwnd += 1; // Additive increase
            cout << " -> " << cwnd << endl;
        }
    }

    return 0;
}