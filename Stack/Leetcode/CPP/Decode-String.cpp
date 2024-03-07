/*
Question Link:- https://leetcode.com/problems/decode-string/description/
*/

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currentStr;
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(num);
                strStack.push(currentStr);
                currentStr = "";
                num = 0;
            } else if (c == ']') {
                int k = numStack.top();
                numStack.pop();
                string temp = currentStr;
                currentStr = strStack.top();
                strStack.pop();
                for (int i = 0; i < k; ++i) {
                    currentStr += temp;
                }
            } else {
                currentStr += c;
            }
        }

        return currentStr;
    }
};