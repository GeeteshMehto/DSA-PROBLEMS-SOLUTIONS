/*
Question Link:- https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/
*/


class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr; // No middle node to delete

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now 'slow' points to the middle node
        // 'prev' points to the node before the middle node

        if (prev != nullptr)
            prev->next = slow->next; // Removing the middle node
        delete slow;                 // Freeing memory of the middle node

        return head;
    }
};
