class Solution:
    # Regex + two pointers
    # T: O(m * n)
    # S: O(n) python substring copying
    def hasMatch(self, s: str, p: str) -> bool:
        try:
            star_idx = p.index('*')
            l = s.index(p[:star_idx])
            r = s.index(p[star_idx + 1:], l + star_idx)  # 2nd arg is from_index
        except ValueError:
            # if any of the substrings above not found
            return False
        return True
