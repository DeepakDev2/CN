// SLOW START ALONE

#include <iostream>
using namespace std;

int main() {
    int cwnd = 1;            // initial congestion window
    int ssthresh = 16;       // threshold where slow start stops

    cout << "TCP Slow Start Simulation:\n";
    cout << "------------------------------\n";
    cout << "Step\tCWND\n";

    for(int step = 1; step <= 10; step++) {

        cout << step << "\t" << cwnd;

        // Check if cwnd reached threshold (simulated loss or congestion)
        if(cwnd >= ssthresh) {
            cout << "  <-- Loss detected, switch to Congestion Avoidance";
            cwnd /= 2;   // halve the window like in TCP Tahoe
            cout << " -> New CWND: " << cwnd;
            break;
        }

        // Exponential growth (slow start)
        cwnd *= 2;
        cout << " -> After ACK: " << cwnd << endl;
    }

    return 0;
}