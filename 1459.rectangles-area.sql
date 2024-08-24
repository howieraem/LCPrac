--
-- @lc app=leetcode id=1459 lang=mysql
--
-- [1459] Rectangles Area
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    a.id AS p1,
    b.id AS p2,
    (ABS(a.x_value - b.x_value) * ABS(a.y_value - b.y_value)) AS area
FROM Points a
INNER JOIN Points b
ON a.id < b.id
WHERE ABS(a.x_value - b.x_value) > 0 
    AND ABS(a.y_value - b.y_value) > 0
ORDER BY area DESC, p1, p2;

-- @lc code=end

