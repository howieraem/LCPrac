class Solution:
    # two pointers
    # T: O(n)
    # S: O(n) immutable string
    def isOneEditDistance(self, s: str, t: str) -> bool:
        # always make s the shorter string
        if len(s) > len(t):
            s, t = t, s

        m = len(s)
        n = len(t)
        if n - m > 1:
            # rule out edit distance > 1 cases
            return False

        for i in range(m):
            if s[i] != t[i]:
                return s[i + 1:] == t[i + 1:] if m == n \
                    else s[i:] == t[i + 1:]

        # s = t[:-1]
        # The strings are one edit away iff
        # t has one more character.
        return m + 1 == n
