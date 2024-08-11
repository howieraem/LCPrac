class Solution:
    # T: O(n)
    # S: O(1)
    def bestClosingTime(self, customers: str) -> int:
        # Minimizing the penalty can be paraphrasized as maximizing a reward
        ans = -1
        max_reward = reward = 0

        for i, c in enumerate(customers):
            reward += 1 if c == 'Y' else -1
            if reward > max_reward:
                max_reward = reward
                ans = i

        return ans + 1  # add 1 because we still need to include the current hour
