/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */
#include <bits/stdc++.h>

using std::vector;
using std::string;

// @lc code=start
class Solution {
public:
    // T: O(n * log(n) * log(avg(nums)))
    // S: O(n * log(avg(nums)))
    string largestNumber(vector<int>& nums) {
        if (std::all_of(nums.begin(), nums.end(), [](const int& num) { return num == 0; })) {
            // Handle special case beforehand to avoid sorting and changing 
            // the result string inefficiently after
            return "0";
        }

        vector<string> strings;
        int len = 0;
        strings.reserve(nums.size());
        for (const int& x : nums) {
            string s = std::to_string(x);
            len += s.size();
            strings.push_back(std::move(s));
        }
        std::sort(strings.begin(), strings.end(), [](const string& s1, const string& s2) {
            // Comparator example: 
            //   s1 = "9", s2 = "31"
            //   s1 + s2 = "931"
            //   s2 + s1 = "319"
            //   Thus, s1 should be in front of s2
            return s1 + s2 > s2 + s1;
        });
        
        string res;
        res.reserve(len);
        for (const auto& s : strings) {
            res.append(s);
        }
        return res;
    }
};
// @lc code=end

