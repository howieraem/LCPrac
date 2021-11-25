/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int cnt = 0, sum = 0;

        // below is somehow faster than `for (auto &n : nums)`
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (mp.find(sum - k) != mp.end()) {
                cnt += mp[sum - k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
// @lc code=end

