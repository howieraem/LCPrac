import java.util.*;

/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        if (n < 3)  return res;
        Arrays.sort(nums);  // O(N*log(N))

        for (int i = 0; i < n - 2; ++i) {
            int x = nums[i];
            if (x > 0)  return res; // after sorting, sum of any 3 nums to the right of x always > 0
            if (i > 0 && nums[i - 1] == x)  continue;   // skip duplicates
            int l = i + 1, r = n - 1;
            while (l < r) {
                int y = nums[l], z = nums[r];
                int sum = x + y + z;
                if (sum == 0) {
                    res.add(new ArrayList<>(Arrays.asList(x, y, z)));
                    while (l < r && nums[l + 1] == nums[l])  ++l;
                    while (l < r && nums[r - 1] == nums[r])  --r;
                    ++l;
                    --r;
                } else if (sum > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return res;
    }
}
// @lc code=end

