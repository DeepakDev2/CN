// FIFO
// 

#include <iostream>
using namespace std;

#define SIZE 5   // Max size of FIFO

class FIFO {
    int arr[SIZE];
    int front, rear;

public:
    FIFO() {
        front = 0;
        rear = -1;
    }

    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full! Cannot insert " << value << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        cout << value << " inserted." << endl;
    }

    void dequeue() {
        if (front > rear) {
            cout << "Queue is empty! Nothing to delete." << endl;
            return;
        }
        cout << "Removed: " << arr[front] << endl;
        front++;
    }

    void display() {
        if (front > rear) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "FIFO Order: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    FIFO q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);  // Overflow
    q.display();

    return 0;
}