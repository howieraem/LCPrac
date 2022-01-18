/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /*
    // Solution 1
    // T: O(n)
    // S: O(n)
    int findPairs(vector<int>& nums, int k) {
        unordered_set<int> vis, dif;

        for (const int &num : nums) {
            if (vis.find(num - k) != vis.end()) {
                dif.insert(num - k);
            }

            if (vis.find(num + k) != vis.end()) {
                dif.insert(num);
            }

            vis.insert(num);
        }
        return dif.size();
    }
    */

    // Solution 2: one hash data structure, less time and memory for hashing
    // T: O(n)
    // S: O(n)
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (const int &num : nums) {
            ++mp[num];  // counts numbers and avoids duplicates
        }

        int ans = 0;
        if (!k) {
            // Trivial case
            for (const auto &p : mp) {
                // To form a pair, the number must have > 1 occurrence.
                // Since the pair must be unique, just need to check
                // if the count > 1.
                ans += (p.second > 1);
            }
        } else {
            for (const auto &p : mp) {
                ans += (mp.find(p.first + k) != mp.end());
            }
        }

        return ans;
    }
};
// @lc code=end

