#
# @lc app=leetcode id=727 lang=python3
#
# [727] Minimum Window Subsequence
#

# @lc code=start
class Solution:
    # Two pointers
    # T: O(m ^ 2) worst, O(m * n) on average
    # S: O(1)
    def minWindow(self, s1: str, s2: str) -> str:
        m = len(s1)
        n = len(s2)
        i = 0
        j = 0
        min_len = m + 1
        min_subseq_start = -1

        while i < m:
            if s1[i] == s2[j]:
                j += 1
                
                if j == n:
                    # Found a valid subseq in s1
                    subseq_end = i + 1

                    # Try to shorten the subseq by checking 
                    # characters reversely
                    j = n - 1
                    subseq_start = subseq_end - 1
                    while j >= 0:
                        if s1[subseq_start] == s2[j]:
                            j -= 1
                        if j >= 0:
                            subseq_start -= 1

                    # Update answer
                    new_len = subseq_end - subseq_start
                    if new_len < min_len:
                        min_len = new_len
                        min_subseq_start = subseq_start

                    # Update pointer of s1 to search for next subseq (will add 1 below). 
                    # j should be 0 at this point.
                    i = subseq_start

            i += 1

        return s1[min_subseq_start:min_subseq_start + min_len] if min_subseq_start != -1 else ""

        
# @lc code=end

