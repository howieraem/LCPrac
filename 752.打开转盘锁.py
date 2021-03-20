#
# @lc app=leetcode.cn id=752 lang=python3
#
# [752] 打开转盘锁
#
from collections import deque

# @lc code=start
class Solution:
    '''
    # ordinary BFS
    def openLock(self, deadends: List[str], target: str) -> int:
        # deads = set(deadends)
        visited = set(deadends)
        if '0000' in visited or target in visited:
            return -1
        q = deque()
        ans = 0

        q.append('0000')
        visited.add('0000')
        while q:
            for _ in range(len(q)):
                cur = q.popleft()
                # if cur in deads:
                #     continue
                if cur == target:
                    return ans
                
                for j in range(4):
                    up = self._up(cur, j)
                    if up not in visited:
                        q.append(up)
                        visited.add(up)
                    
                    down = self._down(cur, j)
                    if down not in visited:
                        q.append(down)
                        visited.add(down)
            ans += 1
        return -1   # target not reachable
    '''

    # Bi-directional BFS 
    def openLock(self, deadends: List[str], target: str) -> int:
        visited = set(deadends)
        if '0000' in visited or target in visited:
            return -1
        q1 = set()
        q2 = set()
        q1.add('0000')
        q2.add(target)
        ans = 0

        while q1 and q2:
            tmp = set()     # create tmp as q1 will change

            for cur in q1:
                if cur in visited:
                    continue
                if cur in q2:
                    return ans
                visited.add(cur)
            
                for j in range(4):
                    up = self._up(cur, j)
                    if up not in visited:
                        tmp.add(up)
                    down = self._down(cur, j)
                    if down not in visited:
                        tmp.add(down)
            ans += 1

            # swap q1 and q2
            q1 = q2
            q2 = tmp
        return -1
    
    @staticmethod
    def _up(s, j):
        if s[j] == '9':
            return s[:j] + '0' + s[j+1:]
        return s[:j] + chr(ord(s[j]) + 1) + s[j+1:]

    @staticmethod
    def _down(s, j):
        if s[j] == '0':
            return s[:j] + '9' + s[j+1:]
        return s[:j] + chr(ord(s[j]) - 1) + s[j+1:]

# @lc code=end

