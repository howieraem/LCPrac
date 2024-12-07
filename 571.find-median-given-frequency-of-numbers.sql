/* Write your T-SQL query statement below */
WITH cte AS (
    SELECT 
        num,
        frequency,
        SUM(frequency) OVER (ORDER BY num) AS cumul_freq,
        (SUM(frequency) OVER ()) / 2.0 AS median_idx
    FROM Numbers
)
SELECT AVG(CAST(num AS FLOAT)) AS median
FROM cte
WHERE median_idx BETWEEN cumul_freq - frequency AND cumul_freq;