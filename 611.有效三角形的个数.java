import java.util.Arrays;

/*
 * @lc app=leetcode.cn id=611 lang=java
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);  // O(NlogN)
        int ans = 0;

        // Iterate one side + dual pointers for the other two sides, O(N^2)
        // A trick here is to iterate the longest side a reversely,
        // and then find b and c such that b + c > a, which will 
        // implicitly satisfy a + c > b and a + b > c
        for (int i = nums.length - 1; i >= 2; --i) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    ans += (r - l);
                    --r;
                } else {
                    ++l;
                }
            }
        }
        return ans;
    }
}
// @lc code=end

