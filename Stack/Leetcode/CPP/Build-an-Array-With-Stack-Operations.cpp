
/*
Question Link :- https://leetcode.com/problems/build-an-array-with-stack-operations/
*/


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int j=1,i=0;
        while(j<=n && i<target.size()) {
            if(j==target[i]) {
                result.push_back("Push");
                i++;
                j++;
            }
            else if(j!=target[i]) {
                result.push_back("Push");
                result.push_back("Pop");
                j++;
            }
        }
        return result;
    }
};
