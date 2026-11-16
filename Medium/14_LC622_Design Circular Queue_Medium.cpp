#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        arr.resize(k);
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;

        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % capacity;
        size--;

        return true;
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularQueue q(3);

    cout << q.enQueue(10) << endl;
    cout << q.enQueue(20) << endl;
    cout << q.enQueue(30) << endl;

    cout << q.Rear() << endl;
    cout << q.isFull() << endl;

    q.deQueue();

    cout << q.enQueue(40) << endl;
    cout << q.Rear() << endl;

    return 0;
}
