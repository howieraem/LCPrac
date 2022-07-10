/*
 * @lc app=leetcode id=2150 lang=cpp
 *
 * [2150] Find All Lonely Numbers in the Array
 */
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // T: O(n)
    // S: O(n)
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (const int &num : nums) {
            ++mp[num];
        }
        
        vector<int> res;
        for (const auto &p : mp) {
            if (p.second == 1 && mp.find(p.first - 1) == mp.end() && mp.find(p.first + 1) == mp.end()) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};
// @lc code=end
