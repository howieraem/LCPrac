/*
 * @lc app=leetcode id=2158 lang=cpp
 *
 * [2158] Amount of New Area Painted Each Day
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n * log(m)), m := interval_max - interval_min
    // S: O(n)
    vector<int> amountPainted(vector<vector<int>>& paint) {
        const int N = paint.size();
        std::map<int, int> intervals;
        vector<int> res;
        res.reserve(N);

        for (const auto& p : paint) {
            // For each day, first search for the existing painted interval on the left. 
            // If that interval exists and overlaps, extend it. Otherwise, create a new interval.
            int l = p[0], r = p[1];
            auto next = intervals.upper_bound(l), cur = next;
            if (cur != intervals.begin() && std::prev(cur)->second >= l) {
                cur = std::prev(cur);
                l = cur->second;
            } else {
                // std::map::insert() here returns a pair, with its member pair::first 
                // set to an iterator pointing to either the newly inserted element or 
                // to the element with an equivalent key in the map. The pair::second 
                // element in the pair is set to true if a new element was inserted or 
                // false if an equivalent key already existed.
                cur = intervals.insert({l, r}).first;
            }

            // Then, go right and merge all overlapping intervals into the current (cur) one. 
            // Meanwhile, carefully track the newly painted area.
            int paint = r - l;
            while (next != intervals.end() && next->first < r) {
                paint -= std::min(r, next->second) - next->first;
                r = std::max(r, next->second);
                intervals.erase(next++);
            }
            cur->second = std::max(cur->second, r);
            res.push_back(std::max(0, paint));
        }
        return res;
    }
};
// @lc code=end
