/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * Core ideas:
     * 1. Greedy: If car starts at A and cannot reach B, then any station between A and B
     *    cannot reach B. B is the first station that A cannot reach.
     * 2. If the total gas is greater than the total cost, there must be a solution.
     */
    // T: O(n)
    // S: O(1)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int n = gas.size();
        int tot_gas = 0, cur_gas = 0;
        int start = 0;
        for (int i = 0; i < n; ++i) {
            int diff = gas[i] - cost[i];
            tot_gas += diff;
            cur_gas += diff;
            if (cur_gas < 0) {
                // Can't reach this station. Try 
                // starting from the next one.
                start = i + 1;
                cur_gas = 0;
            }
        }
        // Based on the 2nd idea above, we don't need to simulate the circular run with mod etc.
        return tot_gas < 0 ? -1 : start; 
    }
};
// @lc code=end

