/*
 * @lc app=leetcode id=358 lang=cpp
 *
 * [358] Rearrange String k Distance Apart
 */
#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::pair;
using std::priority_queue;

// @lc code=start
class Solution {
public:
    /*
    // Greedy Solution 1
    // T: O(n * s)
    // S: O(s)
    string rearrangeString(string s, int k) {
        if (!k)  return s;

        // `cnt`: stores the remaining count of every character type
        // `valid`: keeps track of the left most position that one character can appear
        vector<int> cnt(26, 0), valid(26, 0);
        for (const auto& c : s) {
            ++cnt[c - 'a'];
        }

        string res;

        // Every time we want to find the best candidate which is 
        // the character with the largest remaining count. Reason:
        // https://leetcode.com/problems/rearrange-string-k-distance-apart/discuss/161489/
        for (int i = 0; i < s.size(); ++i) {
            int candidate = find_valid_max(cnt, valid, i);
            if (candidate == -1)  return "";
            --cnt[candidate];
            valid[candidate] = i + k;
            res.push_back('a' + candidate);
        }
        return res;
    }

    int find_valid_max(vector<int>& cnt, vector<int>& valid, int idx) {
        int max = INT_MIN, candidate = -1;
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i] > 0 && cnt[i] > max && idx >= valid[i]) {
                max = cnt[i];
                candidate = i;
            }
        }
        return candidate;
    }
    */

    // Greedy Solution 2
    // T: O(n * log(s))
    // S: O(s)
    string rearrangeString(string s, int k) {
        if (!k)  return s;

        vector<int> cnts(26, 0);
        for (const char& c : s) {
            ++cnts[c - 'a'];
        }

        priority_queue<pair<int, char>> max_heap;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i]) {
                max_heap.push({cnts[i], 'a' + i});
            }
        }

        int len = s.size();
        string res;
        res.reserve(len);
        vector<pair<int, char>> tmp_pairs;
        tmp_pairs.reserve(26);

        while (max_heap.size()) {
            tmp_pairs.clear();
            int cnt = std::min(k, len);
            while (cnt-- > 0) {
                if (max_heap.empty()) return "";
                auto p = max_heap.top(); max_heap.pop();
                res.push_back(p.second);
                if (--p.first > 0) {
                    tmp_pairs.push_back(p);
                }
                --len;
            }
            for (const auto& p : tmp_pairs) {
                max_heap.push(p);
            }
        }
        return res;
    }
};
// @lc code=end

