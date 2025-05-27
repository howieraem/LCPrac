/*
 * @lc app=leetcode id=412 lang=cpp
 *
 * [412] Fizz Buzz
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
 public:
  std::vector<std::string> fizzBuzz(int n) {
    std::vector<std::string> res;
    for (int i = 1; i <= n; ++i) {
      std::string ans;

      if (i % 3 == 0) {
        ans += "Fizz";
      }
      if (i % 5 == 0) {
        ans += "Buzz";
      }
      if (ans.empty()) {
        res.push_back(std::to_string(i));
      } else {
        res.push_back(std::move(ans));
      }
    }
    return res;
  }
};
// @lc code=end
