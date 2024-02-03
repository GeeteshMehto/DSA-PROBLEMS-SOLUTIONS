/*
Question Link:- https://www.codingninjas.com/studio/problems/reverse-list-in-k-groups_983644
*/

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    //base call
    if(head == NULL) {
        return head;
    }
    
    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count= 0;

    // check if k nodes are available    
    int check= 0;
    Node* Chk = head;
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
        head -> next = kReverse(next,k);
    }
    
    //step3: return head of reversed list
    return prev;
}