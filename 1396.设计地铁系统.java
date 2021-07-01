/*
 * @lc app=leetcode.cn id=1396 lang=java
 *
 * [1396] 设计地铁系统
 */
import java.util.Map;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

// @lc code=start
class UndergroundSystem {
    class CheckInInfo {
        public String station;
        public int t;

        public CheckInInfo(String station, int t) {
            this.station = station;
            this.t = t;
        }
    }

    private Map<String, List<Integer>> routeTime;
    private Map<Integer, CheckInInfo> checkIns;

    public UndergroundSystem() {
        routeTime = new HashMap<>();
        checkIns = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        checkIns.put(id, new CheckInInfo(stationName, t));
    }
    
    public void checkOut(int id, String stationName, int t) {
        CheckInInfo checkIn = checkIns.get(id);
        String route = checkIn.station + "=>" + stationName;
        if (!routeTime.containsKey(route)) {
            routeTime.put(route, new ArrayList<>());
        }
        routeTime.get(route).add(t - checkIn.t);
        // checkIns.remove(id);
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String route = startStation + "=>" + endStation;
        List<Integer> times = routeTime.get(route);
        double ans = 0;
        for (Integer time : times) {
            ans += time;
        }
        return ans / (double) times.size();
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */
// @lc code=end

