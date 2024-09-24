/* Write your T-SQL query statement below */
SELECT e.employee_id
FROM Employees e
LEFT JOIN Logs l
    ON e.employee_id = l.employee_id
GROUP BY e.employee_id, e.needed_hours
HAVING SUM(CEILING(CAST(COALESCE(DATEDIFF(SECOND, in_time, out_time), 0) AS FLOAT) / 60)) / 60 < e.needed_hours 
ORDER BY e.employee_id;
