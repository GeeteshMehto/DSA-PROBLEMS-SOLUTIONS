/*
Question Link:- https://leetcode.com/problems/stamping-the-sequence/description/
*/

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> result;
        int m = stamp.size(), n = target.size();
        bool replaced = true;

        while (replaced) {
            replaced = false;
            for (int i = 0; i <= n - m; ++i) {
                bool matched = false;
                for (int j = 0; j < m; ++j) {
                    if (target[i + j] == stamp[j] || target[i + j] == '?')
                        matched = true;
                    else {
                        matched = false;
                        break;
                    }
                }
                if (matched) {
                    for (int j = 0; j < m; ++j) {
                        if (target[i + j] != '?') {
                            target[i + j] = '?';
                            replaced = true;
                        }
                    }
                    result.push_back(i);
                    if (count(target.begin(), target.end(), '?') == n) {
                        reverse(result.begin(), result.end());
                        return result;
                    }
                }
            }
        }

        return {};
    }
};