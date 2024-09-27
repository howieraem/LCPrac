/* Write your T-SQL query statement below */
WITH a AS (
    SELECT 
        user_id,
        steps_date,
        LAG(steps_date, 2) OVER (PARTITION BY user_id ORDER BY steps_date) AS steps_date_pre2,
        ROUND(AVG(CAST(steps_count AS FLOAT)) OVER (PARTITION BY user_id ORDER BY steps_date ROWS BETWEEN 2 PRECEDING AND CURRENT ROW), 2) AS rolling_average
    FROM Steps
)
SELECT
    user_id,
    steps_date,
    rolling_average
FROM a
WHERE DATEDIFF(DAY, steps_date_pre2, steps_date) = 2  -- filters null rows and consecutive n != 2 cases
ORDER BY user_id, steps_date;