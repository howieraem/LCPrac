from typing import List

class Solution:
    # One hash map, no sorting
    # T: O(n)
    # S: O(n)
    def mostPopularCreator(self, creators: List[str], ids: List[str], views: List[int]) -> List[List[str]]:
        mp = dict()  # k: creator, v: (view_sum, best_idx)
        max_views = 0
        for i, (c, vi, v) in enumerate(zip(creators, ids, views)):
            if c not in mp:
                mp[c] = [v, -1]
            else:
                mp[c][0] += v
            max_views = max(max_views, mp[c][0])
            cur_best_idx = mp[c][1]
            if cur_best_idx < 0 or views[cur_best_idx] < v or \
                (views[cur_best_idx] == v and ids[cur_best_idx] > vi):
                mp[c][1] = i
        
        res = []
        for k, (view_sum, best_idx) in mp.items():
            if view_sum == max_views:
                res.append([k, ids[best_idx]])
        return res
