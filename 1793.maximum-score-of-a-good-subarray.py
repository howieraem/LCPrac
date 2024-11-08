#
# @lc app=leetcode id=1793 lang=python3
#
# [1793] Maximum Score of a Good Subarray
#
from typing import *

# @lc code=start
class Solution:
    '''
    # Solution 1: mono-stack
    # Variant of Q84
    # T: O(n)
    # S: O(n)
    def maximumScore(self, nums: List[int], k: int) -> int:
        ans = 0

        # avoid an extra while loop after the for loop to check the last few subarrays
        nums.append(0)
        
        # Stores indexes of corresponding numbers ordered ASC
        # Dummy index -1 added for edge case like nums[0] is the minimum
        st = [-1]

        for i in range(len(nums)):
            while len(st) > 0 and nums[st[-1]] > nums[i]:
                subarr_min = nums[st.pop()]
                if st[-1] < k < i:
                    ans = max(ans, (i - st[-1] - 1) * subarr_min)

            st.append(i)

        return ans
    '''
    
    # Solution 2: two pointers (expanding window) + greedy
    # T: O(n)
    # S: O(1)
    def maximumScore(self, nums: List[int], k: int) -> int:
        n = len(nums)
        k = max(0, min(k, n - 1))
        
        # start base window at index k with width 1
        l = k
        r = k
        ans = nums[k]   # IMPORTANT: handle edge case like nums = [x] and k = 0
        cur_min = nums[k]

        # gradually expand the window to both sides
        while l > 0 or r < n - 1:
            if l == 0:
                r += 1
            elif r == n - 1:
                l -= 1
            elif nums[l - 1] < nums[r + 1]:
                # keep left side as the min, and expand to the right
                r += 1
            else:
                # keep right side as the min, and expand to the left
                l -= 1
            
            cur_min = min(cur_min, nums[l], nums[r])
            ans = max(ans, cur_min * (r - l + 1))

        return ans
        

        
# @lc code=end

