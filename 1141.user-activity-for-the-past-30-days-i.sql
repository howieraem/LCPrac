--
-- @lc app=leetcode id=1141 lang=mysql
--
-- [1141] User Activity for the Past 30 Days I
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    activity_date AS `day`,
    COUNT(DISTINCT `user_id`) AS active_users
FROM Activity
GROUP BY activity_date
HAVING activity_date > DATE_SUB('2019-07-27', INTERVAL 30 DAY) and activity_date <= '2019-07-27';

-- @lc code=end

