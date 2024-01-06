#include <algorithm> 

void solve(string str, vector<string>& ans, int index) {
    if(index >= str.size()) {
        ans.push_back(str);
        return;
    }
    for(int j = index; j < str.size(); j++) {
        swap(str[index], str[j]);
        solve(str, ans, index + 1);
        // Backtrack
        swap(str[index], str[j]);
    }
}

vector<string> generatePermutations(string str) {
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    // Sort the permutations to ensure lexicographically increasing order
    sort(ans.begin(), ans.end());
    return ans;
}