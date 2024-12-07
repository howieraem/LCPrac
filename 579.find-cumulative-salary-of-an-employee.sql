/* Write your T-SQL query statement below */
WITH cte AS (
    SELECT id, MAX(month) AS most_recent_month
    FROM Employee
    GROUP BY id
)
SELECT e1.id, e1.month, SUM(e2.salary) AS salary
FROM Employee e1
JOIN Employee e2 ON e1.id = e2.id AND (e1.month - e2.month) BETWEEN 0 AND 2
JOIN cte ON e1.id = cte.id AND e1.month != cte.most_recent_month
GROUP BY e1.id, e1.month
ORDER BY e1.id, e1.month DESC
