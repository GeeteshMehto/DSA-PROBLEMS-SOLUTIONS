/*
Question Link:- https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/
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
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *prev = NULL, *first = head, *second = head -> next;
        while(true){
            first -> next=prev;
            prev = first;
            first = second;
            if(first == NULL)
                break;
            second = first -> next;
        }
        return prev;
    }
    
    ListNode* doubleIt(ListNode* head) {
        ListNode *ptr = reverseLL(head);
        ListNode *prev = new ListNode(), *h = prev;
        int carry = 0;
        while(carry || ptr != NULL){
            int value = 0;
            if(ptr){
                value = ptr->val * 2;
                ptr = ptr -> next;
            }
            value += carry;
            carry = value / 10;
            ListNode *node = new ListNode(value % 10);
            prev -> next= node;
            prev = prev -> next;
        }
        ListNode *ans = reverseLL(h -> next);
        return ans;
    }
};