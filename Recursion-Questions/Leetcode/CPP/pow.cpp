/*
Question Link:- https://leetcode.com/problems/powx-n/description/
*/


class Solution {
public:
    double myPow(double x, int n) {

        if (n == 0) {
            return 1;
        }
        if (x == 1) {
            return x;
        }

        double ans = myPow(x, n / 2);
        if (n % 2 == 0) {
            return ans * ans;
        } else {
            if (n > 0) {
                return x * ans * ans;
            } else {
                // Handle negative power by taking the reciprocal
                return (1 / x) * ans * ans;
            }
        }
    }
    };