import java.util.*;

/*
 * @lc app=leetcode.cn id=496 lang=java
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] res = new int[nums1.length];
        Stack<Integer> s = new Stack<>();
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums2.length; ++i) {
            while (!s.empty() && s.peek() < nums2[i]) {
                map.put(s.pop(), nums2[i]);
            }
            s.push(nums2[i]);
        }
        while (!s.empty()) {
            map.put(s.pop(), -1);
        }
        for (int i = 0; i < nums1.length; ++i) {
            // nums1 is a subset of nums2 and the latter has no duplicate, so
            // all nums1 elements are in the keyset and have 1-to-1 relation
            // with their next greater elements.
            res[i] = map.get(nums1[i]);
        }
        return res;
    }
}
// @lc code=end

