/* Write your T-SQL query statement below */
WITH a AS (
    SELECT 
        post_id, 
        user_id,
        post_date,
        COUNT(*) OVER (PARTITION BY user_id) / 4.0 AS avg_weekly_posts
    FROM Posts
    WHERE post_date BETWEEN '2024-02-01' AND '2024-02-28'
),
b AS (
    SELECT
        p1.user_id,
        p1.post_date,
        COUNT(DISTINCT p2.post_id) AS seven_day_posts
    FROM Posts p1
    INNER JOIN Posts p2 ON p1.user_id = p2.user_id AND p2.post_date BETWEEN DATEADD(DAY, -6, p1.post_date) AND p1.post_date
    WHERE p1.post_date BETWEEN '2024-02-01' AND '2024-02-28'
    GROUP BY p1.user_id, p1.post_date
)
SELECT 
    DISTINCT a.user_id,
    MAX(seven_day_posts) AS max_7day_posts,
    avg_weekly_posts
FROM a
JOIN b ON a.user_id = b.user_id
WHERE seven_day_posts >= 2 * avg_weekly_posts
GROUP BY a.user_id, avg_weekly_posts
ORDER BY a.user_id;