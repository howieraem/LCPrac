--
-- @lc app=leetcode id=1142 lang=mysql
--
-- [1142] User Activity for the Past 30 Days II
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    ROUND(
        IFNULL(
            CAST(COUNT(DISTINCT `session_id`) AS FLOAT) / COUNT(DISTINCT `user_id`), 
            0), 
        2) AS average_sessions_per_user
FROM Activity
WHERE activity_date > DATE_SUB('2019-07-27', INTERVAL 30 DAY) and activity_date <= '2019-07-27';

-- @lc code=end

