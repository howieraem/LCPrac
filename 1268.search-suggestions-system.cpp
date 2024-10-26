/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution {
 public:
  // Sort + Binary search (lower bound)
  // Idea: If the strings are sorted, we can do binary search to get the first
  // word that has the same prefix, and then just check the next 2 words to see
  // if they have the same prefix or not.
  // T: O(n * log(n)), n := len(products)
  // S: O(log(n)) (avg. space complexity of std::sort())
  std::vector<std::vector<std::string>> suggestedProducts(
      std::vector<std::string>& products, std::string searchWord) {
    std::sort(products.begin(), products.end());

    const int n = products.size();
    std::vector<std::vector<std::string>> res;
    int begin_search_idx = 0;
    std::string prefix;
    prefix.reserve(searchWord.size());
    bool prev_empty = false;  // if longer prefix will always get empty results

    for (const auto& c : searchWord) {
      if (prev_empty) {
        // prevent useless search
        res.push_back({});
        continue;
      }

      prefix += c;

      // Get the starting index of word with prefix
      int start_idx = std::lower_bound(products.begin() + begin_search_idx,
                                       products.end(), prefix) -
                      products.begin();
      int end_idx = std::min(start_idx + 3, n);
      std::vector<std::string> char_res;

      for (int i = start_idx; i < end_idx; ++i) {
        if (products[i].compare(0, prefix.size(), prefix) != 0) {
          // Add the words with the same prefix to the result.
          // std::string::compare() returns 0 if strings equal.
          // This method avoids making a prefix substring of `products[i]`.
          break;
        }
        char_res.push_back(products[i]);
      }
      if (char_res.empty()) {
        prev_empty = true;
        res.push_back({});
        continue;
      }
      res.push_back(std::move(char_res));

      // Reduce the search space of the next binary search
      begin_search_idx = start_idx;
    }
    return res;
  }
};
// @lc code=end
