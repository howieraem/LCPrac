#
# @lc app=leetcode.cn id=1600 lang=python3
#
# [1600] 皇位继承顺序
#
from collections import defaultdict

# @lc code=start
class ThroneInheritance:
    __slots__ = ['initKing', 'p2c', 'deaths']

    def __init__(self, kingName: str):
        self.initKing = kingName
        self.p2c = defaultdict(list)
        self.deaths = set()

    def birth(self, parentName: str, childName: str) -> None:
        self.p2c[parentName].append(childName)

    def death(self, name: str) -> None:
        self.deaths.add(name)

    def getInheritanceOrder(self) -> List[str]:
        res = []
        self.dfs(res, self.initKing)
        return res
    
    def dfs(self, res, name):
        if name not in self.deaths:
            res.append(name)
        for child in self.p2c[name]:
            self.dfs(res, child)

# Your ThroneInheritance object will be instantiated and called as such:
# obj = ThroneInheritance(kingName)
# obj.birth(parentName,childName)
# obj.death(name)
# param_3 = obj.getInheritanceOrder()
# @lc code=end

