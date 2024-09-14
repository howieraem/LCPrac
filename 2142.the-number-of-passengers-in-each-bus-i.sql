--
-- @lc app=leetcode id=2142 lang=mysql
--
-- [2142] The Number of Passengers in Each Bus I
--

-- @lc code=start
-- Write your MySQL query statement below
-- create intervals between bus arrivals 
WITH a AS (
    SELECT 
        bus_id,
        arrival_time AS curr,
        LAG(arrival_time, 1, 0) OVER (ORDER BY arrival_time) AS prev
    FROM Buses
)
SELECT 
    bus_id, 
    COUNT(passenger_id) AS passengers_cnt
FROM a
LEFT JOIN Passengers p
    ON a.prev < p.arrival_time AND p.arrival_time <= a.curr
GROUP BY bus_id
ORDER BY bus_id;


-- @lc code=end

