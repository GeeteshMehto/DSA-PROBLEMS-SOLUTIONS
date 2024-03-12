/*
Question Link:- https://leetcode.com/problems/sliding-window-maximum/description/
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> window; // deque to store indices of elements in the current window

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices that are outside the current window
            while (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }

            // Remove indices of elements smaller than the current element from
            // the back
            while (!window.empty() && nums[window.back()] < nums[i]) {
                window.pop_back();
            }

            // Add the current index to the window
            window.push_back(i);

            // If the window has reached its full size, add the maximum element
            // to the result
            if (i >= k - 1) {
                result.push_back(nums[window.front()]);
            }
        }

        return result;
    }
};