/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution with sorting
    int heightChecker(vector<int>& heights) {
        vector<int> cloned(heights);
        sort(heights.begin(), heights.end());

        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            ans += (cloned[i] != heights[i]);
        }
        return ans;
    }
    */

    // Solution without std::sort():
    // Given max(heights.size()) = 100 and max(heights) = 100 by the question,
    // obviously counting sort would be faster (O(N) < O(NlogN)).
    static const int MIN_VAL = 1, MAX_VAL = 100;

    int heightChecker(vector<int>& heights) {
        vector<int> freq(MAX_VAL + 1);
        for (auto &h : heights) {
            ++freq[h];
        }

        int ans = 0, i = 0;
        for (int h = MIN_VAL; h <= MAX_VAL; ++h) {
            while (freq[h]) {   // this will also skips nonexistent height values
                ans += (h != heights[i++]);
                --freq[h];
            }
        }
        return ans;
    }
};
// @lc code=end

