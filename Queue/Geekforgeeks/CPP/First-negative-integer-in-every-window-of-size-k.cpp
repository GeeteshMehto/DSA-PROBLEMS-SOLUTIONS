/*
Question Link:- https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    deque<long long int> dq;
    vector<long long> ans;

    // Process the first window of size K
    for(int i = 0; i < K; i++) {
        if(A[i] < 0) {
            dq.push_back(i);
        }
    }

    // Store the answer for the first window of size K
    if(!dq.empty()) {
        ans.push_back(A[dq.front()]);
    } else {
        ans.push_back(0);
    }

    // Process the remaining windows
    for(int i = K; i < N; i++) {
        // Removal
        if(!dq.empty() && i - dq.front() >= K) {
            dq.pop_front();
        }

        // Addition
        if(A[i] < 0) {
            dq.push_back(i);
        }

        // Store answer
        if(!dq.empty()) {
            ans.push_back(A[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }

    return ans;
}
