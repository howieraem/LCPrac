--
-- @lc app=leetcode id=1731 lang=mysql
--
-- [1731] The Number of Employees Which Report to Each Employee
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    b.employee_id,
    b.name,
    COUNT(*) AS reports_count,
    ROUND(AVG(CAST(a.age AS DECIMAL)), 0) AS average_age
FROM Employees a
INNER JOIN Employees b
ON a.reports_to = b.employee_id
GROUP BY 1, 2
ORDER BY 1;

-- @lc code=end

