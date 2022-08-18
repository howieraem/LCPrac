#
# @lc app=leetcode id=1328 lang=python3
#
# [1328] Break a Palindrome
#

# @lc code=start
class Solution:
    # T: O(n)
    # S: O(n)
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        if n <= 1:
            return ""
        arr = list(palindrome)
        for i in range(n >> 1):
            if arr[i] != 'a':
                arr[i] = 'a'
                return "".join(arr)
        arr[n - 1] = 'b'
        return "".join(arr)

        
# @lc code=end

