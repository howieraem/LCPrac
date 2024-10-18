from typing import *
from subseq_sum_eq_k_cnt import solve as helper


def solve(nums: List[int], k: int) -> int:
    """
    Returns how many subseqs with difference equal to k.
    
    A variant of Q494.

    Constraint: k >= 0
    """
    # s1 - s2 = k
    # s1 + s2 = sum(nums)
    # s1 = (k + sum(nums)) / 2

    s = sum(nums)
    
    if s < abs(k) or ((k + s) & 1):
        # infeasible
        return 0

    zero_cnt = 0
    non_zero_nums = []
    for x in nums:
        if x == 0:
            zero_cnt += 1
        else:
            non_zero_nums.append(x)

    target = (k + s) >> 1

    return (1 << zero_cnt) * helper(non_zero_nums, target)


if __name__ == '__main__':
    res = solve([0, 0, 0, 0, 0, 0, 0, 0, 1], 1)
    print(res)
