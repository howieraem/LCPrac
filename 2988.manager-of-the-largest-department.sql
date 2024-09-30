/* Write your T-SQL query statement below */
WITH a AS (
    SELECT dep_id, DENSE_RANK() OVER (ORDER BY COUNT(emp_id) DESC) AS rk
    FROM Employees
    GROUP BY dep_id
)
SELECT e.emp_name AS manager_name, a.dep_id
FROM Employees e
JOIN a ON e.dep_id = a.dep_id AND a.rk = 1
WHERE e.position = 'Manager'
ORDER BY a.dep_id;