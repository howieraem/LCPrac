/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

// @lc code=start
typedef pair<string, int> check_in; // station and check-in time

// S: O(n)
class UndergroundSystem {
    unordered_map<int, check_in> passenger_check_in;  // k: passenger_id, v: check_in (station, time)
    unordered_map<string, vector<int>> route_durations;  // k: station1_station2, v: list of durations

public:
    UndergroundSystem() {}
    
    // O(1)
    void checkIn(int id, string stationName, int t) {
        passenger_check_in[id] = {stationName, t};
    }
    
    // O(1)
    void checkOut(int id, string stationName, int t) {
        const auto& [pre_station, t_pre] = passenger_check_in[id];
        route_durations[pre_station + "=>" + stationName].push_back(t - t_pre);
    }
    
    // O(n)
    double getAverageTime(string startStation, string endStation) {
        double res = 0.;
        const string route = startStation + "=>" + endStation;
        for (const auto& t : route_durations[route]) {
            res += t;
        }
        return res / route_durations[route].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

