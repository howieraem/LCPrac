/*
 * @lc app=leetcode.cn id=189 lang=java
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
    public void rotate(int[] nums, int k) {
        int n = nums.length;
        k %= n;
        int count = 0;  // record swapping times
        for (int start = 0; count < n; ++start) {
            /* Loop while count < n to ensure every number has been 
            iterated through and swapped. */
            int cur = start, pre = nums[cur];
            do {
                int nxt = (cur + k) % n;
                int tmp = nums[nxt];
                nums[nxt] = pre;
                pre = tmp;
                cur = nxt;
                count++;
            } while (start != cur);  // back to the initial index
        }
    }
}
// @lc code=end
