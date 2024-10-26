from typing import List

class Solution:
    # Sorting + Binary search
    # T: O((ns + np) * log(np))
    # S: O(np) timsort
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        np = len(potions)
        ns = len(spells)
        res = [0] * ns

        # do binary search on potions for every spell
        for i in range(ns):
            l = 0
            r = np - 1

            while l <= r:
                m = l + ((r - l) >> 1)
                prod = spells[i] * potions[m]
                if prod >= success:
                    r = m - 1
                else:
                    l = m + 1
            
            res[i] = np - l  # every numbers on the right of l are eligible

        return res
