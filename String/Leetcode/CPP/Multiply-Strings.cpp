/*
Question Link:- https://leetcode.com/problems/multiply-strings/
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);

        // Perform the multiplication
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // Convert result to string
        string resultStr;
        for (int digit : result) {
            if (!(resultStr.empty() && digit == 0)) {
                resultStr.push_back(digit + '0');
            }
        }

        return resultStr.empty() ? "0" : resultStr;
    }
};