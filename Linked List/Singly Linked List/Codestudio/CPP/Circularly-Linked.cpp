/*
Question Link:- https://www.codingninjas.com/studio/problems/circularly-linked_1070232
*/

#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/
bool isCircular(Node* head){

    if(head==NULL){
        return true;
    }

    Node*slow=head,*fast=head;

    while(fast && fast->next){
        slow=slow->next;

        fast=fast->next->next;

        if(slow==fast){
            if(slow==head){
                return true;
            }
            else{
                return false;
            }
        }
    }

    return false;

}