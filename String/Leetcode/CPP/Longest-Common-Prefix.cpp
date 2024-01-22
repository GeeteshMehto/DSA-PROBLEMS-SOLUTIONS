/*
Question Link:- https://leetcode.com/problems/longest-common-prefix/description/
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return ""; // If the input vector is empty, return an empty string.
        }

        // Iterate through characters in the first string
        for (int i = 0; i < strs[0].size(); ++i) {
            // Check if the character matches in all other strings
            for (int j = 1; j < strs.size(); ++j) {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    // If the character is out of bounds or doesn't match,
                    // return the prefix found so far
                    return strs[0].substr(0, i);
                }
            }
        }

        // If the loop completes, the entire first string is the common prefix
        return strs[0];
    }
};
