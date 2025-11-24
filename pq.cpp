// PRIORITY QUEUE


#include <iostream>
using namespace std;

struct Node {
    int data, priority;
};

class PriorityQueue {
    Node arr[10];
    int size;

public:
    PriorityQueue() { size = 0; }

    void push(int data, int priority) {
        arr[size++] = {data, priority};
        cout << "Inserted " << data << " (Priority " << priority << ")\n";
    }

    void pop() {
        if (size == 0) {
            cout << "Queue Empty!\n";
            return;
        }

        int maxIndex = 0;
        for (int i = 1; i < size; i++)
            if (arr[i].priority > arr[maxIndex].priority)
                maxIndex = i;

        cout << "Removed: " << arr[maxIndex].data << " (Priority " << arr[maxIndex].priority << ")\n";

        for (int i = maxIndex; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    void display() {
        cout << "\nQueue: ";
        for (int i = 0; i < size; i++)
            cout << arr[i].data << "(P" << arr[i].priority << ") ";
        cout << "\n";
    }
};

int main() {
    PriorityQueue q;
    q.push(10, 1);
    q.push(50, 3);
    q.push(20, 2);
    q.display();
    q.pop();
    q.display();
}