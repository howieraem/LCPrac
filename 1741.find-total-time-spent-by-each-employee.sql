--
-- @lc app=leetcode id=1741 lang=mysql
--
-- [1741] Find Total Time Spent by Each Employee
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    event_day AS `day`,
    emp_id,
    SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY 1, 2
ORDER BY 1, 2;

-- @lc code=end

