/*
Question Link:- https://www.codingninjas.com/studio/problems/unique-sorted-list_2420283
*/

/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node *removeDuplicates(Node *head) {
    if (head == NULL || head->next == NULL) {
        return head; 
    }

    Node *current = head;

    while (current->next != NULL) {
        if (current->data == current->next->data) { 
            Node *temp = current->next;
            current->next = current->next->next;
            if (current->next != NULL){
                current->next->prev = current;
            } 
                 
            delete temp;
        }
        else {
            current = current->next;
        } 
    }

    return head;
}

