// CONGESTION CONTROL ALONE


#include <iostream>
using namespace std;

int main() {
    int cwnd = 8;        // Start from a value above slow start phase
    int ssthresh = 8;    // Reached threshold → now congestion avoidance starts

    cout << "TCP Congestion Avoidance Simulation:\n";
    cout << "-----------------------------------\n";
    cout << "Step\tCWND\n";

    for(int step = 1; step <= 10; step++) {

        cout << step << "\t" << cwnd;

        // Simulate packet loss condition
        if(cwnd >= 14) {
            cout << " <-- Packet Loss! Halving CWND";
            cwnd /= 2; // Like TCP Tahoe/Reno reaction
            cout << " -> New CWND: " << cwnd << endl;
            break;
        }

        // Linear Growth (Additive Increase)
        cwnd += 1;
        cout << " -> After ACK: " << cwnd << endl;
    }

    return 0;
}