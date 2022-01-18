import java.util.*;

/*
 * @lc app=leetcode.cn id=18 lang=java
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        if (n < 4)  return res;
        Arrays.sort(nums);
        int w, x, y, z;
        for (int i = 0; i < n - 3; ++i) {
            w = nums[i];
            if (i > 0 && w == nums[i - 1])  continue;
            for (int j = i + 1; j < n - 2; ++j) {
                x = nums[j];
                if (j > i + 1 && x == nums[j - 1])  continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    y = nums[l];
                    z = nums[r];
                    int s = w + x + y + z;
                    if (s == target) {
                        res.add(new ArrayList<>(Arrays.asList(w, x, y, z)));
                        while (l < r && nums[l + 1] == nums[l]) ++l;
                        while (l < r && nums[r - 1] == nums[r]) --r;
                        ++l;
                        --r;
                    } else if (s > target) {
                        --r;
                    } else {
                        ++l;
                    }
                }
            }
        }
        return res;
    }
}
// @lc code=end

