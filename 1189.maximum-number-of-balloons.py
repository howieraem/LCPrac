#
# @lc app=leetcode id=1189 lang=python3
#
# [1189] Maximum Number of Balloons
#

# @lc code=start
OFFSET = ord('a')

class Solution:
    # hash map + greedy
    # T: O(n + alpha_size)
    # S: O(alpha_size)
    def maxNumberOfBalloons(self, text: str) -> int:
        # count char in text
        freqs = [0] * 26
        for c in text:
            freqs[ord(c) - OFFSET] += 1
        
        # check count for each type of char in target word
        return min(
                freqs[0],  # char a
                freqs[1],  # char b
                freqs[11] >> 1,  # char l
                freqs[13],  # char n
                freqs[14] >> 1,  # char o
        )

    # follow-up: arbitrary target word, Q2287

# @lc code=end

