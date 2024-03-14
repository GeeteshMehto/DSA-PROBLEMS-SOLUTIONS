/*
Question Link:- https://leetcode.com/problems/maximum-sum-circular-subarray/description/
*/

class Solution {
public:
    int maxSubarraySumCircular(std::vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();

        // Calculate the total sum of all elements in the array
        for (int num : nums) {
            total_sum += num;
        }

        // Initialize variables to track maximum and minimum subarray sums
        int max_sum = nums[0];
        int min_sum = nums[0];
        int current_max = nums[0];
        int current_min = nums[0];

        // Initialize pointers for sliding window
        int max_start = 0;
        int min_start = 0;

        // Traverse the array to find maximum and minimum subarray sums
        for (int i = 1; i < n; ++i) {
            // Update maximum subarray sum
            if (current_max > 0) {
                current_max += nums[i];
            } else {
                current_max = nums[i];
                max_start = i;
            }
            if (current_max > max_sum) {
                max_sum = current_max;
            }

            // Update minimum subarray sum
            if (current_min < 0) {
                current_min += nums[i];
            } else {
                current_min = nums[i];
                min_start = i;
            }
            if (current_min < min_sum) {
                min_sum = current_min;
            }
        }

        // Calculate the maximum circular subarray sum
        int max_circular_sum = std::max(total_sum - min_sum, max_sum);

        // If all elements are negative, return the maximum straight subarray
        // sum
        if (max_circular_sum == 0) {
            return max_sum;
        }

        return max_circular_sum;
    }
};