from typing import List


def optimal_utilization(a: List[List], b: List[List], target: int):
    # If need to iterate on two (or more) collections pair-wise,
    # consider sorting first and then using two-pointer approach. 
    # O(N^2) -> O(NlogN).
    a.sort(key=lambda x: x[1])
    b.sort(key=lambda y: y[1])
    i = 0
    j = len(b) - 1
    min_sum = -2 ** 31

    res = []
    while i < len(a) and j >= 0:
        s = a[i][1] + b[j][1]
        if s > target:
            j -= 1
        else:
            if s > min_sum:
                res = []
            res.append([a[i][0], b[j][0]])
            min_sum = s
            i += 1
    return res
