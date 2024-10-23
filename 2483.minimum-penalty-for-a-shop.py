class Solution:
    # DP / Prefix sum
    # T: O(n)
    # S: O(1)
    def bestClosingTime(self, customers: str) -> int:
        # Minimizing the penalty can be paraphrased as maximizing a reward
        ans = -1
        max_reward = reward = 0

        # Assume the store always opens. To cover both kinds of penalty,
        # use a positive score for hours with customers, and a negative 
        # score for hours without customers.
        for i, c in enumerate(customers):
            reward += 1 if c == 'Y' else -1
            if reward > max_reward:
                max_reward = reward
                ans = i

        return ans + 1  # add 1 because we still need to include the current hour
