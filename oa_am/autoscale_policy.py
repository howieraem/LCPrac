from math import ceil
from typing import List


def autoscale_policy(instances: int, average_util: List):
    # Read the question carefully and note the conditions/thresholds
    n = len(average_util)
    for i in range(n):
        if average_util[i] < 25:
            if instances > 1:
                instances = ceil(instances / 2)
                i += 10
                if i > n:
                    break
        elif average_util[i] > 60:
            if instances * 2 < 217:     # 108 * 2 + 1 
                instances *= 2
                i += 10
                if i > n:
                    break
    return instances
