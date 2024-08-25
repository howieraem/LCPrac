from itertools import combinations_with_replacement
from collections import defaultdict
from typing import List, Set

class Solution:
    # T: O(len(nums) * (log(x) ^ 4)), works well with large len(nums) and similar numbers
    # S: O(log(x) ^ 4)
    def countPairs(self, nums: List[int]) -> int:
        ans = 0
        pair_cnt = defaultdict(int)
        for x in nums:
            ans += pair_cnt[x]
            for y in self.get_adj(x):
                pair_cnt[y] += 1 
        return ans

    def get_adj(self, x: int) -> Set[int]:
        s = str(x)
        # pad to 7 digits, because max(x) is less than 10^7
        s = ['0'] * (7 - len(s)) + list(s)  # convert to chararray for easy swapping
        n = len(s)
        adj = set()

        # Do any 2 swaps (incl. 0 and 1 swap cases)
        '''
        for i in range(7):
            for j in range(i, 7):
                for k in range(7):
                    for l in range(k, 7):
        '''
        for i, j in combinations_with_replacement(range(n), 2):
            s[i], s[j] = s[j], s[i]
            for k, l in combinations_with_replacement(range(n), 2):
                s[k], s[l] = s[l], s[k]
                adj.add(int("".join(s)))
                s[l], s[k] = s[k], s[l]
            s[j], s[i] = s[i], s[j]
        return adj

    '''
    # Below will encounter TLE in Python
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
        # pure numerical check, without converting to str
        diff_i = 0
        a_diff_digits = [-1] * 4  # max two swaps
        b_diff_digits = [-1] * 4
        while a > 0 or b > 0:
            a_div, a_mod = divmod(a, 10)
            b_div, b_mod = divmod(b, 10)
            if a_mod != b_mod:
                a_diff_digits[diff_i] = a_mod
                b_diff_digits[diff_i] = b_mod
                diff_i += 1
            a = a_div
            b = b_div
            if diff_i == 4:
                break
        
        if diff_i == 0:
            return True
        elif diff_i == 1:
            return False
        elif diff_i == 2 or diff_i == 3:
            if a != b:
                return False
            a_diff_digits.sort()
            b_diff_digits.sort()
            return a_diff_digits == b_diff_digits
        else:  # diff_i == 4
            if a != b:
                return False
            for i in range(3):
                for j in range(i + 1, 4):
                    if a_diff_digits[i] == b_diff_digits[j] and a_diff_digits[j] == b_diff_digits[i]:
                        # get a matching pair first
                        a_diff_digits.sort()
                        b_diff_digits.sort()
                        return a_diff_digits == b_diff_digits  # this also covers actual diff >= 5 cases
            return False  # no matching pair exists
    '''
