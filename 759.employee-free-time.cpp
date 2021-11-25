/*
 * @lc app=leetcode id=759 lang=cpp
 *
 * [759] Employee Free Time
 */
#include <algorithm>
#include <vector>

using namespace std;


class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

// @lc code=start
/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    // Solution 1: sort all intervals (which ignores that the intervals of a person are sorted)
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res, sorted;
        for (auto &s : schedule) {
            for (auto &t : s) {
                sorted.push_back(t);
            }
        }
        sort(sorted.begin(), sorted.end(), [](const Interval &i1, const Interval &i2) {
            return i1.start == i2.start ? i1.end < i2.end : i1.start < i2.start;
        });

        int end = -1;
        for (auto &t : sorted) {
            if (t.start > end) {
                if (end != -1)  res.push_back(Interval(end, t.start));
                end = t.end;
            } else {
                end = max(end, t.end);
            }
        }
        return res;
    }
};
// @lc code=end

