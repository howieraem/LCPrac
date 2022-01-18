#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#
from collections import deque

# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        """Amortized analysis: every element only gets enqueued/dequeued once,
        so O(N) time complexity."""
        # The hard part is to find maximum in a window in O(1) time. 
        # Use deque as a mono-queue.
        dq = deque()
        res = []
        for i, num in enumerate(nums):
            if dq and dq[0] <= i-k:
                dq.popleft()    # remove last left most index
            while dq and num > nums[dq[-1]]:
                # remove the indices of elements that are less than current number
                dq.pop()
            dq.append(i)
            if i >= k-1:
                res.append(nums[dq[0]])     # dq[0] is always the index of maximum in a window
        return res

# @lc code=end

