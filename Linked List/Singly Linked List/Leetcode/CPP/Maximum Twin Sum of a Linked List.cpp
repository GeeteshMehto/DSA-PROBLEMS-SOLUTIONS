/*
Question Link:- https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        int ans = 0, len = 0;
        vector<int> vals;

        while (head) {
            len++;
            vals.push_back(head->val);
            head = head->next;
        }
        
        for (int i = 0; i < len / 2; ++i) {
            ans = max(ans, vals[i] + vals[len - i - 1]);
        }
        
        return ans;
    }
};