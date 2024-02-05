/*
Question Link:- https://leetcode.com/problems/rotate-list/description/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head; // If the list is empty or rotation is unnecessary
        
        int length = 1;
        ListNode* tail = head;
        
        // Find the length of the list and locate its tail
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        
        k = k % length; // Adjust k in case it's larger than the length of the list
        if (k == 0) return head; // If k is a multiple of length, no rotation is needed
        
        ListNode* new_tail = head;
        
        // Move the new_tail to the (length - k)th node
        for (int i = 0; i < length - k - 1; ++i) {
            new_tail = new_tail->next;
        }
        
        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr; // Set the new_tail's next to nullptr to break the list
        
        tail->next = head; // Connect the original tail to the original head to form a cycle
        
        return new_head; // Return the new head of the rotated list
    }
};
