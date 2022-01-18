/*
 * @lc app=leetcode id=1081 lang=cpp
 *
 * [1081] Smallest Subsequence of Distinct Characters
 */
#include <string>

using std::string;

// @lc code=start
class Solution {
public:
    // Same solution as Q316.
    // T: O(n)
    // S: O(n)
    string smallestSubsequence(string s) {
        const int n = s.size();
        bool vis[26] {};
        int cnt[26] {};
        for (const char &c : s) {
            ++cnt[c - 'a'];
        }

        string stack;
        for (const char &ch : s) {
            int c = ch - 'a';
            if (!vis[c]) {
                while (stack.size() && stack.back() > ch && cnt[stack.back() - 'a']) {
                    vis[stack.back() - 'a'] = false;
                    stack.pop_back();   // will add the popped character again later when the order allows
                }
                vis[c] = true;
                stack.push_back(ch);
            }
            --cnt[c];
        }
        return stack;
    }
};
// @lc code=end

