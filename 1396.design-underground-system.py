#
# @lc app=leetcode id=1396 lang=python3
#
# [1396] Design Underground System
#
from collections import defaultdict

# @lc code=start
# S: O(n)
class UndergroundSystem:
    # T: O(1)
    def __init__(self):
        # k: passenger_id, v: (start_station, timestamp)
        self.last_check_in = {}

        # k: (start_station, end_station), v: list of durations
        self.route_duration = defaultdict(list)  

    # T: O(1)
    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.last_check_in[id] = (stationName, t)

    # T: O(1)
    def checkOut(self, id: int, stationName: str, t: int) -> None:
        (start, t_start) = self.last_check_in.get(id, (None, None))
        if start is not None and t_start is not None:
            self.route_duration[(start, stationName)].append(t - t_start)

    # T: O(n)
    def getAverageTime(self, startStation: str, endStation: str) -> float:
        durations = self.route_duration.get((startStation, endStation), None)
        if durations is None:
            return 0
        return sum(durations) / len(durations)


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
# @lc code=end

