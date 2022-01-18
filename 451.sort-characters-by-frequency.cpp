/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */
#include <string>
// #include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        // unordered_map<char, int> f;
        int f[256] = {0};
        for (char c : s)  ++f[c];
        
        /*
        // Solution with direct sorting, O(NlogN), N=s.size() 
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return f[a] > f[b] || (f[a] == f[b] && a < b); 
        });
        return s;
        */

        // Solution with bucket, O(s.size())
        vector<string> bucket(s.size() + 1, "");
        // for (auto &e : f) {
        //     int n = e.second;
        //     bucket[n].append(n, e.first);
        // }
        for (int i = 0; i < 256; ++i) {
            int n = f[i];
            bucket[n].append(n, (char) i);
        }

        string res;
        for (int i = s.size(); i > 0; --i) {
            if (!bucket[i].empty()) {
                res.append(bucket[i]);
            }
        }
        return res;
    }
};
// @lc code=end

