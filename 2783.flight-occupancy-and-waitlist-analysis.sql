/* Write your T-SQL query statement below */
WITH a AS (
    SELECT flight_id, COUNT(*) AS cnt
    FROM Passengers
    GROUP BY flight_id
)
SELECT 
    f.flight_id,
    CASE 
        WHEN COALESCE(a.cnt, 0) > f.capacity THEN f.capacity ELSE COALESCE(a.cnt, 0)
    END AS booked_cnt,
    CASE 
        WHEN a.cnt > f.capacity THEN a.cnt - f.capacity ELSE 0  -- captures null
    END AS waitlist_cnt
FROM Flights f
LEFT JOIN a
    ON f.flight_id = a.flight_id
ORDER BY f.flight_id;