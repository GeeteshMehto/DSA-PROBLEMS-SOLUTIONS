/*
Question Link:- https://www.codingninjas.com/studio/problems/interview-shuriken-42-detect-and-remove-loop_241049
*/

/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node* floyd(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow; // Loop detected
        }
    }
    return NULL; // No loop
}

Node* getStartingNode(Node* head) {
    Node* intersection = floyd(head);
    if (intersection == NULL) {
        return NULL; // No loop
    }

    Node* start = head;
    while (start != intersection) {
        start = start->next;
        intersection = intersection->next;
    }
    return start; // Start of the loop
}

Node* removeLoop(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* startOfLoop = getStartingNode(head);
    if (startOfLoop == NULL) {
        return head; // No loop to remove
    }

    Node* temp = startOfLoop;
    while (temp->next != startOfLoop) {
        temp = temp->next;
    }
    temp->next = NULL; // Remove the loop
    return head;
}