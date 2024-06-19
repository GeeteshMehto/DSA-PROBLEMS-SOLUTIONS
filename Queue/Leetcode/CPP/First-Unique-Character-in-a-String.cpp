/*
Question Link:- https://leetcode.com/problems/first-unique-character-in-a-string/description/
*/


class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> freqMap;

        // Count frequency of characters
        for (char c : s) {
            freqMap[c]++;
        }

        // Find the first character with frequency 1
        for (int i = 0; i < s.length(); ++i) {
            if (freqMap[s[i]] == 1) {
                return i;
            }
        }

        // If no such character found
        return -1;
    }
};
