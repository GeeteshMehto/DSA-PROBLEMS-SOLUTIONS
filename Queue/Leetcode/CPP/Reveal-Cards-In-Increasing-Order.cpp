/*
Question Link:- https://leetcode.com/problems/reveal-cards-in-increasing-order/description/
*/

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        queue<int> indices;
        int n = deck.size();
        for (int i = 0; i < n; ++i)
            indices.push(i);

        vector<int> result(n);
        for (int card : deck) {
            result[indices.front()] = card;
            indices.pop();
            if (!indices.empty()) {
                indices.push(indices.front());
                indices.pop();
            }
        }
        return result;
    }
};