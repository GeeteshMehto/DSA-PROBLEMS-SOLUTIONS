/*
Question Link:- https://leetcode.com/problems/jewels-and-stones/description/
*/

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // Create a lookup table to store whether a character is a jewel
        bool jewelLookup[256] = {false}; // Assuming ASCII characters

        // Mark each character in jewels as a jewel in the lookup table
        for (char jewel : jewels) {
            jewelLookup[jewel] = true;
        }

        int jewelCount = 0;

        // Iterate through each stone
        for (char stone : stones) {
            // If the stone is a jewel, increment the count
            if (jewelLookup[stone]) {
                jewelCount++;
            }
        }

        return jewelCount;
    }
};