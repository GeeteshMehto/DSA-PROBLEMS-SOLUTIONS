/*
Question Link:- https://leetcode.com/problems/3sum/description/
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> finalAns;

        // Sorting the array to make it easier to find unique triplets
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            // Skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a triplet
                    finalAns.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;

                    // Move to the next unique pair
                    ++left;
                    --right;
                } else if (sum < 0) {
                    // Move left pointer to increase the sum
                    ++left;
                } else {
                    // Move right pointer to decrease the sum
                    --right;
                }
            }
        }

        return finalAns;

    }
};