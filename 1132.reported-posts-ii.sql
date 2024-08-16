--
-- @lc app=leetcode id=1132 lang=mysql
--
-- [1132] Reported Posts II
--

-- @lc code=start
-- Write your MySQL query statement below

SELECT ROUND(AVG(ratio) * 100, 2) AS average_daily_percent
FROM (
    SELECT 
        a.action_date, 
        CAST(COUNT(DISTINCT r.post_id) AS DECIMAL(30, 2)) / COUNT(DISTINCT a.post_id) AS ratio
    FROM Actions a
    LEFT JOIN Removals r
    ON a.post_id = r.post_id
    WHERE extra = 'spam'
    GROUP BY a.action_date 
) t;

-- @lc code=end

