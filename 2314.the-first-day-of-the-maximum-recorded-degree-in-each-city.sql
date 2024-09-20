/* Write your T-SQL query statement below */
WITH cte AS (
    SELECT 
        city_id,
        day, 
        degree,
        RANK() OVER (PARTITION BY city_id ORDER BY degree DESC, day) AS rk
    FROM Weather
)
SELECT city_id, day, degree
FROM cte
WHERE rk = 1
ORDER BY city_id;