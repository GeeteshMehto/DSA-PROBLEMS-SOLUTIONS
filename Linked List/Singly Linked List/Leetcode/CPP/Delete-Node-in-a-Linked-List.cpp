/*
Question Link:- https://leetcode.com/problems/delete-node-in-a-linked-list/description/
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Ensure that the given node is not the last node
        if (node == nullptr || node->next == nullptr)
            return;
        
        // Copy the value of the next node to the current node
        node->val = node->next->val;
        
        // Delete the next node
        ListNode* temp = node->next;
        node->next = node->next->next;
        delete temp;
    }
};
