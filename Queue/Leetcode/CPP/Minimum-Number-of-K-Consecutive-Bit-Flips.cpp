/*
Question Link:- https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
*/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;
        queue<int> flipQueue; // Queue to keep track of flipped indices

        for (int i = 0; i < n; ++i) {
            if (!flipQueue.empty() && i >= flipQueue.front() + k) {
                flipQueue.pop(); // Remove outdated flip indices
            }

            // If the current element needs to be flipped
            if ((nums[i] + flipQueue.size()) % 2 == 0) {
                // If we can't flip the window anymore
                if (i + k > n) {
                    return -1;
                }
                flipQueue.push(i);
                ++flips;
            }
        }

        return flips;
    }
};