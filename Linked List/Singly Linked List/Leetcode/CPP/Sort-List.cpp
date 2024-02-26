/*
Question Link:- https://leetcode.com/problems/sort-list/description/
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode *slow = head, *fast = head, *prev = nullptr;

        // Find the middle of the linked list
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        prev->next = nullptr;

        // Recursively sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge the sorted halves
        return merge(left, right);
    }

private:
    // Merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        current->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
