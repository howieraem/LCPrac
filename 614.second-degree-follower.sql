--
-- @lc app=leetcode id=614 lang=mysql
--
-- [614] Second Degree Follower
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    a.follower AS `follower`,
    COUNT(DISTINCT b.follower) AS num
FROM Follow a
INNER JOIN Follow b
ON a.follower = b.followee
GROUP BY a.follower
ORDER BY a.follower;

-- @lc code=end

