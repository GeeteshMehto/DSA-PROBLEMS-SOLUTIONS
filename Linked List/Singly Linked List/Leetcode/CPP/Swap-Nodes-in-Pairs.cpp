/*
Question Link:- https://leetcode.com/problems/swap-nodes-in-pairs/description/
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
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to facilitate the swapping process
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the next pair
            prev = first;
        }

        return dummy.next;
    }
};