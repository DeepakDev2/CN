// STOP AND WAIT


#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int totalFrames;
    cout << "Enter number of frames to send: ";
    cin >> totalFrames;

    int frame = 0;

    while (frame < totalFrames) {
        cout << "\nSending Frame: " << frame << endl;

        // Simulating ACK loss or frame success
        int random = rand() % 2; // 0 = lost, 1 = received

        if (random == 1) {
            cout << "ACK received for Frame " << frame << endl;
            frame++; // move to next frame
        } 
        else {
            cout << "ACK lost! Resending Frame " << frame << endl;
            // frame not incremented → resend
        }
    }

    cout << "\nAll frames sent successfully!" << endl;
    return 0;
}