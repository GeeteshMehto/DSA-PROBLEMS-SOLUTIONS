/*
Question Link:- https://leetcode.com/problems/count-and-say/description/
*/


class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if (n == 1) {
            return "1";
        }

        // Recursively get the previous term in the sequence
        string prevTerm = countAndSay(n - 1);
        
        string result = "";
        int count = 1;

        // Iterate through the previous term to generate the current term
        for (int i = 0; i < prevTerm.size(); ++i) {
            // Check if the current digit is the same as the next one
            if (i + 1 < prevTerm.size() && prevTerm[i] == prevTerm[i + 1]) {
                count++;
            } else {
                // Append the count and the digit to the result
                result += to_string(count) + prevTerm[i];
                // Reset count for the new digit
                count = 1;
            }
        }

        return result;
    }
};