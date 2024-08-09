--
-- @lc app=leetcode id=1294 lang=mysql
--
-- [1294] Weather Type in Each Country
--

-- @lc code=start
-- Write your MySQL query statement below
WITH w AS (
    SELECT 
        country_id,
        AVG(CAST(weather_state AS DECIMAL)) as avg_state
    FROM Weather
    WHERE `day` BETWEEN '2019-11-01' AND '2019-11-30'
    GROUP BY country_id
)
SELECT 
    c.country_name,
    CASE 
        WHEN w.avg_state <= 15 THEN 'Cold'
        WHEN w.avg_state >= 25 THEN 'Hot'
        ELSE 'Warm'
    END AS weather_type
FROM Countries c
INNER JOIN w
ON c.country_id = w.country_id;


-- @lc code=end

