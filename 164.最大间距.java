/*
 * @lc app=leetcode.cn id=164 lang=java
 *
 * [164] 最大间距
 */

// @lc code=start
/** 桶结构，桶内只关心最大值、最小值 */
class Bucket {
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
}


class Solution {
    /** Solution with bucket sort (near linear complexity). */
    public int maximumGap(int[] nums) {
        if (nums == null || nums.length < 2)  return 0;
        // Calculate extrema of array
        int max = 0, min = 0;
        for (int num : nums) {
            max = Math.max(max, num);
            min = Math.min(min, num);
        }
        
        // Create buckets
        int bucketSize = Math.max(1, (max - min) / (nums.length - 1));
        Bucket[] buckets = new Bucket[(max - min) / bucketSize + 1];
        
        // Update bucket values
        for (int i = 0; i < nums.length; ++i) {
            int bucketIdx = (nums[i] - min) / bucketSize;
            if (buckets[bucketIdx] == null)  buckets[bucketIdx] = new Bucket();
            buckets[bucketIdx].max = Math.max(buckets[bucketIdx].max, nums[i]);
            buckets[bucketIdx].min = Math.min(buckets[bucketIdx].min, nums[i]);
        }

        // Find the maximum gap
        int preMax = -1, ans = 0;
        for (int i = 0; i < buckets.length; ++i) {
            if (buckets[i] != null) {
                if (preMax != -1) {
                    // max_gap >= avg_gap = (max - min) / (nums.length - 1) > (bucket.max - bucket.min)
                    ans = Math.max(ans, buckets[i].min - preMax);
                }
                preMax = buckets[i].max;
            }
        }
        return ans;
    }
}
// @lc code=end

