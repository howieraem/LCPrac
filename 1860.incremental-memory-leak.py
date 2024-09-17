#
# @lc app=leetcode id=1860 lang=python3
#
# [1860] Incremental Memory Leak
#
import math
from typing import List

# @lc code=start
class Solution:
    # Simulation
    # T: O(max(mem1, mem2))
    # S: O(1)
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        i = 1
        while memory1 >= i or memory2 >= i:
            if memory1 >= memory2:
                memory1 -= i
            else:
                memory2 -= i
            i += 1
        return [i, memory1, memory2]

    '''
    # Math method
    # T: O(1)
    # S: O(1)
    def memLeak(self, memory1: int, memory2: int) -> List[int]:
        swapped = False
        if memory1 < memory2:
            # keep mem1 the larger one for now
            memory1, memory2 = memory2, memory1
            swapped = True

        def solve_quadratic(coeff, rhs):
            # solve the equation x ** 2 + coeff * x = rhs
            return math.floor((-coeff + math.sqrt(coeff * coeff + (rhs << 2))) / 2.)

        # Phase 1: consume mem1
        # memory1 - memory2 <= 1 + 2 + ... + i = i * (i + 1) / 2
        # solve for i
        i1 = solve_quadratic(1, (memory1 - memory2) << 1)
        memory1 -= ((i1 * (i1 + 1)) >> 1)
        if memory1 == memory2:
            swapped = False

        # Phase 2: consume both mems
        # memory2 <= (i + 2) + (i + 4) + ... + (i + 2 * n) = n * ((i + 2) + (i + 2 * n)) / 2
        # solve for n
        n_end = solve_quadratic(i1 + 1, memory2)
        
		# Compute sums of respective arithmetic sequences
        i_end_1 = i1 - 1 + (n_end << 1)
        i_end_2 = i1 + (n_end << 1)
        
        sum1 = n_end * ((i1 + 1 + i_end_1) >> 1)
        sum2 = n_end * ((i1 + 2 + i_end_2) >> 1)
        
		# Compute updated memories 
        memory1 -= sum1
        memory2 -= sum2
        
        full_cnt = (n_end << 1) + i1
        
        # If we can still make one removal from mem1
        if memory1 >= i_end_2 + 1: 
            memory1 -= i_end_2 + 1
            full_cnt += 1
            
        return [full_cnt + 1, memory2, memory1] if swapped \
            else [full_cnt + 1, memory1, memory2]
        '''

# @lc code=end

