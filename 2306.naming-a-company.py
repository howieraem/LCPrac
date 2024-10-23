from typing import List

class Solution:
    # T: O(alpha_size * len(ideas))
    # S: O(alpha_size * len(ideas))
    def distinctNames(self, ideas: List[str]) -> int:
        OFFSET = ord('a')
        letter1_to_suffixes = [set() for _ in range(26)]
        for idea in ideas:
            letter1, suffix = idea[0], idea[1:]
            letter1_to_suffixes[ord(letter1) - OFFSET].add(suffix)
        
        ans = 0

        # If two ideas ideas[i] and ideas[j] share a common suffix,
        # then ideas[i] can't be paired with any idea starts with the first letter of ideas[j]
        # and ideas[j] can't be paired with any idea starts with the first letter of ideas[i]
        for i in range(25):
            for j in range(i + 1, 26):
                eligible1 = 0
                for suffix in letter1_to_suffixes[i]:
                    eligible1 += (suffix not in letter1_to_suffixes[j])

                eligible2 = 0
                for suffix in letter1_to_suffixes[j]:
                    eligible2 += (suffix not in letter1_to_suffixes[i])
    
                ans += ((eligible1 * eligible2) << 1)  # mult by 2 because if (A, B) is valid then (B, A) is also valid

                # alternative pythonic way:
                # duplicates = len(letter1_to_suffixes[i] & letter1_to_suffixes[j])
                # ans += ((len(letter1_to_suffixes[i] - duplicates) * (len(letter1_to_suffixes[j] - duplicates)) * 2
    
        return ans
