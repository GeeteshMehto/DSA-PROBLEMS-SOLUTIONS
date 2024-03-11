/*
Question Link:- https://leetcode.com/problems/implement-queue-using-stacks/description/
*/

class MyQueue {
private:
    stack<int> inStack; // Stack for enqueue operation
    stack<int> outStack; // Stack for dequeue operation

    // Move elements from inStack to outStack
    void moveElements() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    MyQueue() {}

    // Push element to the back of the queue
    void push(int x) {
        inStack.push(x);
    }

    // Removes the element from the front of the queue and returns it
    int pop() {
        if (outStack.empty()) {
            moveElements(); // Move elements to outStack if it's empty
        }
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    // Returns the element at the front of the queue
    int peek() {
        if (outStack.empty()) {
            moveElements(); // Move elements to outStack if it's empty
        }
        return outStack.top();
    }

    // Returns true if the queue is empty, false otherwise
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};
