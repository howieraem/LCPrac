/*
 * @lc app=leetcode id=811 lang=cpp
 *
 * [811] Subdomain Visit Count
 */
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n * l), l := average domain length
    // S: O(n)
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for (const auto &s : cpdomains) {
            int i = s.find(' ');
            int cnt = stoi(s.substr(0, i));

            mp[s.substr(++i)] += cnt;   // first full domain

            // subdomains
            for (i = i + 1; i < s.size(); ++i) {
                if (s[i] == '.') {
                    mp[s.substr(i + 1)] += cnt;
                }
            }
        }

        vector<string> res;
        for (const auto [domain, cnt] : mp) {
            res.push_back(to_string(cnt) + " " + domain);
        }
        return res;
    }
};
// @lc code=end

