#
# @lc app=leetcode id=2115 lang=python3
#
# [2115] Find All Possible Recipes from Given Supplies
#
from collections import defaultdict, deque
from typing import List

# @lc code=start
class Solution:
    # Kahn's algorithm (topological sort)
    # T: O(V + E + S), S := len(supplies), V := len(recipes), E := S - len(ingredients)?
    # S: O(V + S)
    def findAllRecipes(self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]) -> List[str]:
        supply_set = set(supplies)
        graph = defaultdict(list)
        in_degree = defaultdict(int)

        # Build a directed graph for missing ingredients and impossible recipes.
        # Some recipes can be ingredients of other recipes.
        for i in range(len(recipes)):
            for j in range(len(ingredients[i])):
                if ingredients[i][j] not in supply_set:
                    graph[ingredients[i][j]].append(recipes[i])
                    in_degree[recipes[i]] += 1

        # Possible recipes should have zero in_degree
        q = deque()
        for r in recipes:
            if in_degree[r] == 0:
                q.append(r)
        res = []
        while len(q):
            r = q.popleft()
            res.append(r)
            for neighbor in graph[r]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    q.append(neighbor)
        return res   


# @lc code=end

