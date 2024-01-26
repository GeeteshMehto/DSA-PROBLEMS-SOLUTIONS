/*
Question Link:- https://leetcode.com/problems/valid-parentheses/description/
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                brackets.push(c);
            } else {
                if (brackets.empty()) {
                    return false; // Closing bracket with no matching opening bracket
                }
                char top = brackets.top();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    return false; // Mismatched closing bracket
                }
                brackets.pop(); // Matched closing bracket, remove corresponding opening bracket from stack
            }
        }
        
        return brackets.empty(); // Return true if all brackets are matched
    }
};