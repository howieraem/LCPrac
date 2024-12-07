/* The knows API is defined for you. */
bool knows(int a, int b);

class Solution {
public:
    // Graph + Greedy
    // T: O(n) assuming knows() is O(1)
    // S: O(1) assuming knows() is O(1)
    int findCelebrity(int n) {
        // Find a possible celebrity candidate
        int candidate = 0;
        for (int i = 1; i < n; ++i) {
            if (knows(candidate, i)) {
                // The previous candidate is invalid,
                // and i may be a valid celebrity 
                candidate = i;
            }
        }

        // Check if the candidate is really valid
        for (int i = 0; i < n; ++i) {
            if (i < candidate) {
                if (knows(candidate, i) || !knows(i, candidate)) {
                    return -1;
                }
            } else if (i > candidate) { 
                if (!knows(i, candidate)) {
                    // no need to check knows(candidate, i) again because of the previous loop
                    return -1;
                }
            }
        }
        return candidate;
    }
};