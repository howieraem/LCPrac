#
# @lc app=leetcode id=2002 lang=python3
#
# [2002] Maximum Product of the Length of Two Palindromic Subsequences
#

# @lc code=start
class Solution:
    # Bitmask: 1 means that the char is used in a subsequence, 0 otherwise.
    # Because the maximum len(s) is relatively small, this solution is acceptable
    # T: O(n * 2 ^ n), n := len(s)
    # S: O(2 ^ n)
    def maxProduct(self, s: str) -> int:
        n = len(s)
        mask_lens = []

        # Enumerate all possible subseqs
        for mask in range(1, 1 << n):
            subseq = []

            for i in range(n):
                if mask & (1 << i) > 0:
                    # convert bitmask to string subseq
                    subseq.append(s[i])

            if subseq == subseq[::-1]:
                # Palindrome
                mask_lens.append((mask, len(subseq)))

        mask_lens.sort(key = lambda p: p[1], reverse=True)
        ans = 1
        for i in range(len(mask_lens)):
            mask1, len1 = mask_lens[i]
            if len1 * len1 < ans:
                # as mask_lens is sorted by lengths DESC, no need to loop through bitmasks of 
                # the shorter subseqs
                break
            
            for j in range(i + 1, len(mask_lens)):
                mask2, len2 = mask_lens[j]

                if mask1 & mask2 == 0:
                    # update only when disjoint and product is greater
                    ans = max(ans, len1 * len2)

                    # as mask_lens is sorted by lengths DESC, no need to loop through bitmasks of 
                    # the shorter subseqs
                    break

        return ans

        
# @lc code=end

