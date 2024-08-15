--
-- @lc app=leetcode id=1107 lang=mysql
--
-- [1107] New Users Daily Count
--

-- @lc code=start
-- Write your MySQL query statement below

SELECT login_date, COUNT(*) AS user_count
FROM (
    SELECT `user_id`, min(activity_date) AS login_date
    FROM Traffic
    WHERE activity = 'login'
    GROUP BY `user_id`
) a
WHERE DATEDIFF('2019-06-30', login_date) <= 90
GROUP BY login_date;

-- @lc code=end

