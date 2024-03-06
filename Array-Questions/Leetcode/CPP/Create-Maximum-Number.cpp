/*
Question Link:- https://leetcode.com/problems/create-maximum-number/
*/


class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> result;

        for (int i = max(0, k - n); i <= min(k, m); ++i) {
            vector<int> candidate = merge(maxNumberFromOneArray(nums1, i),
                                          maxNumberFromOneArray(nums2, k - i));
            if (greater(candidate, 0, result, 0))
                result = move(candidate);
        }

        return result;
    }

private:
    vector<int> maxNumberFromOneArray(vector<int>& nums, int k) {
        vector<int> result;
        int drop = nums.size() - k;

        for (int num : nums) {
            while (drop > 0 && !result.empty() && result.back() < num) {
                result.pop_back();
                drop--;
            }
            result.push_back(num);
        }

        result.resize(k);
        return result;
    }

    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        vector<int> result;
        auto it1 = nums1.begin(), it2 = nums2.begin();

        while (it1 != nums1.end() || it2 != nums2.end()) {
            if (greater(nums1, it1 - nums1.begin(), nums2, it2 - nums2.begin()))
                result.push_back(*it1++);
            else
                result.push_back(*it2++);
        }

        return result;
    }

    bool greater(vector<int>& nums1, int start1, vector<int>& nums2,
                 int start2) {
        while (start1 < nums1.size() && start2 < nums2.size() &&
               nums1[start1] == nums2[start2]) {
            start1++;
            start2++;
        }
        return start2 == nums2.size() ||
               (start1 < nums1.size() && nums1[start1] > nums2[start2]);
    }
};