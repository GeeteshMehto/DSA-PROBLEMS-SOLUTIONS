/*
Question Link:- https://leetcode.com/problems/merge-k-sorted-lists/description/
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
public:
    struct Compare {
        bool operator()(const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
        
        // Push the head of each list into the minHeap
        for (ListNode* list : lists) {
            if (list)
                minHeap.push(list);
        }
        
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        // Pop the smallest node from the minHeap and add it to the merged list
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();
            tail->next = smallest;
            tail = tail->next;
            if (smallest->next)
                minHeap.push(smallest->next);
        }
        
        return dummy.next;
    }
};