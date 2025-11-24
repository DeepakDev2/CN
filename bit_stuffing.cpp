// BIT STUFFING


#include <iostream>
using namespace std;

string bitStuff(string data) {
    string result = "";
    int count = 0;

    for (char bit : data) {
        result += bit;

        if (bit == '1') {
            count++;
        } else {
            count = 0;
        }

        // After 5 consecutive 1s, insert a 0
        if (count == 5) {
            result += '0';
            count = 0;
        }
    }
    return result;
}

int main() {
    string data;
    cout << "Enter binary data: ";
    cin >> data;

    string stuffed = bitStuff(data);
    cout << "Stuffed data: " << stuffed << endl;

    return 0;
}