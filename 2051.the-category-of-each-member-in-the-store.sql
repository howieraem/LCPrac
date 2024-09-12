--
-- @lc app=leetcode id=2051 lang=mysql
--
-- [2051] The Category of Each Member in the Store
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        m.member_id,
        m.name,
        CAST(COUNT(p.visit_id) AS DECIMAL(30, 2)) / CASE WHEN COUNT(v.visit_id) = 0 THEN NULL ELSE COUNT(v.visit_id) END AS cvr
    FROM Members m
    LEFT JOIN Visits v ON m.member_id = v.member_id
    LEFT JOIN Purchases p ON v.visit_id = p.visit_id
    GROUP BY m.member_id, m.name
    ORDER BY m.member_id
)
SELECT 
    member_id, 
    `name`,
    CASE
        WHEN cvr >= 0.8 THEN 'Diamond'
        WHEN cvr >= 0.5 THEN 'Gold'
        WHEN cvr < 0.5 THEN 'Silver'
        ELSE 'Bronze' -- null
    END AS category
FROM a;

-- @lc code=end

