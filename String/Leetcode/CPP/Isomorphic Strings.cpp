/*
Question Link:- https://leetcode.com/problems/isomorphic-strings/description
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length())
        return false;

    unordered_map<char, char> s_to_t_map;
    unordered_map<char, char> t_to_s_map;

    for (int i = 0; i < s.length(); ++i) {
        if (s_to_t_map.find(s[i]) == s_to_t_map.end() && t_to_s_map.find(t[i]) == t_to_s_map.end()) {
            s_to_t_map[s[i]] = t[i];
            t_to_s_map[t[i]] = s[i];
        } else {
            if (s_to_t_map[s[i]] != t[i] || t_to_s_map[t[i]] != s[i])
                return false;
        }
    }

    return true;
    }
};