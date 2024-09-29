/* Write your T-SQL query statement below */
WITH a AS (
    SELECT 
        city,
        DATEPART(HOUR, call_time) AS peak_calling_hour,
        COUNT(*) AS number_of_calls
    FROM Calls
    GROUP BY city, DATEPART(HOUR, call_time)
),
b AS (
    SELECT 
        city, 
        peak_calling_hour, 
        number_of_calls, 
        DENSE_RANK() OVER (PARTITION BY city ORDER BY number_of_calls DESC) AS rk
    FROM a
)
SELECT 
    city, 
    peak_calling_hour, 
    number_of_calls
FROM b
WHERE rk = 1
ORDER BY peak_calling_hour DESC, city DESC;