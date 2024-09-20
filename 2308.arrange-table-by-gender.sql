/* Write your T-SQL query statement below */
WITH cte AS (
    SELECT 
        user_id,
        gender,
        ROW_NUMBER() OVER (PARTITION BY gender ORDER BY user_id) AS u_rk,
        CASE 
            WHEN gender = 'female' THEN 1
            WHEN gender = 'other' THEN 2
            WHEN gender = 'male' THEN 3
        END AS g_rk
    FROM genders
)
SELECT user_id, gender
FROM cte
ORDER BY u_rk, g_rk;