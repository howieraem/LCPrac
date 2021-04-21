import java.util.Map;
import java.util.HashMap;

/*
 * @lc app=leetcode.cn id=220 lang=java
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
    // be aware of integer overflow
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        int n = nums.length;
        Map<Long, Long> map = new HashMap<Long, Long>();
        long w = (long) t + 1;
        for (int i = 0; i < n; i++) {
            long num = nums[i], id = getBucketID(num, w);
            if (map.containsKey(id) || 
                (map.containsKey(id - 1) && Math.abs(num - map.get(id - 1)) <= t) ||
                (map.containsKey(id + 1) && Math.abs(num - map.get(id + 1)) <= t)
                ) {
                // Once a bucket is added, the number in bucket will not be 
                // overwritten by a new number because the difference 
                // between them is less than or equal to t
                return true;
            }
            map.put(id, num);   // Add a new bucket
            if (i >= k) {
                map.remove(getBucketID(nums[i - k], w));
            }
        }
        return false;
    }

    public long getBucketID(long x, long w) {
        // be aware of integer overflow
        return x >= 0 ? x / w : (x + 1) / w - 1;
    }
}
// @lc code=end

