/*
Question Link:- https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
*/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int circularCount = 0; // Number of students who prefer circular sandwiches
        int squareCount = 0; // Number of students who prefer square sandwiches

        // Counting the number of students with each preference
        for (int pref : students) {
            if (pref == 0) {
                circularCount++;
            } else {
                squareCount++;
            }
        }

        // Iterating through the sandwiches
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (circularCount == 0) {
                    break; // No more circular sandwiches left, so stop the
                           // process
                }
                circularCount--; // A circular sandwich has been taken
            } else {
                if (squareCount == 0) {
                    break; // No more square sandwiches left, so stop the
                           // process
                }
                squareCount--; // A square sandwich has been taken
            }
        }

        // The remaining students who couldn't eat are the ones whose
        // preferences couldn't be satisfied
        return circularCount + squareCount;
    }
};