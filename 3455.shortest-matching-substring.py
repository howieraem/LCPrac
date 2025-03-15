class Solution:
    # KMP
    # T: O(m + n)
    # S: O(m + n)
    def shortestMatchingSubstring(self, s: str, p: str) -> int:
        n = len(p)
        if n == 2:
            return 0
        
        m = len(s)
        
        # split pattern into 3 parts:
        # - a: sub-pattern prior to the first '*'
        # - b: sub-pattern between the two '*'s
        # - c: sub-pattern behind the second '*'
        parts = p.split('*')
        if len(parts) != 3:
            return -1
        a, b, c = parts
        na = len(a)
        nb = len(b)
        nc = len(c)

        def get_lps(p):
            n = len(p)
            lps = [0] * n
            i = 1
            j = 0
            while i < n:
                if p[i] == p[j]:
                    lps[i] = j + 1
                    i += 1
                    j += 1
                elif j > 0:
                    j = lps[j - 1]
                else:
                    i += 1
            return lps

        # Find lps of sub-patterns a, b and c in s    
        lps_a = get_lps(a + '#' + s)[na + 1:]
        lps_b = get_lps(b + '#' + s)[nb + 1:]
        lps_c = get_lps(c + '#' + s)[nc + 1:]
        
        i = 0
        j = 0
        k = 0
        ans = m + 1

        # For index i in lps_a, find index j in lps_b such that gap between i and j is at least nb. 
        # Similarly, find index k in lps_c such that gap between j and k is at least nc.
        while i + nb + nc < len(lps_a):
            while i < len(lps_a) and lps_a[i] != na:
                i += 1
            if i >= len(lps_a):
                break

            while j < len(lps_b) and (j < i + nb or lps_b[j] != nb):
                j += 1
            if j >= len(lps_b):
                break

            while k < len(lps_c) and (k < j + nc or lps_c[k] != nc):
                k += 1
            if k >= len(lps_c):
                break

            ans = min(ans, k - i + na)
            i += 1

        return ans if ans != m + 1 else -1
