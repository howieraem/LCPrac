from typing import List

class Solution:
    # T: O(n ^ 2)
    # S: O(1)
    def countPairs(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                ans += self.check(nums[i], nums[j])
        return ans
    
    # T: O(max(log(a), log(b)))
    # S: O(1)
    def check(self, a: int, b: int) -> bool:
        a = str(a)
        b = str(b)
        if len(b) > len(a):
            a, b = b, a
        
        if len(a) - len(b) >= 1:
            b = '0' * (len(a) - len(b)) + b

        diffs = []
        for c1, c2 in zip(a, b):
            if c1 != c2:
                diffs.append((c1, c2))
            if len(diffs) > 2:
                return False
        return len(diffs) == 0 or \
            (len(diffs) == 2 and diffs[0][1] == diffs[1][0] and diffs[0][0] == diffs[1][1])
