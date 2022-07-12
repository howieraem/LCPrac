#
# @lc app=leetcode id=358 lang=python3
#
# [358] Rearrange String k Distance Apart
#
import heapq

# @lc code=start
class Solution:
    # T: O(n * log(s))
    # S: O(s)
    def rearrangeString(self, s: str, k: int) -> str:
        if not k:
            return s

        a = ord('a')
        cnts = [0] * 26
        for c in s:
            cnts[ord(c) - a] += 1

        min_heap = []
        for i in range(26):
            if cnts[i]:
                heapq.heappush(min_heap, (-cnts[i], chr(i + a)))

        remain_len = len(s)
        res = ""
        tmp_pairs = []

        while len(min_heap):
            tmp_pairs.clear()
            dist = min(k, remain_len)
            while dist:
                if not len(min_heap):
                    return ""

                # Always pick the char with maximum remaining count
                c_cnt_neg, c = heapq.heappop(min_heap)
                res += c
                c_cnt_neg += 1
                if c_cnt_neg < 0:
                    tmp_pairs.append((c_cnt_neg, c))

                dist -= 1
                remain_len -= 1

            for pair in tmp_pairs:
                heapq.heappush(min_heap, pair)

        return res

# @lc code=end

