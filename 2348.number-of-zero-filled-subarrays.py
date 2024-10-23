from typing import List


class Solution:
    # T: O(n)
    # S: O(1)
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ans = 0
        cur_zero_subarray_len = 0

        for num in nums:
            if num == 0:
                cur_zero_subarray_len += 1

                # simple dp/math: if subarr len extends by 1, new subarrs: 
                # nums[j-len(subarr)+1:j+1], nums[j-len(subarr)+2:j+1], ..., nums[j:j+1]
                ans += cur_zero_subarray_len
            else:
                cur_zero_subarray_len = 0

        return ans
