/*
Question Link:- https://leetcode.com/problems/majority-element/description/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0]; // Initialize the potential majority element
        int count = 1; // Count of occurrences of potential majority element
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == majority) { // If the current element is equal to potential majority
                count++; // Increment the count
            } else { // If the current element is different
                count--; // Decrement the count
                if (count == 0) { // If count becomes zero, update potential majority
                    majority = nums[i];
                    count = 1;
                }
            }
        }
        
        return majority; // Return the potential majority element
    }
};