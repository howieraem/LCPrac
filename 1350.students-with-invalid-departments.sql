--
-- @lc app=leetcode id=1350 lang=mysql
--
-- [1350] Students With Invalid Departments
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT s.id, s.name
FROM Students s
LEFT JOIN Departments d
ON s.department_id = d.id
WHERE d.id IS NULL;

-- @lc code=end

