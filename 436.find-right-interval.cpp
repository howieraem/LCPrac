/*
 * @lc app=leetcode id=436 lang=cpp
 *
 * [436] Find Right Interval
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n*log(n))
    // S: O(n)
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        vector<int> res(n);
        map<int, int> mp;    // tree map, red-black tree
        for (int i = 0; i < n; ++i) {
            mp[intervals[i][0]] = i;    // map interval start to interval index
        }

        for (int i = 0; i < n; ++i) {
            // For each interval end, find the cloest next interval start.
            // From STL documentation: 
            //   lower_bound(const key_type& k) returns an iterator 
            //   pointing to the first element in the container 
            //   whose key is not considered to go before k (i.e., 
            //   either it is equivalent or goes after).
            auto e = mp.lower_bound(intervals[i][1]);
            res[i] = e != mp.end() ? e->second : -1;
        }
        return res;
    }
};
// @lc code=end

