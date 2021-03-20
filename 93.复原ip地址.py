#
# @lc app=leetcode.cn id=93 lang=python3
#
# [93] 复原IP地址
#
from typing import List

# @lc code=start
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        if len(s) < 4:
            return []
        res = []
        def backtrack(ip_str: str, insert_idx: int, remain_dots: int):
            if insert_idx >= len(ip_str):
                return
            remain_dots -= 1
            ip_str = ip_str[:insert_idx] + '.' + ip_str[insert_idx:]
            num1, num2 = ip_str.split('.')[-2:]
            if numInvalid(num1):
                return
            if not remain_dots:
                if numInvalid(num2):
                    return
                res.append(ip_str)
            backtrack(ip_str, insert_idx+2, remain_dots)
            backtrack(ip_str, insert_idx+3, remain_dots)
            backtrack(ip_str, insert_idx+4, remain_dots)
        backtrack(s, 1, 3)
        backtrack(s, 2, 3)
        backtrack(s, 3, 3)
        return res

def numInvalid(string: str):
    return (string != '0' and string.startswith('0')) or int(string) > 255
    

# @lc code=end
s = Solution()
print(s.restoreIpAddresses('101023'))
