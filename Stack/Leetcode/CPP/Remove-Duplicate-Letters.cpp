/*
Question Link:- https://leetcode.com/problems/remove-duplicate-letters/description/
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        // Initialize a stack to hold the result
        stack<char> stk;
        // Initialize a set to keep track of characters in the result
        unordered_set<char> seen;
        // Initialize a map to keep track of the count of each character in the
        // string
        vector<int> count(26, 0);

        // Count the frequency of each character in the string
        for (char c : s) {
            count[c - 'a']++;
        }

        // Iterate through the string
        for (char c : s) {
            // Decrement the count of current character
            count[c - 'a']--;

            // If the character is already in the result, skip it
            if (seen.find(c) != seen.end()) {
                continue;
            }

            // Pop characters from the stack if they are greater than the
            // current character and there are more occurrences of them later in
            // the string
            while (!stk.empty() && stk.top() > c &&
                   count[stk.top() - 'a'] > 0) {
                seen.erase(stk.top());
                stk.pop();
            }

            // Add the current character to the result
            stk.push(c);
            seen.insert(c);
        }

        // Construct the result string
        string result = "";
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }

        return result;
    }
};