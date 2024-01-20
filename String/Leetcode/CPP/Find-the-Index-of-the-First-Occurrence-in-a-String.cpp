/*
Question Link:- https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.length();
        int l2 = needle.length();

        if (l2 == 0) {
            return 0;  // Empty needle is always present at index 0.
        }

        for (int i = 0; i <= l1 - l2; i++) {
            if (haystack.substr(i, l2) == needle) {
                return i;  // Found the first occurrence of needle in haystack.
            }
        }

        return -1;  // Needle not found in haystack.
    }
};