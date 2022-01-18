/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    // Almost the same as Q473 except that the number of partitions is variable
    // T: O(k ^ n)
    // S: O(1)
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int n = nums.size();

        // Prune some trivial cases
        int sum = 0;
        for (const int &num : nums) {
            sum += num;
        }
        if (sum % k)  return false;
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > target)  return false;

        bool vis[n];    // avoid using vector<bool>
        fill_n(vis, n, false);
        return backtrack(nums, 0, target, 0, k, vis);
    }

private:
    static bool backtrack(const vector<int> &nums, int start, const int &target, int cur, int k, bool vis[]) {
        if (k == 1)  return true;
        if (cur == target) {
            // partition
            return backtrack(nums, 0, target, 0, k - 1, vis);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i])  continue;
            int tmp = cur + nums[i];
            if (tmp > target)  continue;    // prune, try smaller numbers instead
            vis[i] = true;
            if (backtrack(nums, i + 1, target, tmp, k, vis)) {
                return true;
            }
            vis[i] = false;
            // prune, skip duplicates
            while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                ++i;
            }
        }
        return false;
    }
};
// @lc code=end

