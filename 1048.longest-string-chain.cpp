/*
 * @lc app=leetcode id=1048 lang=cpp
 *
 * [1048] Longest String Chain
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // 1D DP with hash map
    // T: O(n * (log(n) + l)), n := len(words), l := max word length
    // S: O(n)
    int longestStrChain(vector<string>& words) {
        // Sort words by length
        sort(words.begin(), words.end(), [] (const string& w1, const string& w2) { 
            return w1.size() < w2.size(); });

        unordered_map<string, int> dp;  // k: word, v: longest chain to reach this word
        int ans = 0;
        for (auto &w: words) {
            // base case: dp[w] = 1
            dp[w] = 1;
            auto dp_w_it = dp.find(w);

            for (int i = 0; i < w.size(); ++i) {
                // skip a char and see if a predecessor exists
                string pre = w.substr(0, i) + w.substr(i + 1);

                auto dp_pre_it = dp.find(pre);
                if (dp_pre_it != dp.end()) {
                    dp_w_it->second = max(dp_w_it->second, dp_pre_it->second + 1);
                }
            }
            ans = max(ans, dp_w_it->second);
        }
        return ans;
    }

    /*
    // Original solution: dp with vector
    int longestStrChain(vector<string>& words) {
        // Sort words by length
        sort(words.begin(), words.end(), [] (const string& w1, const string& w2) { 
            return w1.size() < w2.size(); });

        const int n = words.size();
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPre(words[i], words[j])) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    static bool isPre(const string& pre, const string& cur) {
        if (cur.size() - pre.size() != 1)  return false;
        int diffs = 0, i = 0, j = 0;
        while (i < pre.size() && j < cur.size()) {
            if (pre[i] == cur[j]) {
                ++i; ++j;
            } else {
                ++diffs;
                if (diffs > 1)  return false;
                ++j;
            }
        }
        return true;
    }
    */
};
// @lc code=end

