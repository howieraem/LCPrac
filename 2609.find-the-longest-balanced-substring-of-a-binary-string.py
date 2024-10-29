class Solution:
    # pointer (implicit sliding window?) + counter
    # T: O(n)
    # S: O(1)
    def findTheLongestBalancedSubstring(self, s: str) -> int:
        ans = 0
        i = 0
        n = len(s)

        while i < n:
            count0 = 0
            count1 = 0

            # move pointer until anti-pattern '10' is encountered
            while i < n and s[i] == '0':
                count0 += 1
                i += 1
            while i < n and s[i] == '1':
                count1 += 1
                i += 1

            ans = max(ans, min(count0, count1) << 1)

        return ans
