--
-- @lc app=leetcode id=1965 lang=mysql
--
-- [1965] Employees With Missing Information
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT e.employee_id 
    FROM Employees e
    LEFT JOIN Salaries s
    ON e.employee_id = s.employee_id
    WHERE s.salary IS NULL
UNION ALL
SELECT s.employee_id 
    FROM Salaries s
    LEFT JOIN Employees e
    ON s.employee_id = e.employee_id
    WHERE e.name IS NULL
ORDER BY employee_id;

/* Solution below may encounter TLE:
WITH a AS (
    SELECT employee_id FROM Employees
    UNION ALL
    SELECT employee_id FROM Salaries
)
SELECT employee_id
FROM a
GROUP BY employee_id
HAVING COUNT(employee_id) = 1   -- if both name and salary not missing, COUNT will be 2
ORDER BY employee_id;
*/
-- @lc code=end

