--
-- @lc app=leetcode id=1729 lang=mysql
--
-- [1729] Find Followers Count
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    `user_id`,
    COUNT(1) AS followers_count
FROM Followers
GROUP BY 1
ORDER BY 1;

-- @lc code=end

