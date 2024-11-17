#
# @lc app=leetcode id=659 lang=python3
#
# [659] Split Array into Consecutive Subsequences
#
from typing import *

# @lc code=start
class Solution:
    # Greedy + 1D DP + counter
    # T: O(n)
    # S: O(1)
    def isPossible(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3:
            return False
        
        pre = None
        n_len1_seq_end_at_pre = 0  # number of length 1 sequence ending at previous value
        n_len2_seq_end_at_pre = 0  # number of length 2 sequence ending at previous value
        n_len3p_seq_end_at_pre = 0  # number of length 3+ sequence ending at previous value

        i = 0
        while i < n:
            cur = nums[i]

            cnt_cur = 0
            while i < n and nums[i] == cur:
                cnt_cur += 1
                i += 1

            if pre is None or cur != pre + 1:
                # there shall be no length 1 or 2 sequences ending at previous value
                if n_len1_seq_end_at_pre > 0 or n_len2_seq_end_at_pre > 0:
                    return False
                
                # sequences ending with cur
                n_len1_seq_end_at_cur = cnt_cur
                n_len2_seq_end_at_cur = 0
                n_len3p_seq_end_at_cur = 0

            else:  # cur = pre + 1, try extending the sequence
                # If there are not enough values to fill the previous length 1 and
                # length 2 sequences, return false
                if n_len1_seq_end_at_pre + n_len2_seq_end_at_pre > cnt_cur:
                    return False

                # highest priority will be given to previous length 1 sequences
                n_len2_seq_end_at_cur = n_len1_seq_end_at_pre

                # then priority will be given to previous length 2 sequences
                # if there are still some remaining, to the previous length 3
                # sequences as well
                n_len3p_seq_end_at_cur = n_len2_seq_end_at_pre + \
                        min(n_len3p_seq_end_at_pre, cnt_cur - n_len1_seq_end_at_pre - n_len2_seq_end_at_pre)
                
                # if there are even some values left after we fill length 1,2,3
                # sequences, then these values have to become the start of new
                # length 1 sequences
                n_len1_seq_end_at_cur = max(0, cnt_cur - n_len1_seq_end_at_pre - n_len2_seq_end_at_pre - n_len3p_seq_end_at_pre)

            # rolling update
            pre = cur
            n_len1_seq_end_at_pre = n_len1_seq_end_at_cur
            n_len2_seq_end_at_pre = n_len2_seq_end_at_cur
            n_len3p_seq_end_at_pre = n_len3p_seq_end_at_cur

        # all sequences at this stage should have length >= 3
        return n_len1_seq_end_at_pre == 0 and n_len2_seq_end_at_pre == 0

# @lc code=end

