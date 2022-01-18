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
    // T: O(n*log(n)), S: O(1) (ignoring space complexity of std::sort())
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(), intervals.end(), 
            [](const auto &i1, const auto &i2) { 
                return i1[0] < i2[0]; });
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1])  return false;
        }
        return true;
    }
};
// @lc code=end

