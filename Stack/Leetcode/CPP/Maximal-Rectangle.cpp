/*
Question Link:- https://leetcode.com/problems/maximal-rectangle/description/
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0); // store the height of each bar in the histogram
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            // Update heights array
            for (int j = 0; j < cols; ++j) {
                heights[j] = matrix[i][j] == '1' ? heights[j] + 1 : 0;
            }
            // Calculate the largest rectangle for this row
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> s;
        
        // Calculate the nearest smallest element to the left
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        
        // Clear the stack
        while (!s.empty()) {
            s.pop();
        }
        
        // Calculate the nearest smallest element to the right
        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty() ? n : s.top();
            s.push(i);
        }
        
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));
        }
        
        return maxArea;
    }
};