from typing import List

class Solution:
    # Convert to interval problem + sorting
    # T: O(n * log(n))
    # S: O(n) timsort
    def visibleMountains(self, peaks: List[List[int]]) -> int:
        n = len(peaks)

        # convert peaks to intervals
        for i in range(n):
            x = peaks[i][0]
            y = peaks[i][1]
            peaks[i][0] = x - y
            peaks[i][1] = x + y

        # sort by starts ASC and ends DESC
        peaks.sort(key=lambda interval: (interval[0], -interval[1]))

        ans = 0
        cur_end = float('-inf')
        for i, (s, e) in enumerate(peaks):
            if e > cur_end:
                # new interval not covered by previous interval
                cur_end = e

                # check if last interval and duplicate next interval
                if i == n - 1 or (s != peaks[i + 1][0] or e != peaks[i + 1][1]):
                    ans += 1
        return ans
