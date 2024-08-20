--
-- @lc app=leetcode id=1341 lang=mysql
--
-- [1341] Movie Rating
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        u1.name
    FROM MovieRating m1
    LEFT JOIN Users u1
    ON m1.user_id = u1.user_id
    GROUP BY m1.user_id, u1.name
    ORDER BY COUNT(m1.user_id) DESC, u1.name
    LIMIT 1
),
b AS (
    SELECT
        m3.title
    FROM MovieRating m2
    LEFT JOIN Movies m3
    ON m2.movie_id = m3.movie_id
    WHERE LEFT(m2.created_at, 7) = '2020-02'
    GROUP BY m3.title
    ORDER BY AVG(CAST(m2.rating AS DECIMAL(18, 2))) DESC, m3.title
    LIMIT 1
)
SELECT `name` AS results FROM a
UNION ALL
SELECT * from b;

-- @lc code=end

