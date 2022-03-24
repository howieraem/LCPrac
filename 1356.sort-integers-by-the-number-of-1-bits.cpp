/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n))
    // S: O(n)
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](int x, int y) {
            int a = __builtin_popcount(x), b = __builtin_popcount(y);
            return a == b ? x < y : a < b;
        });
        return arr;
    }
};
// @lc code=end

