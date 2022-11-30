/*
 * @lc app=leetcode id=1296 lang=cpp
 *
 * [1296] Divide Array in Sets of K Consecutive Numbers
 */

// @lc code=start
class Solution {
public:
    // Same as Q846
    // T: O(n + m * log(m)) amortized (each number only used once), m := the number of unique value
    // S: O(n)
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false; 

        map<int, int> cnts;
        for (const int& x : nums) {
            ++cnts[x];
        }

        // For each unique value, if some of its instances have not been used in groups,
        // let these instances be the first numbers of the new groups, and check if we 
        // have enough instances of consecutive values to complete the new groups. 
        for (const auto& [x, x_cnt] : cnts) {
            if (x_cnt > 0) {
                for (int y = x + 1; y < x + k; ++y) {
                    auto p = cnts.find(y);
                    if (p == cnts.end() || p->second < x_cnt) {
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

