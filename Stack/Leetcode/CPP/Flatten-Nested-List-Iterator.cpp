/*
Question Link:- https://leetcode.com/problems/flatten-nested-list-iterator/description/
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    stack<NestedInteger> nodes;

public:
    NestedIterator(vector<NestedInteger>& nestedList) {
        // Push elements from the end to the beginning onto the stack
        for (int i = nestedList.size() - 1; i >= 0; --i) {
            nodes.push(nestedList[i]);
        }
    }

    int next() {
        // Ensure hasNext is called before next
        hasNext();

        // Get the top element and pop it from the stack
        int val = nodes.top().getInteger();
        nodes.pop();
        return val;
    }

    bool hasNext() {
        // Keep popping until we find an integer or the stack is empty
        while (!nodes.empty()) {
            NestedInteger current = nodes.top();
            if (current.isInteger()) {
                return true;
            }
            nodes.pop(); // Remove the list as we've already processed it

            // Push elements from the end to the beginning onto the stack
            vector<NestedInteger>& list = current.getList();
            for (int i = list.size() - 1; i >= 0; --i) {
                nodes.push(list[i]);
            }
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */