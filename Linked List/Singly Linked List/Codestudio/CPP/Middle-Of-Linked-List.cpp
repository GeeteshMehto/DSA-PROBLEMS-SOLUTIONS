/*
Question Link:- https://www.codingninjas.com/studio/problems/middle-of-linked-list_973250
*/

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node *findMiddle(Node *head) {
    if (head == NULL)  // Check if the list is empty
        return NULL;

    Node* slow = head;    // Slow pointer moves one node at a time
    Node* fast = head;    // Fast pointer moves two nodes at a time

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          // Move slow pointer one step
        fast = fast->next->next;    // Move fast pointer two steps
    }

    return slow;    // When fast pointer reaches end, slow pointer will be at the middle
}


