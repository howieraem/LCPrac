/*
 * @lc app=leetcode id=1604 lang=cpp
 *
 * [1604] Alert Using Same Key-Card Three or More Times in a One Hour Period
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
 public:
  // T: O(n * log(n))
  // S: O(n)
  std::vector<std::string> alertNames(std::vector<std::string>& keyName,
                                      std::vector<std::string>& keyTime) {
    std::unordered_map<std::string, std::vector<int>> mp;
    for (int i = 0; i < keyName.size(); ++i) {
      mp[keyName[i]].push_back(
          std::stoi(keyTime[i].substr(0, 2) + keyTime[i].substr(3)));
    }

    std::vector<std::string> res;
    for (auto& [k, v] : mp) {
      std::sort(v.begin(), v.end());
      // Simple sliding window
      for (int i = 2; i < v.size(); ++i) {
        if (v[i] - v[i - 2] <= 100) {
          res.push_back(k);
          break;
        }
      }
    }
    std::sort(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
