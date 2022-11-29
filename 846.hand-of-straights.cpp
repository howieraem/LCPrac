/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */
#include <bits/stdc++.h>

using std::map;
using std::vector;

// @lc code=start
class Solution {
public:
    // Same as Q1296
    // T: O(n + m * log(m)) amortized (each card only used once), m := the number of unique hand values
    // S: O(n)
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false; 

        map<int, int> cnts;
        for (const int& x : hand) {
            ++cnts[x];
        }

        // For each unique hand value, if some of its instances have not been used in groups,
        // let these instances be the first numbers of the new groups, and check if we 
        // have enough instances of consecutive hand values to complete the new groups. 
        for (const auto& [x, x_cnt] : cnts) {
            if (x_cnt > 0) {
                for (int y = x + 1; y < x + groupSize; ++y) {
                    auto p = cnts.find(y);
                    if (p->second < x_cnt) {
                        return false;
                    }
                    p->second -= x_cnt;
                }
            }
        }

        return true;
    }
};
// @lc code=end

