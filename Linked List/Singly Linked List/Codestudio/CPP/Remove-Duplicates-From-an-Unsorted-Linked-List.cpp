/*
Question Link:- https://www.codingninjas.com/studio/problems/remove-duplicates-from-unsorted-linked-list_1069331
*/


Node* removeDuplicates(Node* head) {
    if (head == NULL)
        return NULL; // Return nullptr if the list is empty

    unordered_set<int> seen_values;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (seen_values.find(curr->data) != seen_values.end()) {
            // If the current data is a duplicate, remove the node
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            // If it's not a duplicate, update seen_values and move forward
            seen_values.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}