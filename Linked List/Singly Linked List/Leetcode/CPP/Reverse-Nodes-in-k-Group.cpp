/*
Question Link:- https://leetcode.com/problems/reverse-nodes-in-k-group/description/
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
    ListNode* reverseKGroup(ListNode* head, int k) {

        //base call
    if(head == NULL) {
        return head;
    }
    
    //step1: reverse first k nodes
    ListNode* next = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    int count= 0;

    // check if k nodes are available    
    int check= 0;
    ListNode* Chk = head;
    while( Chk != NULL && check < k ) {
        Chk = Chk->next;
        check++;
    }
    // if not available then return head without reversing
    if(check != k){
        return head;
    }

    // else reverse
    while( curr != NULL && count < k ) {
    next = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next;
    count++;
    }
    
    //step2: Recursive call
    if(next != NULL) {
        head -> next = reverseKGroup(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
        
    }
};