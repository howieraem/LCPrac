/*
 * @lc app=leetcode id=252 lang=cpp
 *
 * [252] Meeting Rooms
 */
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(log(n)) (space complexity of std::sort())
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        // Sort by start and then end
        sort(intervals.begin(), intervals.end());

        for (int i = 1; i < intervals.size(); ++i) {
            // If any intervals overlap, then it's impossible to attend these meetings
            if (intervals[i][0] < intervals[i - 1][1])  return false;
        }
        return true;
    }
};
// @lc code=end

