/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 */
#include <bits/stdc++.h>

using std::vector;

// @lc code=start
class Solution {
    vector<int> original;
    int n;

public:
    // T: O(n)
    Solution(vector<int>& nums) : original(nums), n(nums.size()) {}

    // T: O(1)
    vector<int> reset() {
        return original;
    }

    // T: O(n)
    vector<int> shuffle() {
        // Alternatively, can have a `shuffled` array class member and do the copy in constructor,
        // if the external code will not change the shuffled array returned
        vector<int> res(original);

        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine gen(seed);
        for (int i = 0; i < n; ++i) {
            // NOTE: rand() % x does not guarantee uniform distribution!
            std::uniform_int_distribution<int> distrib(i, n - 1);
            std::swap(res[i], res[distrib(gen)]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

