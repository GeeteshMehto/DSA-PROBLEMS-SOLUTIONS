/*
Question Link:- https://leetcode.com/problems/linked-list-cycle-ii/description/
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *tortoise = head;
        ListNode *hare = head;

        // Phase 1: Detect cycle
        while (hare != nullptr && hare->next != nullptr) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if (tortoise == hare) { // Cycle detected
                break;
            }
        }

        // No cycle found
        if (hare == nullptr || hare->next == nullptr) {
            return nullptr;
        }

        // Phase 2: Find the start of the cycle
        tortoise = head;
        while (tortoise != hare) {
            tortoise = tortoise->next;
            hare = hare->next;
        }

        return hare; // or tortoise, since they meet at the start of the cycle
    }
};