/*
 * @lc app=leetcode id=1953 lang=cpp
 *
 * [1953] Maximum Number of Weeks for Which You Can Work
 */
#include <algorithm>
#include <vector>

using std::vector;

// @lc code=start
class Solution {
public:
    // Ideas: If there are at least two projects with same number of milestones and there isn't 
    // a project with more milestones than that two, can finish all milestones.
    // Otherwise, can only finish 2 * (sum(milestones) - max(milestones)) + 1 at most.
    // 
    // We can seperate projects to two parts: (1) project with most milestones (2) the rest of projects
    // The greedy strategy here is trying to use the milestones from (2) to form a new project 
    // with the same number of milestones as (1).
    // If possible, we can finish all milestones as we demonstrate.
    // If impossible, we can only: work on the max (1) => work on others (2) => work on the max (1) => etc
    // Detailed explanations: https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/discuss/1375390
    // T: O(n)
    // S: O(1)
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0, max = 0;
        for (const int &m : milestones) {
            sum += m;
            max = std::max(max, (long long) m);
        }

        return sum - max >= max ? sum : ((sum - max) << 1) + 1;
    }
};
// @lc code=end

