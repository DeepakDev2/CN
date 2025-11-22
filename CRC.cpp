#include <bits/stdc++.h>
using namespace std;

// XOR operation for strings
string xorOperation(string a, string b) {
    string result = "";
    for (int i = 1; i < b.size(); i++) {
        result += (a[i] == b[i]) ? '0' : '1';
    }
    return result;
}

// Performs CRC Division
string crcDivision(string dividend, string divisor) {
    int pick = divisor.size();
    string temp = dividend.substr(0, pick);

    while (pick < dividend.size()) {
        if (temp[0] == '1') 
            temp = xorOperation(temp, divisor) + dividend[pick];
        else 
            temp = xorOperation(temp, string(pick, '0')) + dividend[pick];
        pick++;
    }

    // Final step
    if (temp[0] == '1')
        temp = xorOperation(temp, divisor);
    else
        temp = xorOperation(temp, string(pick, '0'));

    return temp; // remainder
}

int main() {
    string data, generator;
    cout << "Enter data: ";
    cin >> data;
    cout << "Enter generator polynomial: ";
    cin >> generator;

    int m = generator.size() - 1;

    // Append m zeros to data
    string appendedData = data + string(m, '0');

    cout << "\nAppended Data = " << appendedData << endl;

    // Compute CRC remainder
    string remainder = crcDivision(appendedData, generator);
    cout << "CRC Remainder = " << remainder << endl;

    // Transmitted frame = data + remainder
    string codeword = data + remainder;
    cout << "Transmitted Codeword = " << codeword << endl;

    // Receiver side checking
    cout << "\n--- Receiver Side Check ---\n";
    string recvRemainder = crcDivision(codeword, generator);
    cout << "Syndrome = " << recvRemainder << endl;

    if (recvRemainder.find('1') != string::npos)
        cout << "Error Detected in Transmission!\n";
    else
        cout << "No Error Detected. Transmission Successful.\n";

    return 0;
}

// Enter data: 1101011011
// Enter generator polynomial: 10011
// Appended Data = 11010110110000
// CRC Remainder = 1000
// Transmitted Codeword = 11010110111000

// --- Receiver Side Check ---
// Syndrome = 0000
// No Error Detected. Transmission Successful.
