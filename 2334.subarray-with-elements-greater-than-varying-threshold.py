from typing import List

class Solution:
    # Mono-stack
    # T: O(n)
    # S: O(n)
    def validSubarraySize(self, nums: List[int], threshold: int) -> int:
        # Find the minimum in subarray and expand that subarray as much as possible
        # so that threshold / k is smaller
        N = len(nums)

        stk = []  # indexes, corresponding numbers should be monotonically increasing
        
        next_smaller = [-1] * N
        for i in range(N):
            while len(stk) != 0 and nums[i] < nums[stk[-1]]:
                next_smaller[stk.pop()] = i
            stk.append(i)

        stk.clear()
        
        prev_smaller = [-1] * N
        for i in range(N - 1, -1, -1):
            while len(stk) != 0 and nums[i] < nums[stk[-1]]:
                prev_smaller[stk.pop()] = i
            stk.append(i)

        for i in range(N):
            l = prev_smaller[i]
            r = N if next_smaller[i] == -1 else next_smaller[i]
            k = r - l - 1  # subarray with length k and nums[i] as minimum
            if nums[i] > threshold / k:
                return k
        
        return -1
