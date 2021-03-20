/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())  return false;
        int count[26] = {0};
        for (int i=0; i<s.size(); ++i) {
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for (auto num:count) {
            if (num)  return false;
        }
        return true;
    }
};
// @lc code=end

