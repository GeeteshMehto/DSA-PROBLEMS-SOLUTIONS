/*
Question link:- https://leetcode.com/problems/reverse-linked-list-ii/description/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;
        
        // Create a dummy node to handle the case when left = 1
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        
        // Move prev to the node before the sublist to be reversed
        for (int i = 1; i < left; ++i)
            prev = prev->next;
        
        ListNode* start = prev->next; // The node at position left
        ListNode* then = start->next; // The next node after start
        
        // Reverse the sublist from left to right
        for (int i = 0; i < right - left; ++i) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }
        
        return dummy.next;
    }
};
