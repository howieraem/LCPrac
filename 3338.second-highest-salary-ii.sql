/* Write your T-SQL query statement below */
WITH cte AS (
    SELECT 
        emp_id, 
        dept,
        DENSE_RANK() OVER (PARTITION BY dept ORDER BY salary DESC) AS rk
    FROM employees 
)
SELECT emp_id, dept
FROM cte
WHERE rk = 2
ORDER BY emp_id;