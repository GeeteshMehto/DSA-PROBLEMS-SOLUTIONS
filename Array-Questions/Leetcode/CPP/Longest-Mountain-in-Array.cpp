/*
Question Link:- https://leetcode.com/problems/longest-mountain-in-array/description/
*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxLength = 0;

        for (int i = 1; i < n - 1; ++i) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) { // found a peak
                int left = i - 1;
                int right = i + 1;

                // expand left
                while (left > 0 && arr[left] > arr[left - 1]) {
                    --left;
                }

                // expand right
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    ++right;
                }

                // calculate length of mountain subarray
                int length = right - left + 1;

                // update maxLength if the current mountain subarray is longer
                maxLength = max(maxLength, length);
                
                // move to the next element after the mountain
                i = right;
            }
        }

        return maxLength;
    }
};