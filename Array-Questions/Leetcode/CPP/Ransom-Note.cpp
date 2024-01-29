/*
Question Link:- https://leetcode.com/problems/ransom-note/description/
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int charFreq[26] = {0}; // Array to store frequency of characters
        
        // Count frequency of characters in magazine
        for (char ch : magazine) {
            charFreq[ch - 'a']++;
        }
        
        // Check if ransomNote can be constructed
        for (char ch : ransomNote) {
            if (charFreq[ch - 'a'] == 0) {
                return false; // Character not found in magazine or frequency is not enough
            }
            charFreq[ch - 'a']--; // Decrease frequency since this character is used
        }
        
        return true;
    }
};