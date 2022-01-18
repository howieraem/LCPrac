/*
 * @lc app=leetcode.cn id=215 lang=java
 *
 * [215] 数组中的第K个最大元素
 */
import java.util.*;


// @lc code=start
class Solution {
    /*
    // Min heap
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int val : nums) {
            // 初始化堆
            if (pq.size() < k) {
                pq.add(val);
            } else {
                Integer peek = pq.peek();
                if (val > peek) {
                    pq.add(val);
                    pq.poll();
                }
            }
        }
        return pq.peek(); // 取出堆顶node不删除
    }
    */

    /** Quick select */
    private static Random random = new Random(System.currentTimeMillis());

    public int findKthLargest(int[] nums, int k) {
        int len = nums.length;
        int target = len - k;   // if `nums` is sorted, the kth largest is at index `len-k`
        int left = 0;
        int right = len - 1;
        while (true) {
            int index = partition(nums, left, right);
            if (index < target) {
                left = index + 1;  // discard elements less than pivot
            } else if (index > target) {
                right = index - 1;  // discard elements greater than pivot
            } else {
                return nums[index];
            }
        }
    }

    /** 在区间 [left, right] 这个区间执行 partition 操作 */
    private int partition(int[] nums, int left, int right) {
        // 在区间随机选择一个元素作为标定点
        if (right > left) {
            int randomIndex = left + 1 + random.nextInt(right - left);
            swap(nums, left, randomIndex);
        }

        int pivot = nums[left];
        int j = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < pivot) {
                j++;
                swap(nums, j, i);
            }
        }
        swap(nums, left, j);
        // After this point, numbers to the left of pivot are all less than pivot,
        // and numbers to the right of pivot are all greater than pivot.
        // More importantly, pivot is now at the same position as where it is
        // when the array is sorted.
        // Then, if the pivot was not a bad choice (left/right boundary), one side 
        // of the pivot can be ignored.
        return j;
    }

    private void swap(int[] nums, int i, int j) {
        if (i != j) {
            nums[i] ^= nums[j];
            nums[j] ^= nums[i];
            nums[i] ^= nums[j];
        }
    }
}
// @lc code=end
