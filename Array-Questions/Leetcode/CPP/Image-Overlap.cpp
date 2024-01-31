/*
Question Link:- https://leetcode.com/problems/image-overlap/description/
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxOverlap = 0;
        
        for (int dx = -n + 1; dx < n; ++dx) {
            for (int dy = -n + 1; dy < n; ++dy) {
                maxOverlap = max(maxOverlap, overlap(img1, img2, dx, dy));
            }
        }
        
        return maxOverlap;
    }
    
private:
    int overlap(vector<vector<int>>& img1, vector<vector<int>>& img2, int dx, int dy) {
        int n = img1.size();
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i + dx >= 0 && i + dx < n && j + dy >= 0 && j + dy < n) {
                    count += img1[i][j] & img2[i + dx][j + dy];
                }
            }
        }
        
        return count;
    }
};