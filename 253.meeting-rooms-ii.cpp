/*
 * @lc app=leetcode id=253 lang=cpp
 *
 * [253] Meeting Rooms II
 */
#include <algorithm>
#include <vector>
#include <utility>

using std::max;
using std::pair;
using std::sort;
using std::vector;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1: separate sorting
    // T: O(n*log(n))
    // S: O(n)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<int> starts(n, 0), ends(n, 0);
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int ans = 0, curEndIdx = 0;
        for (int i = 0; i < n; ++i) {
            if (starts[i] < ends[curEndIdx]) {
                // Has overlap, must create a new room
                ++ans;
            } else {
                // No overlap, an existing room can be reused
                ++curEndIdx;
            }
        }
        return ans;
    }
    */

    // Solution 2: Sweeping line, only need to sort once
    // T: O(n*log(n))
    // S: O(n)
    int minMeetingRooms(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<pair<int, int>> inters(n << 1);
        int p = 0;
        for (int i = 0; i < n; ++i) {
            inters[p++] = {intervals[i][0], 1};      // start
            inters[p++] = {intervals[i][1], -1};     // end
        }

        sort(inters.begin(), inters.end());
        int ans = 0, cur_rooms = 0;
        for (const auto &inter : inters) {
            ans = max(ans, cur_rooms += inter.second);
        }
        return ans;
    }
};
// @lc code=end

