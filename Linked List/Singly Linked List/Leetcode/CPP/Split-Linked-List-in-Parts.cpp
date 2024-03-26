/*
Question Link:- https://leetcode.com/problems/split-linked-list-in-parts/description/
*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Calculate the length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        // Determine the size of each part and the remainder
        int partSize = length / k;
        int remainder = length % k;

        // Create the result array
        vector<ListNode*> result(k, nullptr);

        // Iterate through the linked list to split it into parts
        current = head;
        for (int i = 0; i < k && current != nullptr; i++) {
            result[i] = current;
            int currentPartSize = partSize + (i < remainder ? 1 : 0);
            for (int j = 0; j < currentPartSize - 1; j++) {
                current = current->next;
            }
            ListNode* nextNode = current->next;
            current->next = nullptr;
            current = nextNode;
        }

        return result;
    }
};