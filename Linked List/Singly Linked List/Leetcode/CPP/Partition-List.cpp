/*
Question Link:- https://leetcode.com/problems/partition-list/description/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(); // Head of the list containing nodes less than x
        ListNode* lessTail = lessHead; // Tail of the list containing nodes less than x
        ListNode* greaterEqualHead = new ListNode(); // Head of the list containing nodes greater than or equal to x
        ListNode* greaterEqualTail = greaterEqualHead; // Tail of the list containing nodes greater than or equal to x
        
        while (head != nullptr) {
            if (head->val < x) {
                lessTail->next = head;
                lessTail = lessTail->next;
            } else {
                greaterEqualTail->next = head;
                greaterEqualTail = greaterEqualTail->next;
            }
            head = head->next;
        }
        
        // Connect the two lists
        greaterEqualTail->next = nullptr; // Terminate the list of nodes greater than or equal to x
        lessTail->next = greaterEqualHead->next; // Connect the end of the list of nodes less than x to the start of the other list
        
        // Return the head of the merged list
        return lessHead->next;
    }
};