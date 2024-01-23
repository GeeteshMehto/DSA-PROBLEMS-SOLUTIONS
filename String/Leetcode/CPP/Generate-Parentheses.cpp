/*
Question Link:- https://leetcode.com/problems/generate-parentheses/description/
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParenthesisHelper(result, "", 0, 0, n);
        return result;
    }

private:
    void generateParenthesisHelper(vector<string>& result, string current, int open, int close, int n) {
        // Base case: If the length of the current string is 2*n, add it to the result
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add an open parenthesis if the count of open parentheses is less than n
        if (open < n) {
            generateParenthesisHelper(result, current + '(', open + 1, close, n);
        }

        // Add a close parenthesis if the count of close parentheses is less than open parentheses
        if (close < open) {
            generateParenthesisHelper(result, current + ')', open, close + 1, n);
        }
    }
};