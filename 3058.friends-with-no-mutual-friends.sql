/* Write your T-SQL query statement below */
WITH all_friends AS (
    SELECT 
        user_id1 AS uid,
        user_id2 AS friend
    FROM Friends
    UNION ALL
    SELECT
        user_id2 AS uid,
        user_id1 AS friend
    FROM Friends
),
mutual AS (
    SELECT
        f.user_id1,
        f.user_id2,
        a1.friend AS mutual_friend
    FROM Friends f
    JOIN all_friends a1 ON a1.uid = f.user_id1
    JOIN all_friends a2 ON a2.uid = f.user_id2 AND a1.friend = a2.friend
)
SELECT
    f.user_id1,
    f.user_id2
FROM Friends f
LEFT JOIN mutual m ON f.user_id1 = m.user_id1 AND f.user_id2 = m.user_id2
WHERE m.mutual_friend IS NULL
ORDER BY f.user_id1, f.user_id2;
