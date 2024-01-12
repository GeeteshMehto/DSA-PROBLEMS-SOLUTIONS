/*
QUestion link:- https://leetcode.com/problems/3sum-closest/
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Sort the array to simplify the solution
        sort(nums.begin(), nums.end());

        int closestSum = INT_MAX;
        int minDifference = INT_MAX;

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDifference = abs(currentSum - target);

                if (currentDifference < minDifference) {
                    minDifference = currentDifference;
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return closestSum;
    }
};
