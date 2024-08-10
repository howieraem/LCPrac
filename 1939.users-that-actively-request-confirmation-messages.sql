--
-- @lc app=leetcode id=1939 lang=mysql
--
-- [1939] Users That Actively Request Confirmation Messages
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT DISTINCT c1.user_id AS `user_id`
FROM Confirmations c1
INNER JOIN Confirmations c2
ON c1.user_id = c2.user_id
    AND c1.time_stamp < c2.time_stamp
    AND TIMESTAMPDIFF(second, c1.time_stamp, c2.time_stamp) <= 86400;

-- @lc code=end

