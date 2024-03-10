/*
Question Link:- https://leetcode.com/problems/implement-stack-using-queues/description/
*/

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
    
public:
    MyStack() {
        
    }
    
    // Push element x onto stack.
    void push(int x) {
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Push the new element to q1
        q1.push(x);
        // Move all elements back to q1 from q2
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    // Removes the element on top of the stack and returns that element.
    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }
    
    // Get the top element.
    int top() {
        return q1.front();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};