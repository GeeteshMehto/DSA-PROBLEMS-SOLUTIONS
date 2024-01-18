class Solution {
public:
    string convert(string s, int numRows) {
        // If there is only one row or the string is empty, return the original string
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create a vector of strings to represent each row
        vector<string> rows(numRows);

        int row = 0;
        bool goingDown = false;

        // Iterate through each character in the string
        for (char c : s) {
            // Add the character to the current row
            rows[row] += c;

            // Change the direction if we reach the first or last row
            if (row == 0 || row == numRows - 1) {
                goingDown = !goingDown;
            }

            // Update the current row based on the direction
            row += goingDown ? 1 : -1;
        }

        // Combine all rows to get the final zigzag pattern
        string result;
        for (const string& r : rows) {
            result += r;
        }

        return result;
    }
};
