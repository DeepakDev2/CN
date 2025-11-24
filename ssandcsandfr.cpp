// CONGESTION + SLOW START + FAST RECOVERY


#include <iostream>
using namespace std;

int main() {
    int cwnd = 1;            // initial congestion window
    int ssthresh = 16;       // slow start threshold
    int dupAck = 0;          // duplicate ACK counter

    cout << "TCP Reno Simulation (Slow Start + Congestion Avoidance + Fast Recovery)\n";
    cout << "---------------------------------------------------------------------\n";

    for(int step = 1; step <= 20; step++) {
        
        cout << "\nStep " << step << " | CWND = " << cwnd << " | ssthresh = " << ssthresh;

        // Simulate packet loss event when cwnd reaches 20 (for example)
        if(cwnd >= 20) {
            cout << "\n>>> Packet Loss Detected! Triggering Duplicate ACKs...\n";
            dupAck++;
        }

        // Fast retransmit triggered after 3 duplicate ACKs
        if(dupAck == 3) {
            cout << ">>> FAST RETRANSMIT triggered!";
            ssthresh = cwnd / 2;
            cwnd = ssthresh + 3;
            cout << "\nNew ssthresh = " << ssthresh;
            cout << "\nEntering Fast Recovery with CWND = " << cwnd;
            continue;
        }

        // During fast recovery (dup ack > 3)
        if(dupAck > 3) {
            cwnd++;
            cout << "\nFast Recovery ongoing: CWND increased to " << cwnd;
            continue;
        }

        // If recovery ended (normal ACK)
        if(dupAck >= 3) {
            cout << "\nRecovery complete → switching to Congestion Avoidance";
            cwnd = ssthresh;
            dupAck = 0;
        }

        // NORMAL TCP OPERATION:
        if(cwnd < ssthresh) {
            // SLOW START → exponential growth
            cwnd *= 2;
            cout << "\nSlow Start: CWND doubled to " << cwnd;
        } else {
            // CONGESTION AVOIDANCE → linear growth
            cwnd += 1;
            cout << "\nCongestion Avoidance: CWND increased to " << cwnd;
        }
    }

    return 0;
}