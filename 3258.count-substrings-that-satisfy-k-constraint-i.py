class Solution:
    # T: O(len(s))
    # S: O(1)
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        l = 0
        counts = [0, 0]
        ans = 0
        for r in range(n):
            counts[int(s[r])] += 1

            while counts[0] > k and counts[1] > k:
                counts[int(s[l])] -= 1
                l += 1

            ans += (r - l + 1)
        
        return ans
