/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ls = s.size(), lp = p.size();
        vector<int> res;
        if (ls < lp)  return res;
        vector<int> count_s(26, 0), count_p(26, 0); // use vector for fast `==` check
        for (int i=0; i < lp; ++i) {
            count_p[p[i]-'a']++;
            count_s[s[i]-'a']++;
        }
        if (count_p == count_s)  res.emplace_back(0);
        for (int i = 0; i + lp < ls; ++i) {
            count_s[s[i]-'a']--;
            count_s[s[i+lp]-'a']++;
            if (count_p == count_s) {
                res.emplace_back(i+1);
            }
        }
        return res;
    }
};
// @lc code=end
int main() {
    string a = "cbaebabacd";
    string b = "abc";
    Solution *s = new Solution();
    vector<int> res = s->findAnagrams(a, b);
    cout << '[';
    for(auto elem: res) {
        cout << elem << ", ";
    }
    cout << ']' << endl;
}
