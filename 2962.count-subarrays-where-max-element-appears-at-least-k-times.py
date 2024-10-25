from typing import List

class Solution:
    # Sliding window
    # T: O(n)
    # S: O(1)
    def countSubarrays(self, nums: List[int], k: int) -> int:
        if len(nums) == 0 or k < 0:
            return 0
        max_x = float('-inf')
        max_x_cnt = 0
        for x in nums:
            if x > max_x:
                max_x = x
                max_x_cnt = 1
            elif x == max_x:
                max_x_cnt += 1

        if max_x_cnt < k:
            return 0

        window_max_x_cnt = 0
        ans = 0
        l = 0
        for r in range(len(nums)):
            window_max_x_cnt += (nums[r] == max_x)

            while window_max_x_cnt >= k:
                window_max_x_cnt -= (nums[l] == max_x)
                l += 1
            
            # IMPORTANT: different from window sum/product and distinct types cases:
            # The no. of eligible subarrs is l, because there are l subarrs of nums[:l], 
            # concatenating nums[l:r+1] (fixed) to form the complete feasible subarr
            ans += l
        
        return ans
