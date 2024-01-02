class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        // Start from the rightmost digit
        for (int i = n - 1; i >= 0; --i) {
            // Add 1 to the current digit
            digits[i] += 1;

            // Check if there is a carry
            if (digits[i] < 10) {
                // No carry, return the modified digits
                return digits;
            } else {
                // There is a carry, set current digit to 0 and continue with the next digit
                digits[i] = 0;
            }
        }

        // If we reach here, it means there was a carry that propagated to the leftmost digit
        // Add a new digit with the value 1 at the beginning
        digits.insert(digits.begin(), 1);

        return digits;
    }
};
