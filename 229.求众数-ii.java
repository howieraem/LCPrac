import java.util.ArrayList;
import java.util.List;
/*
 * @lc app=leetcode.cn id=229 lang=java
 *
 * [229] 求众数 II
 */

// @lc code=start
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> res = new ArrayList<>();
        if (nums == null || nums.length == 0)  return res;
        int candidate1 = nums[0], cnt1 = 0;
        int candidate2 = nums[0], cnt2 = 0;

        // find candidates possibly appears more than n//3 times
        for (int num : nums) {
            if (candidate1 == num) {
                ++cnt1;
                continue;
            }
            if (candidate2 == num) {
                ++cnt2;
                continue;
            }
            if (cnt1 == 0) {
                candidate1 = num;
                ++cnt1;
                continue;
            }
            if (cnt2 == 0) {
                candidate2 = num;
                ++cnt2;
                continue;
            }
            --cnt1;
            --cnt2;
        }

        // check the actual count of candidates
        cnt1 = 0;
        cnt2 = 0;
        for (int num : nums)  {
            if (candidate1 == num)  ++cnt1;
            else if (candidate2 == num)  ++cnt2;
        }
        int minCnt = nums.length / 3;
        if (cnt1 > minCnt)  res.add(candidate1);
        if (cnt2 > minCnt)  res.add(candidate2);
        return res;
    }
}
// @lc code=end

