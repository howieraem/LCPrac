from typing import *

OFFSET = ord('a')

class Solution:
    # hash maps
    # T: O(sum(len(w) for w in words) + len(chars) + alpha_size)
    # S: O(alpha_size)
    def countCharacters(self, words: List[str], chars: str) -> int:
        freqs = [0] * 26
        for c in chars:
            freqs[ord(c) - OFFSET] += 1

        ans = 0
        # Check for each word whether chars freqs can satisfy
        # instead of creating another counter for each word.
        # This approach works better if len(w) > alpha_size
        for w in words:
            freqs_copy = freqs[:]
            is_good = True
            for c in w:
                cidx = ord(c) - OFFSET
                if freqs_copy[cidx] == 0:
                    is_good = False
                    break
                freqs_copy[cidx] -= 1
            
            if is_good:
                ans += len(w)

        return ans