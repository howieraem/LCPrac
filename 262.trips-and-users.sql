/* Write your PL/SQL query statement below */
WITH unbanned AS (
    SELECT id, t.client_id, t.driver_id, status, request_at AS Day
    FROM Trips t
    JOIN Users u1 ON t.client_id = u1.users_id AND u1.banned = 'No'
    JOIN Users u2 ON t.driver_id = u2.users_id AND u2.banned = 'No'
    ORDER BY id
)
SELECT Day, ROUND(SUM(CASE WHEN status != 'completed' THEN 1 ELSE 0 END) / COUNT(status), 2) AS "Cancellation Rate"
FROM unbanned
WHERE Day between '2013-10-01' AND '2013-10-03'
GROUP BY Day
ORDER BY Day;