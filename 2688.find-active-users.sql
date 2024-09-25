/* Write your T-SQL query statement below */
WITH a AS (
    SELECT
        user_id,
        DATEDIFF(DAY, created_at, LEAD(created_at) OVER (PARTITION BY user_id ORDER BY created_at)) AS diff
    FROM Users
)
SELECT DISTINCT user_id FROM a
WHERE diff IS NOT NULL -- if no corresponding created_at, some diff will be null
    AND diff <= 7;