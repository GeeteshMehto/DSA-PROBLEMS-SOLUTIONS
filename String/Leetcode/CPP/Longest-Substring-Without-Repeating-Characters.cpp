class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0, right = 0;

        while (right < n) {
            // If the character is not in the set, add it and move the right pointer.
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
                right++;
            } else {
                // If the character is in the set, remove the leftmost character and move the left pointer.
                charSet.erase(s[left]);
                left++;
            }
        }

        return maxLength;
    }
};