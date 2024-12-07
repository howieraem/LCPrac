/* Write your T-SQL query statement below */
WITH cte AS (
    SELECT 
        id,
        company, 
        salary, 
        ROW_NUMBER() OVER (PARTITION BY company ORDER BY salary, id) AS rn,
        COUNT(1) OVER (PARTITION BY company) AS cnt
    FROM Employee
)
SELECT id, company, salary
FROM cte
WHERE rn = cnt / 2.0  -- exact match for even cnt of ids in a company
    OR rn = cnt / 2 + 1;
