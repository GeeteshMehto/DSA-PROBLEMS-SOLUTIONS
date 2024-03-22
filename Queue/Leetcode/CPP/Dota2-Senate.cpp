/*
Question Link:- https://leetcode.com/problems/dota2-senate/description/
*/

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;
        int n = senate.size();
        
        // Queue the indices of senators
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        
        while (!radiant.empty() && !dire.empty()) {
            int radiant_index = radiant.front();
            int dire_index = dire.front();
            radiant.pop();
            dire.pop();
            
            // If the Radiant senator comes before the Dire senator,
            // ban the next Dire senator's right and re-queue them,
            // else ban the next Radiant senator's right
            if (radiant_index < dire_index)
                radiant.push(radiant_index + n);
            else
                dire.push(dire_index + n);
        }
        
        return radiant.size() > dire.size() ? "Radiant" : "Dire";
    }
};