--
-- @lc app=leetcode id=580 lang=mysql
--
-- [580] Count Student Number in Departments
--

-- @lc code=start
-- Write your MySQL query statement below

SELECT 
    d.dept_name,
    COUNT(s.student_id) AS student_number
FROM Department d
LEFT JOIN Student s
ON d.dept_id = s.dept_id
GROUP BY d.dept_name
ORDER BY COUNT(s.student_id) DESC, d.dept_name;

-- @lc code=end

