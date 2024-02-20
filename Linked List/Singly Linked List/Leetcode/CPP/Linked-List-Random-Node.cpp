/*
Question Link:- https://leetcode.com/problems/linked-list-random-node/description/
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
private:
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
        srand(time(nullptr)); // Seed for random number generation
    }
    
    int getRandom() {
        ListNode* current = head;
        int chosenValue = current->val;
        int count = 1;
        
        while (current != nullptr) {
            // With probability 1/count, replace the chosen value
            if (rand() % count == 0) {
                chosenValue = current->val;
            }
            count++;
            current = current->next;
        }
        
        return chosenValue;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */