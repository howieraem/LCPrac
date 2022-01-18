def droppedRequest(requestTime):
    ans = 0
    for i in range(len(requestTime)):
        # use elif below because a request to be dropped at a given time cannot be counted multiple times
        if i > 2 and requestTime[i] == requestTime[i - 3]:
            ans += 1
        elif i > 19 and requestTime[i] - requestTime[i - 20] < 10:
            ans += 1
        elif i > 59 and requestTime[i] - requestTime[i - 60] < 60:
            ans += 1
    return ans
