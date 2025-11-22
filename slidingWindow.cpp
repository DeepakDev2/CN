// Go Back N

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int total_frames, window_size;

//     cout << "Enter total number of frames: ";
//     cin >> total_frames;

//     cout << "Enter window size: ";
//     cin >> window_size;

//     int sent = 0;  // index of next frame to send

//     while (sent < total_frames) {
//         cout << "\nSender Window: ";

//         // Send frames inside the window
//         for (int i = sent; i < min(sent + window_size, total_frames); i++) {
//             cout << "[" << i << "] ";
//         }
//         cout << endl;

//         // Simulate ACK (user decides which frame failed)
//         int ack;
//         cout << "Enter last ACK received (-1 for no ACK): ";
//         cin >> ack;

//         if (ack == -1) {
//             cout << "Timeout! Resending window...\n";
//         } else if (ack >= sent && ack < sent + window_size) {
//             cout << "ACK received for frame " << ack << endl;
//             sent = ack + 1;  // move sliding window forward
//         } else {
//             cout << "Invalid ACK! Ignoring...\n";
//         }
//     }

//     cout << "\nAll frames sent successfully!\n";
//     return 0;
// }


// Stop and Wait ARQ
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int total_frames;
//     cout << "Enter total number of frames: ";
//     cin >> total_frames;

//     for (int i = 0; i < total_frames; i++) {
//         cout << "Sending Frame " << i << endl;

//         int ack;
//         cout << "Enter ACK for frame " << i << " (1 = OK, 0 = Lost): ";
//         cin >> ack;

//         if (ack == 1) {
//             cout << "ACK received!\n";
//         } else {
//             cout << "Timeout! Resending Frame " << i << endl;
//             i--; // resend same frame
//         }
//     }

//     cout << "All frames transmitted!\n";
// }


// Selective Repeat
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int total, win;
//     cout << "Enter number of frames: ";
//     cin >> total;
//     cout << "Enter window size: ";
//     cin >> win;

//     vector<int> ack(total, 0);
//     int base = 0;

//     while (base < total) {
//         cout << "\nSending frames in window:\n";
//         for (int i = base; i < min(base + win, total); i++)
//             if (!ack[i]) cout << "Sent frame " << i << endl;

//         cout << "\nEnter ACK frame number (-1 for none): ";
//         int a; 
//         cin >> a;

//         if (a >= base && a < base + win) {
//             ack[a] = 1;
//             cout << "ACK received for " << a << endl;

//             while (base < total && ack[base]) base++;
//         } else {
//             cout << "No new ACK.\n";
//         }
//     }

//     cout << "\nAll frames transmitted using Selective Repeat!\n";
//     return 0;
// }
