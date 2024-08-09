--
-- @lc app=leetcode id=1435 lang=mysql
--
-- [1435] Create a Session Bar Chart
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT '[0-5>' AS bin, COUNT(*) AS total FROM `Sessions` WHERE duration >= 0 AND duration < 300
UNION
SELECT '[5-10>' AS bin, COUNT(*) AS total FROM `Sessions` WHERE duration >= 300 AND duration < 600
UNION
SELECT '[10-15>' AS bin, COUNT(*) AS total FROM `Sessions` WHERE duration >= 600 AND duration < 900
UNION
SELECT '15 or more' AS bin, COUNT(*) AS total FROM `Sessions` WHERE duration >= 900;

-- @lc code=end

