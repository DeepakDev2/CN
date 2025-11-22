#include <bits/stdc++.h>
using namespace std;

// Function to perform 1's complement addition of two binary strings
string addBinary(string a, string b) {
    string result = "";
    int carry = 0;

    for (int i = a.size() - 1; i >= 0; i--) {
        int bitA = a[i] - '0';
        int bitB = b[i] - '0';

        int sum = bitA + bitB + carry;
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }

    // If overflow carry -> wrap around
    if (carry == 1) {
        for (int i = result.size() - 1; i >= 0; i--) {
            int bit = (result[i] - '0') + 1;
            result[i] = char(bit % 2 + '0');
            if (bit < 2) break;  // no new carry
        }
    }

    return result;
}

// 1's complement
string onesComplement(string s) {
    for (char &c : s)
        c = (c == '0') ? '1' : '0';
    return s;
}

int main() {
    int n;
    cout << "Enter number of data words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter data words (same length binary strings):\n";
    for (int i = 0; i < n; i++)
        cin >> words[i];

    // Sender Side: Calculate checksum
    string sum = words[0];

    for (int i = 1; i < n; i++)
        sum = addBinary(sum, words[i]);

    string checksum = onesComplement(sum);
    cout << "\nSender side checksum = " << checksum << endl;

    // Now simulate transmission:
    // Receiver gets the same words + checksum
    cout << "\n--- Receiver Side Checking ---\n";
    string receiverSum = words[0];

    for (int i = 1; i < n; i++)
        receiverSum = addBinary(receiverSum, words[i]);

    receiverSum = addBinary(receiverSum, checksum);
    receiverSum = onesComplement(receiverSum);

    cout << "Final result after adding all and complementing: " 
         << receiverSum << endl;

    if (receiverSum.find('1') != string::npos)
        cout << "\nERROR detected in received data!\n";
    else
        cout << "\nNO ERROR detected (data is correct).\n";

    return 0;
}
