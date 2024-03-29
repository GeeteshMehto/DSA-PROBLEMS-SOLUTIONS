/*
Question Link:- https://leetcode.com/problems/next-greater-node-in-linked-list/description/
*/

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>v;
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
        }

        stack<int>st;
        int i = 0, n = v.size();
        vector<int>result(n ,0);
        while(i < n)
        {
            while(!st.empty() and v[i] > v[st.top()])
            {
                int idx = st.top(); st.pop();
                result[idx] = v[i];
            }
            st.push(i++);
        }
        return result;
    }
};