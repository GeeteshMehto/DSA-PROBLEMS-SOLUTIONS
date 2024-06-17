/*
Question Link:- https://leetcode.com/problems/design-circular-queue/description/
*/


class MyCircularQueue {
private:
    vector<int> data;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        front = -1;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        if (isEmpty())
            front = 0;

        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return data[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        return data[rear];
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};
