#
# @lc app=leetcode.cn id=347 lang=python3
#
# [347] 前 K 个高频元素
#

# @lc code=start
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # count numbers
        hashmap = {}
        for num in nums:
            if num not in hashmap:
                hashmap[num] = 1
            else:
                hashmap[num] += 1

        # bucket sort
        tmp = [[] for _ in range(len(nums))]
        for num, count in hashmap.items():
            tmp[count - 1].append(num)
        n, res = 0, []
        for i in range(len(tmp)-1, -1, -1):
            if n == k:
                break
            if tmp[i]:
                res.extend(tmp[i])
                n += len(tmp[i])
        return res
        
# @lc code=end

