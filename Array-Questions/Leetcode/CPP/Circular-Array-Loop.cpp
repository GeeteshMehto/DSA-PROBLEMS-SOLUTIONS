/*
Question Link:- https://leetcode.com/problems/circular-array-loop/description/
*/

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) // Skip visited or zero elements
                continue;

            int slow = i, fast = getNext(nums, i);
            while (nums[i] * nums[fast] > 0 &&
                   nums[i] * nums[getNext(nums, fast)] > 0) {
                if (slow == fast) {
                    if (slow == getNext(nums, slow))
                        break; // Cycle of size 1, move to next index

                    return true; // Cycle found
                }
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
            }

            // Mark the current cycle as visited
            int curr = i;
            while (nums[curr] * nums[getNext(nums, curr)] > 0) {
                int next = getNext(nums, curr);
                nums[curr] = 0; // Mark as visited
                curr = next;
            }
        }
        return false;
    }

private:
    int getNext(vector<int>& nums, int index) {
        int n = nums.size();
        return ((index + nums[index]) % n + n) % n;
    }
};