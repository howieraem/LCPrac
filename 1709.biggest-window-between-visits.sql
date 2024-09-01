--
-- @lc app=leetcode id=1709 lang=mysql
--
-- [1709] Biggest Window Between Visits
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        `user_id`,
        visit_date,
        LEAD(visit_date, 1, '2021-1-1') OVER (PARTITION BY `user_id` ORDER BY visit_date) AS nxt_visit
    FROM UserVisits
)
SELECT 
    `user_id`,
    MAX(DATEDIFF(nxt_visit, visit_date)) AS biggest_window
FROM a
GROUP BY `user_id`
ORDER BY `user_id`;

-- @lc code=end

