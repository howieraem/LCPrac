/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */
#include <deque>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1: Stack of (char, count)
    // T: O(n)
    // S: O(n)
    string removeDuplicates(string s, int k) {
        deque<pair<char, int>> stack;   // use deque as std::stack does not have an iterator

        for (const char &c : s) {
            if (stack.empty() || stack.back().first != c) {
                stack.push_back({c, 1});
            } else if (++stack.back().second == k) {
                stack.pop_back();
            }
        }

        string res;
        for (const auto &p : stack) {
            res.append(p.second, p.first);
        }
        return res;
    }
    */

    // Solution 2: Two pointers (same complexities but less cost than solution 1)
    // T: O(n)
    // S: O(n)
    string removeDuplicates(string s, int k) {
        const int n = s.size();
        vector<int> cnt_at_idx(n);
        int i = 0;
        for (int j = 0; j < n; ++i, ++j) {
            s[i] = s[j];
            cnt_at_idx[i] = (i > 0 && s[i - 1] == s[j]) ? cnt_at_idx[i - 1] + 1 : 1;
            if (cnt_at_idx[i] == k)  i -= k;
        }
        return s.substr(0, i);
    }
};
// @lc code=end

