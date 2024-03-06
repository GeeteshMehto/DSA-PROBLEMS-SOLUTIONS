/*
Question Link:- https://www.codingninjas.com/studio/problems/queue-using-array-or-singly-linked-list_2099908
*/

#include <bits/stdc++.h> 
class Queue {

    int *arr;
    int front1;
    int rear;
    int size;
public:
    Queue() {
        
        size = 100001;
        arr = new int[size];
        front1 = 0;
        rear = 0;

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return front1==rear;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear==front1){
            return -1;
        }
        else{
            int element = arr[front1];
            arr[front1] = -1;
            front1++;
            if(front1==rear){
                rear=0;
                front1 = 0;
            }
            return element;
        }
    }

    int front() {
        // Implement the front() function
        if(front1==rear){
            return -1;
        }
        else{
            return arr[front1];
        }
        
    }
};