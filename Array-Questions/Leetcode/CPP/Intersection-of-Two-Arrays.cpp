/*
Question Link:- https://leetcode.com/problems/intersection-of-two-arrays/description/
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        // Sort both arrays
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());



        // Find intersection
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // Found a common element
                result.push_back(nums1[i]);

                // Move to the next unique elements in both arrays
                while (i < nums1.size() && nums1[i] == result.back()) {
                    i++;
                }

                while (j < nums2.size() && nums2[j] == result.back()) {
                    j++;
                }
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
            
    }
};