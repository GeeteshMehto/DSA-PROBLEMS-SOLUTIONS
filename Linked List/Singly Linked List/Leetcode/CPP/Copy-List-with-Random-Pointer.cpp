/*
Question Link:- https://leetcode.com/problems/copy-list-with-random-pointer/description/
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/



class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        
        // Create a hashmap to store mapping between original and copied nodes
        std::unordered_map<Node*, Node*> copiedNodes;
        
        // Create a new dummy node to serve as the starting point of the copied list
        Node* dummy = new Node(0);
        Node* current = head;
        Node* newCurrent = dummy;
        
        // First pass: create new nodes and copy values, linking them as next pointers
        while (current) {
            Node* newNode = new Node(current->val);
            copiedNodes[current] = newNode;
            newCurrent->next = newNode;
            newCurrent = newCurrent->next;
            current = current->next;
        }
        
        // Second pass: assign random pointers for new nodes based on mapping
        current = head;
        newCurrent = dummy->next;
        while (current) {
            newCurrent->random = copiedNodes[current->random];
            current = current->next;
            newCurrent = newCurrent->next;
        }
        
        return dummy->next;
    }
};

