/*
 * @lc app=leetcode.cn id=165 lang=java
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] nums1 = version1.split("\\."), nums2 = version2.split("\\.");
        int i = 0, j = 0;
        while (i < nums1.length || j < nums2.length) {
            int v1 = i < nums1.length ? Integer.parseInt(nums1[i]) : 0;
            int v2 = j < nums2.length ? Integer.parseInt(nums2[i]) : 0;
            if (v1 < v2)  return -1;
            else if (v1 > v2)  return 1;
            ++i; 
            ++j;
        }
        return 0;
    }
}
// @lc code=end

