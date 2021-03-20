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
        for (const int& num:nums) {
            sum += num;
            if (mp.count(sum-k)) {
                cnt += mp[sum-k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
// @lc code=end

