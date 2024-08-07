--
-- @lc app=leetcode id=181 lang=mysql
--
-- [181] Employees Earning More Than Their Managers
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT a.name AS Employee
FROM Employee a
JOIN Employee b
ON a.managerId = b.id
AND a.salary > b.salary;

-- @lc code=end

