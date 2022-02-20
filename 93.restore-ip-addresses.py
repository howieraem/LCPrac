#
# @lc app=leetcode id=93 lang=python3
#
# [93] Restore IP Addresses
#
from typing import List

# @lc code=start
class Solution:
    '''
    # Solution 1: Brute-force
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        n = len(s)
        for a in range(1, 4):
            for b in range(1, 4):
                for c in range(1, 4):
                    d = n - a - b - c
                    if (
                        1 <= d <= 3 and
                        (a == 1 or s[0] != '0') and (a != 3 or s[:a] <= "255") and
                        (b == 1 or s[a] != '0') and (b != 3 or s[a:a + b] <= "255") and
                        (c == 1 or s[a + b] != '0') and (c != 3 or s[a + b:a + b + c] <= "255") and
                        (d == 1 or s[a + b + c] != '0') and (d != 3 or s[a + b + c:] <= "255")
                    ):
                        res.append(
                            '.'.join([s[:a], s[a:a + b], s[a + b:a + b + c], s[a + b + c:]]))
        return res
    '''

    # Solution 2: DFS
    # T: O(3 ^ n), because there are 3 possible segment lengths {1, 2, 3}
    # S: O(n)
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        n = len(s)

        if 4 <= n <= 12:
            # PRUNE 0: avoid impossible lengths

            def dfs(path: str, i: int, cnt: int):
                if cnt == 4:
                    if i == n:
                        res.append(path)
                    return
                
                for l in range(1, 4):
                    j = i + l

                    if j > n:
                        # PRUNE 1: index out of bound
                        break
                    
                    if l != 1 and s[i] == '0':
                        # PRUNE 2:
                        # Unless segment length is 1 (the case '0'),
                        # segment cannot start with '0'
                        break
                    
                    seg = s[i:j]
                    if int(seg) < 256:
                        # PRUNE 3: Segment cannot be greater than 255
                        new_path = path + seg
                        if cnt < 3:
                            # Avoid adding a trailing dot to the restored IP
                            new_path += '.'
                        dfs(new_path, j, cnt + 1)

            dfs("", 0, 0)

        return res


        
# @lc code=end

