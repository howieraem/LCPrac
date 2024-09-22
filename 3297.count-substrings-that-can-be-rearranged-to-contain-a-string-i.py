class Solution:
    # T: O(n + k)
    # S: O(alpha_size)
    def validSubstringCount(self, word1: str, word2: str) -> int:
        n, k = len(word1), len(word2)
        if k > n:
            return 0
        OFFSET = ord('a')
        s1 = [ord(c) - OFFSET for c in word1]
        s2 = [ord(c) - OFFSET for c in word2]

        cnts = [0] * 26
        for c in s2:
            cnts[c] += 1

        window_cnts = [0] * 26

        ans = 0
        l = 0

        # Use auxiliary number k, so there is no need to check 
        # all(v1 >= v2 for v1, v2 in zip(window_cnts, cnts)) 
        for r in range(n):
            c = s1[r]
            if cnts[c] > 0 and window_cnts[c] < cnts[c]:
                k -= 1
            
            window_cnts[c] += 1

            while k == 0:  
                # window contains required counts of chars in word2
                ans += n - r  # IMPORTANT: count possible substrs with the window as prefix

                pre = s1[l]
                window_cnts[pre] -= 1

                if cnts[pre] > 0 and window_cnts[pre] < cnts[pre]:
                    k += 1
                
                l += 1
        
        return ans
