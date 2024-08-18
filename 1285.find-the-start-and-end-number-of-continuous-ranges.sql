--
-- @lc app=leetcode id=1285 lang=mysql
--
-- [1285] Find the Start and End Number of Continuous Ranges
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT
        log_id,
        -- log_id in a continuous range should have the same diff
        log_id - ROW_NUMBER() OVER (ORDER BY log_id) AS diff
    FROM Logs
)
SELECT 
    MIN(log_id) AS start_id,
    MAX(log_id) AS end_id
FROM a
GROUP BY diff;


-- @lc code=end

