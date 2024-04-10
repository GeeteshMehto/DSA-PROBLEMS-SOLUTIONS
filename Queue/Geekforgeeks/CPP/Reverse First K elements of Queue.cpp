/*
Question Link:- https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
*/

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int> st;
        
        for(int i=0; i<k; i++){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        int t = q.size() - k;
        
        while(t--){
            int val = q.front();
            q.pop();
            q.push(val);
        }
        
        return q;
    }
};