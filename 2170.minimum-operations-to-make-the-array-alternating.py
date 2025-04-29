from collections import defaultdict
from typing import *


class Solution:
    # Hash Map + Greedy?
    # T: O(n)
    # S: O(n)
    def minimumOperations(self, nums: List[int]) -> int:
        """
        For the 1st requirement nums[i - 2] == nums[i], we need to get the max freq 
        for both of the odd & even idx in order to get the result: 
            (total numbers in odd idx - max freq in odd) + (total numbers in even idx - max freq in even)
        
        Now consider the 2nd requirement nums[i] != nums[i-1], and what if the number with the max freq 
        is same for both of the even/odd idx? Then we either change the numbers with max freq in odd idx 
        or change the numbers with max freq in even idx and that's why we need to introduce the second 
        max freq for both of the odd & even.
        
        So the result will be one of the following:
        - (total numbers in odd idx - max freq in odd) + (total numbers in even idx - max freq in even) 
          when the max freq num is not the same in both of the even and odd idx
        - min(total number in odd idx - second max freq in odd + total numbers in even - max freq in even, 
              total numbers in even idx - second freq in even + total numbers in odd idx - max freq in odd)
        """
        even_start_res = self.__get_top2_freq(nums, 0)
        odd_start_res = self.__get_top2_freq(nums, 1)

        if even_start_res[0] != odd_start_res[0]:
            return len(nums) - (even_start_res[1] + odd_start_res[1])

        return len(nums) - max(even_start_res[1] + odd_start_res[2],
                               even_start_res[2] + odd_start_res[1])

    @staticmethod
    def __get_top2_freq(nums: List[int], start: int) -> Tuple[int, int, int]:
        x1 = 0
        x2 = 0
        cnts = defaultdict(int)
        for i in range(start, len(nums), 2):
            cnts[nums[i]] += 1
            new_cnt = cnts[nums[i]]
            if new_cnt >= cnts[x1]:
                if nums[i] != x1:
                    x2 = x1
                x1 = nums[i]
            elif new_cnt > cnts[x2]:
                x2 = nums[i]

        return x1, cnts[x1], cnts[x2]
