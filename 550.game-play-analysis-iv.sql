--
-- @lc app=leetcode id=550 lang=mysql
--
-- [550] Game Play Analysis IV
--

-- @lc code=start
-- Write your MySQL query statement below
/* Solution 1: window function */
WITH a AS (
    SELECT 
        player_id,
        DATEDIFF(event_date, MIN(event_date) OVER (PARTITION BY player_id)) AS diff
    FROM Activity
)
SELECT 
    ROUND(SUM(CASE WHEN diff = 1 THEN 1.00 ELSE 0.00 END) / COUNT(distinct player_id), 2) AS fraction
FROM a;

/* Solution 2: without window function 
SELECT 
    ROUND(AVG(CASE WHEN event_date IS NOT NULL THEN 1.00 ELSE 0.00 END), 2) AS fraction 
FROM (
    SELECT
        player_id,
        MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) a
LEFT JOIN Activity b
ON a.player_id = b.player_id
AND DATEDIFF(event_date, first_login) = 1;
*/

-- @lc code=end

