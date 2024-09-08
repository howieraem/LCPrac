from typing import List

class Solution:
    # Greedy
    # T: O(n)
    # S: O(1)
    def findMaximumScore(self, nums: List[int]) -> int:
        n = len(nums)
        pre = 0
        ans = 0

        """
        Jump iff nums[i] at the next step is greater. Proof:
        Suppose i < j < k. To maximize the score, we need 
        (j - i) * nums[i] + (k - j) * nums[j] > (k - i) * nums[i]
        Rearrange:
        (j - k) * nums[i] + (k - j) * nums[j] > 0
        (k - j) * nums[i] < (k - j) * nums[j]
        nums[i] < nums[j]
        """
        for i in range(n):
            if i == n - 1 or nums[i] > nums[pre]:
                ans += (i - pre) * nums[pre]
                pre = i
        return ans
