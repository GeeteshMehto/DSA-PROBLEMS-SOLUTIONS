/*
Question Link:- https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
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
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node to handle cases where the original head is removed
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        
        while (curr != nullptr) {
            ListNode* next = curr->next;
            bool isDuplicate = false;
            while (next != nullptr && next->val == curr->val) {
                next = next->next;
                isDuplicate = true;
            }
            if (isDuplicate) {
                prev->next = next;
            } else {
                prev = curr;
            }
            curr = next;
        }
        
        return dummy->next;
    }
};
