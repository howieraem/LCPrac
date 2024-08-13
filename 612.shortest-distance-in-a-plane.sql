--
-- @lc app=leetcode id=612 lang=mysql
--
-- [612] Shortest Distance in a Plane
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT 
        DISTINCT(CAST(SQRT(POWER(p1.x - p2.x, 2) + POWER(p1.y - p2.y, 2)) AS DECIMAL(18, 2))) as dist
    FROM Point2D p1
    CROSS JOIN Point2D p2
    WHERE p1.x != p2.x OR p1.y != p2.y
)
SELECT min(dist) as shortest FROM a;

-- @lc code=end

