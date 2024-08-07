--
-- @lc app=leetcode id=197 lang=mysql
--
-- [197] Rising Temperature
--

-- @lc code=start
-- Write your MySQL query statement below

-- Solution 1: INNER JOIN
SELECT a.id
FROM Weather a
JOIN Weather b
ON a.recordDate = DATE_ADD(b.recordDate, INTERVAL 1 DAY)
WHERE a.temperature > b.temperature;

-- Solution 2: CROSS JOIN
-- SELECT a.id
-- FROM Weather a, Weather b
-- WHERE a.temperature > b.temperature 
--   AND DATEDIFF(a.recordDate, b.recordDate) = 1;

-- @lc code=end

