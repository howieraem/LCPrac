#
# @lc app=leetcode id=2030 lang=python3
#
# [2030] Smallest K-Length Subsequence With Occurrences of a Letter
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def smallestSubsequence(self, s: str, k: int, letter: str, repetition: int) -> str:
        avail = s.count(letter)
        stack = []  # mono-stack of chars to store the intermediate subseq

        for i, c in enumerate(s):
            while (len(stack) 
                   # If the subseq can be lexicographically smaller by replacing the last char
                   and stack[-1] > c  
                   # If there are enough chars remaining to construct the k-size string
                   and len(stack) + (len(s) - i) > k 
                   # If the char to be popped equals `letter`, then there must be available `letter` chars remaining, 
                   # as one `letter` char needs to be re-added to the stack later
                   and (stack[-1] != letter or avail > repetition)):
                repetition += (stack.pop() == letter)
                
            if len(stack) < k:
                if c == letter:
                    stack.append(c)
                    repetition -= 1
                elif len(stack) + repetition < k:
                    # Not enough chars in current subseq, need to append a char 
                    # even if not equal to `letter`
                    stack.append(c)

            avail -= (c == letter)  # can only use the `letter` chars not yet iterated
        
        return "".join(stack)

# @lc code=end

