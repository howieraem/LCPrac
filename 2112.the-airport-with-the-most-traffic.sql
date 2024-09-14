--
-- @lc app=leetcode id=2112 lang=mysql
--
-- [2112] The Airport With the Most Traffic
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT departure_airport AS airport_id, flights_count FROM Flights
    UNION ALL
    SELECT arrival_airport AS airport_id, flights_count FROM Flights
), b AS (
    SELECT
        airport_id,
        DENSE_RANK() OVER (ORDER BY SUM(flights_count) DESC) AS rk 
    FROM a
    GROUP BY airport_id
)
SELECT DISTINCT airport_id
FROM b
WHERE b.rk = 1;

-- @lc code=end

