/*
Question Link:- https://leetcode.com/problems/power-of-three/description/
*/

class Solution {
public:
    bool isPowerOfThree(int n) {

        if (n <= 0) {
            return false; // Negative numbers and zero are not powers of three
        }

        if (n == 1) {
            return true; // Base case: 3^0 is 1
        }

        // Recursive case: Check if n is divisible by 3 and the result is a power of three
        return (n % 3 == 0) && isPowerOfThree(n / 3);
        
    }
};