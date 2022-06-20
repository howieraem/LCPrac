/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */
#include <bits/stdc++.h>

using std::string;

// @lc code=start
class Solution {
 public:
  /*
  // Recursive
  // T: O(log(n))
  // S: O(1) tail recursion
  string convertToTitle(int columnNumber) {
    return columnNumber == 0 ? ""
                             : convertToTitle((columnNumber - 1) / 26) + (char)((columnNumber - 1) % 26 + 'A');
  }
  */

  // Iterative
  // T: O(log(n))
  // S: O(1)
  string convertToTitle(int columnNumber) {
    string res;

    /*
    while (columnNumber > 0) {
      if (columnNumber % 26 == 0) {
        res.push_back(26 + 'A');
        columnNumber = columnNumber / 26 - 1;
      } else {
        res.push_back(columnNumber % 26 + 'A');
        columnNumber /= 26;
      }
    }
    */

    while (columnNumber-- > 0) {
      res.push_back(columnNumber % 26 + 'A');
      columnNumber /= 26;
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
