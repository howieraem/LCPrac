#
# @lc app=leetcode id=1888 lang=python3
#
# [1888] Minimum Number of Flips to Make the Binary String Alternating
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(1)
    def minFlips(self, s: str) -> int:
        # For op1, can simulate by "appending" s to its right, i.e. s += s
        # Then we make the resulted string to start with either 0101... or 
        # 1010...
        # Use a sliding window with fixed size len(s) to determine which of 
        # the two results above takes less op2.
        n = len(s)

        ans1 = 0
        ans2 = 0
        ans = float('inf')
        for r in range(n << 1):
            c_r = int(s[r % n])
            ans1 += ((r & 1) != c_r)
            ans2 += (((r + 1) & 1) != c_r)
            if r >= n - 1:
                if r >= n:
                    l = r - n
                    c_l = int(s[l % n])
                    ans1 -= ((l & 1) != c_l)
                    ans2 -= (((l + 1) & 1) != c_l)
                ans = min(ans, ans1, ans2)

        return ans

         
# @lc code=end

