#
# @lc app=leetcode.cn id=71 lang=python3
#
# [71] 简化路径
#

# @lc code=start
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        path = path.split("/")
        for item in path:
            if item == "..":
                if stack:   # stack not empty
                    stack.pop()
            elif item and item != ".":
                stack.append(item)  # a directory name
        return "/" + "/".join(stack)
        
# @lc code=end
s = Solution()
print(s.simplifyPath('/a//b////c/d//././/..'))
