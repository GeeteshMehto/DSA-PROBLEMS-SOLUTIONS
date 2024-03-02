/*
Question link:- https://leetcode.com/problems/simplify-path/description/
*/

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;

        int i = 0;
        while (i < path.size()) {
            // Skip consecutive slashes
            while (i < path.size() && path[i] == '/') {
                i++;
            }

            // Extract the directory name
            string dirName = "";
            while (i < path.size() && path[i] != '/') {
                dirName += path[i];
                i++;
            }

            // Process the directory name
            if (dirName == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (dirName != "." && !dirName.empty()) {
                stk.push(dirName);
            }
        }

        // Reconstruct the simplified path from stack.
        string simplifiedPath = "";
        while (!stk.empty()) {
            simplifiedPath = "/" + stk.top() + simplifiedPath;
            stk.pop();
        }

        // If no valid directory found, return root directory "/".
        if (simplifiedPath.empty()) {
            simplifiedPath = "/";
        }

        return simplifiedPath;
    }
};