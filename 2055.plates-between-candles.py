#
# @lc app=leetcode id=2055 lang=python3
#
# [2055] Plates Between Candles
#
from typing import List

# @lc code=start
class Solution:
    # Prefix sum + two pointers
    # T: O(len(s) + len(queries))
    # S: O(len(s))
    def platesBetweenCandles(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)

        nearest_candle_l = [0] * n
        candle_idx = -1
        candle_pre_sum = [0] * n
        cur_candle_cnt = 0
        for i in range(n):
            if s[i] == '|':
                candle_idx = i
                cur_candle_cnt += 1
            nearest_candle_l[i] = candle_idx
            candle_pre_sum[i] = cur_candle_cnt

        nearest_candle_r = [0] * n
        candle_idx = -1
        for i in range(n - 1, -1, -1):
            if s[i] == '|':
                candle_idx = i
            nearest_candle_r[i] = candle_idx

        res = [0] * len(queries)
        for qidx, (l, r) in enumerate(queries):
            candle_leftmost = nearest_candle_r[l]
            candle_rightmost = nearest_candle_l[r]

            if candle_leftmost == -1 or candle_rightmost == -1:
                # the interval contains plates not between in-interval candles
                continue

            candle_range = candle_rightmost - candle_leftmost
            if candle_range <= 1:
                # the interval contains candles only, or is invalid (l > r)
                continue
            
            # excl. all other candles between the leftmost and the rightmost candles 
            res[qidx] = candle_range + 1 - (candle_pre_sum[candle_rightmost] - candle_pre_sum[candle_leftmost] + 1)

        return res

# @lc code=end

