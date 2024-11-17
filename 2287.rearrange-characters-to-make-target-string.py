OFFSET = ord('a')

class Solution:
    # hash map + greedy
    # T: O(len(s) + len(target) + alpha_size)
    # S: O(alpha_size)
    def rearrangeCharacters(self, s: str, target: str) -> int:
        if len(s) == 0 or len(target) == 0:
            return 0

        # count char in text
        freqs = [0] * 26
        for c in s:
            freqs[ord(c) - OFFSET] += 1

        # count char in target
        freqs_target = [0] * 26
        for c in target:
            freqs_target[ord(c) - OFFSET] += 1
        
        # find the minimum multiple
        return min(freqs[i] // freqs_target[i] 
                   for i in range(26) if freqs_target[i] != 0)
