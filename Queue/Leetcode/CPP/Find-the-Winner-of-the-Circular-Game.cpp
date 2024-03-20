/*
Question Link:- https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/
*/

class Solution {
public:
    int findTheWinner(int n, int k) {
        deque<int> friends;
        
        // Initialize friends from 1 to n
        for (int i = 1; i <= n; ++i)
            friends.push_back(i);
        
        // Simulate the game until only one friend remains
        while (friends.size() > 1) {
            // Count k friends and remove the kth friend
            for (int i = 0; i < k - 1; ++i) {
                // Move the friend who just lost to the back
                friends.push_back(friends.front());
                friends.pop_front();
            }
            // Remove the kth friend
            friends.pop_front();
        }
        
        // Return the winner
        return friends.front();
    }
};