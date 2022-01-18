#
# @lc app=leetcode.cn id=406 lang=python3
#
# [406] 根据身高重建队列
#

# @lc code=start
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        # sort by reversed height and then k
        people.sort(key=lambda x: (-x[0], x[1]))     
        output = []
        for p in people:
            output.insert(p[1], p)  # insert at index k
        return output
        
# @lc code=end
