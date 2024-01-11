/*
Question Link:- https://leetcode.com/problems/roman-to-integer/description/
*/
class Solution {
public:
    int romanToInt(string s) {
        // Define arrays to store the values and corresponding symbols of Roman numerals
        char romanSymbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int romanValues[] = {1, 5, 10, 50, 100, 500, 1000};

        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            int currentSymbolValue = getValue(romanSymbols, romanValues, s[i]);
            int nextSymbolValue = (i < s.length() - 1) ? getValue(romanSymbols, romanValues, s[i + 1]) : 0;

            // If the current numeral is smaller than the next one, subtract its value
            if (currentSymbolValue < nextSymbolValue) {
                result -= currentSymbolValue;
            } else {
                result += currentSymbolValue;
            }
        }

        return result;
    }

private:
    int getValue(char symbols[], int values[], char symbol) {
        for (int i = 0; i < 7; ++i) {
            if (symbols[i] == symbol) {
                return values[i];
            }
        }
        return 0; // Return 0 if the symbol is not found (should not happen for valid input)
    }
};
