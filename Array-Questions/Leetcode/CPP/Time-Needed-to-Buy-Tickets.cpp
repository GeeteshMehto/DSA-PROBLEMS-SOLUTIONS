/*
Question Link:- https://leetcode.com/problems/time-needed-to-buy-tickets/description/
*/



class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;

        // Simulate the process until the person at position k finishes buying
        // tickets
        while (tickets[k] > 0) {
            for (int i = 0; i < n; ++i) {
                if (tickets[i] > 0) {
                    tickets[i]--; // Buy a ticket
                    time++;       // Increment time by 1 second
                    if (i == k &&
                        tickets[k] == 0) // Check if the person at position k
                                         // has finished buying tickets
                        return time;
                }
            }
        }

        return time; // This line is unreachable, as the loop above will always
                     // exit when the person at position k finishes buying
                     // tickets
    }
};