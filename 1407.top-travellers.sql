--
-- @lc app=leetcode id=1407 lang=mysql
--
-- [1407] Top Travellers
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    u.name,
    SUM(IFNULL(r.distance, 0)) AS travelled_distance
FROM Users u
LEFT JOIN Rides r
ON u.id = r.user_id
GROUP BY u.id, u.name
ORDER BY 2 DESC, 1

-- @lc code=end

