/*
Question Link:- https://leetcode.com/problems/longest-palindromic-substring/description/
*/


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) {
            return s;
        }

        // Create a table to store the results of subproblems
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
        }

        int start = 0; // Starting index of the longest palindrome
        int maxLength = 1; // Length of the longest palindrome

        // Check substrings of length 2
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                isPalindrome[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // Check substrings of length 3 or more
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // Ending index of the substring

                // Check if the current substring is a palindrome
                if (isPalindrome[i + 1][j - 1] && s[i] == s[j]) {
                    isPalindrome[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        }

        // Return the longest palindrome substring
        return s.substr(start, maxLength);
    }

};