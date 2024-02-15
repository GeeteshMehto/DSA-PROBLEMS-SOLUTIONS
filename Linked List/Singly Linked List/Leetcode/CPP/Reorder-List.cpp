/*
Question Link:- https://leetcode.com/problems/reorder-list/description/
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
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return;
        
        // Step 1: Find the middle of the linked list
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse the second half of the linked list
        ListNode *prev = nullptr, *curr = slow->next, *nextNode;
        slow->next = nullptr;
        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        // Step 3: Merge the first half with the reversed second half
        ListNode *first = head, *second = prev;
        while (second != nullptr) {
            ListNode *temp1 = first->next;
            ListNode *temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
