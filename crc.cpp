// CRC

#include <iostream>
using namespace std;

// XOR operation (ignoring the first bit)
string XOR(string a, string b) {
    string result = "";
    for (int i = 1; i < a.size(); i++)
        result += (a[i] == b[i] ? '0' : '1');
    return result;
}

string computeCRC(string data, string generator) {
    int genLen = generator.length();
    
    // Append zeros (generator length - 1)
    string appended = data + string(genLen - 1, '0');
    string temp = appended.substr(0, genLen);

    int index = genLen;
    while (index < appended.length()) {
        if (temp[0] == '1')
            temp = XOR(temp, generator) + appended[index];
        else
            temp = XOR(temp, string(genLen, '0')) + appended[index];
        index++;
    }

    // Final XOR
    if (temp[0] == '1')
        temp = XOR(temp, generator);
    else
        temp = XOR(temp, string(genLen, '0'));

    return temp;  // remainder
}

int main() {
    string data, generator;
    cout << "Enter data bits: ";
    cin >> data;
    cout << "Enter generator polynomial: ";
    cin >> generator;

    string crc = computeCRC(data, generator);
    cout << "CRC: " << crc << endl;
    cout << "Transmitted frame: " << data + crc << endl;

    return 0;
}