--
-- @lc app=leetcode id=603 lang=mysql
--
-- [603] Consecutive Available Seats
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        seat_id,
        free,
        LAG(free, 1) OVER (ORDER BY seat_id) AS free_lag,
        LEAD(free, 1) OVER (ORDER BY seat_id) AS free_lead
    FROM Cinema
)
SELECT seat_id
FROM a
WHERE free = 1 
    AND (free_lag = 1 OR free_lead = 1)
ORDER BY seat_id; 

-- alternative: seat_id - ROW_NUMBER() where free = 1; consecutive seats will have the same diff

-- @lc code=end

