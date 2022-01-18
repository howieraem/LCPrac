/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */
#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n*log(n))
    // S: O(n) (ignoring space complexity of std::sort())
    int minMeetingRooms(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<int> starts(n, 0), ends(n, 0);
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int ans = 0, intervalEndIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (starts[i] < ends[intervalEndIdx]) {
                ++ans;
            } else {
                ++intervalEndIdx;
            }
        }
        return ans;
    }
};
// @lc code=end

