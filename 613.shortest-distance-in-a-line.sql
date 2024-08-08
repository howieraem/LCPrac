--
-- @lc app=leetcode id=613 lang=mysql
--
-- [613] Shortest Distance in a Line
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT MIN(ABS(p1.x - p2.x)) AS shortest
FROM `Point` p1
JOIN `Point` p2
ON p1.x != p2.x;

-- @lc code=end

