/*
Question Link:- https://leetcode.com/problems/number-of-recent-calls/description/
*/

#include <queue>

class RecentCounter {
private:
    queue<int> requests;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        // Add the current request time
        requests.push(t);
        
        // Remove requests older than 3000 milliseconds
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        
        // Return the number of requests within the last 3000 milliseconds
        return requests.size();
    }
};
