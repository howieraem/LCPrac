--
-- @lc app=leetcode id=1303 lang=mysql
--
-- [1303] Find the Team Size
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    employee_id,
    COUNT(team_id) OVER (PARTITION BY team_id) AS team_size
FROM Employee;

-- @lc code=end

