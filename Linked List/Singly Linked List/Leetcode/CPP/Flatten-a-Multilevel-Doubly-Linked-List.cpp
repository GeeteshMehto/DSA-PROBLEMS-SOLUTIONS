/*
Question Link:- https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr; // Base case
        
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                Node* nextNode = curr->next; // Store the next node
                Node* childTail = flatten(curr->child); // Flatten child sublist and get its tail
                curr->next = curr->child; // Connect current node to child sublist
                curr->child->prev = curr; // Set previous pointer of child sublist
                curr->child = nullptr; // Reset child pointer
                
                if (nextNode) {
                    while (childTail->next) {
                        childTail = childTail->next;
                    }
                    childTail->next = nextNode; // Connect child tail to next node
                    nextNode->prev = childTail; // Set previous pointer of next node
                }
                curr = nextNode; // Move current pointer to next node after the flattened sublist
            } else {
                curr = curr->next; // Move current pointer to next node
            }
        }
        return head;
    }
};