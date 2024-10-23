class Solution(object):
    # T: O(n)
    # S: O(alpha_size)
    def partitionString(self, s):
        """
        :type s: str
        :rtype: int
        """
        seen = set()  # or a boolean array for limited alpha size
        ans = 0
        for c in s:
            if c in seen:  
                # Greedy: partition whenever a kind of char appears again
                seen.clear()
                ans += 1
            seen.add(c)
        return ans + 1  # don't forget the last partition
