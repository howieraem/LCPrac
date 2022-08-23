#
# @lc app=leetcode id=818 lang=python3
#
# [818] Race Car
#
from collections import deque

# @lc code=start
class Solution:
    '''
    # Solution 1: BFS with pruning
    # T: O(target * log(target))
    # S: O(target * log(target))
    def racecar(self, target: int) -> int:
        q = deque()
        q.appendleft((0, 1))  # queue of (pos, speed) pairs
        vis = set()
        vis.add((0, 1))

        """
        We should allow the car to be able to pass the target and then 
        reverse the direction to go to the target. However, there should 
        be an upper bound because there's no point to keep accelerating 
        after passing the target.

        To find the upper bound, consider an extreme case where the car 
        is always accelerating, the number of acceleration is m, the car 
        with position (2^m) - 1 has not reached the target: (2^m)-1 < target. 
        Since the target is an integer, we can rewrite it as: 
        target = (2^m)+k, k >= 0 (1)

        In the above extreme case, the car's speed 2^m is the maximum possible 
        speed at the position (2^m)-1. Note that we should allow the car to be 
        able to pass the target, which leads to the maximum next position is 
        (2^m)-1 + 2^m (2)

        Combine (1) and (2), we get (2^m)-1+2^m = 2*(2^m)-1 < 2*(2^m)+2*k = 2*target, 
        k >= 0. It indicates that the upper bound for any position with any possible 
        speed is 2*target.
        """
        furthest = (target << 1)

        steps = 0
        while len(q):
            qs = len(q)
            for _ in range(qs):
                pos, speed = q.popleft()
                if pos == target:
                    return steps
                next_accelerate = (pos + speed, speed << 1)
                if next_accelerate not in vis and 0 < next_accelerate[0] < furthest:
                    q.append(next_accelerate)
                    vis.add(next_accelerate)
                
                next_reverse = (pos, -1 if speed > 0 else 1)
                if next_reverse not in vis and 0 < next_reverse[0] < furthest:
                    q.append(next_reverse)
                    vis.add(next_reverse)
            steps += 1
        return -1
    '''

    # Solution 2: bottom-up DP
    # T: O(target * (log(target)) ^ 2)
    # S: O(target)
    def racecar(self, target: int) -> int:
        dp = [2147483647] * (target + 1)
        n_acc = 1  # the number of A operations
        for i in range(1, target + 1):
            if i == (1 << n_acc) - 1:
                # i == 2^n_acc - 1, the minimum number of operations is n_acc
                dp[i] = n_acc
                n_acc += 1
            else:
                # If 2^(n_acc - 1) - 1 < i < 2^n_acc - 1, there're 2 possibilities:
                # 1. The car reaches 2^(n_acc - 1) - 1 and then reverses, accelerates 
                #    for another j operations in the opposite direction and reverses again. 
                #    Now its position is at 2^(n_acc - 1) - 2^j, the remaining subproblem 
                #    is to go from current position to i with initial speed, which is 
                #    dp[i-2^(n_acc - 1)+2^j].
                # 2. The car reaches 2^n_acc - 1 and reverses, the remaining subproblem 
                #    is equal to dp[2^n_acc-1-i]
                lower = (1 << (n_acc - 1)) - 1
                upper = (1 << n_acc) - 1
                for j in range(n_acc - 1):
                    dp[i] = min(dp[i], n_acc + 1 + j + dp[i - (1 << (n_acc - 1)) + (1 << j)])
                dp[i] = min(dp[i], n_acc + 1 + dp[upper - i])
        return dp[target]


# @lc code=end

