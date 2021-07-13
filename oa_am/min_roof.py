from sys import maxsize
from typing import List


def parkingDilemma(cars: List, k: int):
    n = len(cars)
    if not n or n < k:
        return 0
    cars.sort()
    ans = maxsize
    for i in range(n - k + 1):
        # need to add 1 because both window start and window end need to be covered
        ans = min(ans, cars[i + k - 1] - cars[i] + 1)
        i += 1
    return ans
