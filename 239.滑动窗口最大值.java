import java.util.LinkedList;

/*
 * @lc app=leetcode.cn id=239 lang=java
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class MonoQueue {
    LinkedList<Integer> q;

    public MonoQueue() {
        q = new LinkedList<>();
    }

    public void push(int n) {
        while (!q.isEmpty() && q.getLast() < n) {
            q.pollLast();
        }
        q.addLast(n);
    }

    public int max() {
        return q.getFirst();
    }

    public void pop(int n) {
        if (n == q.getFirst()) {
            q.pollFirst();
        }
    }
}

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        MonoQueue window = new MonoQueue();
        int[] res = new int[nums.length - k + 1];   // total number of windows is n-k+1 when stride is 1
        int j = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (i < k - 1) {
                // fill the first k-1 elements in window
                window.push(nums[i]);
            } else {
                window.push(nums[i]);
                res[j] = window.max();
                window.pop(nums[i - k + 1]);    // remove the left most number
                ++j;
            }
        }
        return res;
    }
}
// @lc code=end

