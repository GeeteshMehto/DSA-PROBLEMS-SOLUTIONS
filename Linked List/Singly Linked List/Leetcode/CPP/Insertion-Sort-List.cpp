/*
Question Link:- https://leetcode.com/problems/insertion-sort-list/description/
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
            return head; // If the list is empty or has only one node, it is
                         // already sorted

        ListNode* sortedHead =
            new ListNode(INT_MIN); // Dummy node for the sorted list
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // Store the next node before
                                             // removing curr from original list
            ListNode* prev = sortedHead;

            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next; // Traverse the sorted list to find the
                                   // insertion position
            }

            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode; // Move to the next node in the original list
        }

        ListNode* sortedList = sortedHead->next;
        delete sortedHead; // Free dummy node
        return sortedList;
    }
};