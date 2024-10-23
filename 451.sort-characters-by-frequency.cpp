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
    // Bucket sort
    // T: O(len(s) + alpha_size)
    // S: O(alpha_size)
    string frequencySort(string s) {
        // unordered_map<char, int> f;
        int freqs[256] = {0};
        for (const char& c : s) {
            ++freqs[c];
        }
        
        /*
        // Solution with direct sorting, O(n * log(n)), n := len(s) 
        sort(s.begin(), s.end(), [&](char a, char b) { 
            return f[a] > f[b] || (f[a] == f[b] && a < b); 
        });
        return s;
        */

        // Solution with bucket sort
        vector<string> bucket(s.size() + 1, "");
        // for (auto &e : f) {
        //     int freq = e.second;
        //     if (freq == 0)  continue;
        //     bucket[freq].append(n, e.first);
        // }
        for (int i = 0; i < 256; ++i) {
            const int& freq = freqs[i];
            if (freq == 0) {
                continue;
            }
            // pre-append char * freq substrings (e.g., 'c' * 2 -> "cc"); 
            // If same freq, different kinds of chars are sorted lexicographically ASC
            bucket[freq].append(freq, (char) i);
        }

        string res;
        res.reserve(s.size());
        for (int i = s.size(); i > 0; --i) {
            if (!bucket[i].empty()) {
                res.append(std::move(bucket[i]));
            }
        }
        return res;
    }
};
// @lc code=end

