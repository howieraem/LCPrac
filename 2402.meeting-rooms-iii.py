import heapq
from typing import List

class Solution:
    # Two heaps + merge interval
    # T: O((n + len(meetings)) * log(n))
    # S: O(n)
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()  # sort by start time

        busy_rooms = []  # min heap (meeting_end_time, room_no)
        avail_rooms = []  # min heap, room no. (lower number first)

        room_meeting_cnts = [0] * n

        for i in range(n):
            heapq.heappush(avail_rooms, i)

        for s, e in meetings:
            # remove ended meetings and free the rooms
            while len(busy_rooms) > 0 and busy_rooms[0][0] <= s:
                _, room = heapq.heappop(busy_rooms)
                heapq.heappush(avail_rooms, room)

            if len(avail_rooms) > 0:
                # use an available room with the lowest id
                room = heapq.heappop(avail_rooms)
                room_meeting_cnts[room] += 1
                heapq.heappush(busy_rooms, (e, room))
            else:
                # "delay" the meeting by merging the interval and pre-occupying the room
                old_end, room = heapq.heappop(busy_rooms)
                room_meeting_cnts[room] += 1
                new_end = old_end + (e - s)
                heapq.heappush(busy_rooms, (new_end, room))

        # return argmax(room_meeting_cnts)
        ans = -1
        max_cnt = 0
        for i, cnt in enumerate(room_meeting_cnts):
            if cnt > max_cnt:
                max_cnt = cnt
                ans = i
        return ans
