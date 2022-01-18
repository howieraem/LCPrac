/*
 * @lc app=leetcode.cn id=349 lang=java
 *
 * [349] 两个数组的交集
 */
import java.util.HashSet;


// @lc code=start
class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums1) {
            set.add(num);
        }

        HashSet<Integer> intersect = new HashSet<>();
        for (int num : nums2) {
            if (set.contains(num))  intersect.add(num);
        }
        
        return intersect.stream().mapToInt(Integer::intValue).toArray();
    }
}
// @lc code=end

