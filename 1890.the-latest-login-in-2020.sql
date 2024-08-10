--
-- @lc app=leetcode id=1890 lang=mysql
--
-- [1890] The Latest Login in 2020
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    `user_id`,
    MAX(time_stamp) AS last_stamp
FROM Logins
WHERE YEAR(time_stamp) = '2020'
GROUP BY 1;

-- @lc code=end

