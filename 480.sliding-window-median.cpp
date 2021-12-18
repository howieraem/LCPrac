/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */
#include <iterator>
#include <set>
#include <vector>

using std::multiset;
using std::next;
using std::prev;
using std::vector;

// @lc code=start
class Solution {
public:
    // T: O(n*log(k))
    // S: O(k)
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k >> 1);
        vector<double> res;
        for (int i = k; i < nums.size(); ++i) {
            res.push_back((double(*mid) + *prev(mid, 1 - k & 1)) / 2.);
            window.insert(nums[i]);
            if (nums[i] < *mid)  --mid;
            if (nums[i - k] <= *mid)  ++mid;
            window.erase(window.lower_bound(nums[i - k]));
        }
        // don't forget the last window
        res.push_back((double(*mid) + *prev(mid, 1 - k & 1)) / 2.);
        return res;
    }
};
// @lc code=end

