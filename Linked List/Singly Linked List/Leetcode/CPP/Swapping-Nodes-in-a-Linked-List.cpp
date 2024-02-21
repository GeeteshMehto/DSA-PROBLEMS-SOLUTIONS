/*
Question Link:- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1); // Dummy node to handle edge cases
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move fast pointer k steps forward
        for (int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        
        ListNode* firstNode = fast; // Store the kth node from the beginning
        
        // Move fast pointer till the end and slow pointer from the start to get kth node from the end
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* secondNode = slow; // Store the kth node from the end
        
        // Swap values of the kth node from the beginning and the kth node from the end
        int temp = firstNode->val;
        firstNode->val = secondNode->val;
        secondNode->val = temp;
        
        return dummy->next; // Return the head of the linked list
    }
};
