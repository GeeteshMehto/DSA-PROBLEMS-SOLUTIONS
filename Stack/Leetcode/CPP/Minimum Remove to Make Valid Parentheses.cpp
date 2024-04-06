/*
Question link:- https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses
*/


class Solution {
public:
    std::string minRemoveToMakeValid(std::string s) {
        int leftCount = 0;
        int rightCount = 0;
        stack<char> stack;

        // Pass 1
        for (char ch : s) {
            if (ch == '(') {
                leftCount++;
            } else if (ch == ')') {
                rightCount++;
            }
            if (rightCount > leftCount) {
                rightCount--;
                continue;
            } else {
                stack.push(ch);
            }
        }

        std::string result = "";
        
        // Pass 2
        while (!stack.empty()) {
            char currentChar = stack.top();
            stack.pop();
            if (leftCount > rightCount && currentChar == '(') {
                leftCount--;
            } else {
                result += currentChar;
            }
        }

        // Reverse the result string
        reverse(result.begin(), result.end());
        return result;
    }
};