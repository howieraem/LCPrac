--
-- @lc app=leetcode id=1149 lang=mysql
--
-- [1149] Article Views II
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT DISTINCT viewer_id AS id
FROM Views
GROUP BY view_date, viewer_id
HAVING COUNT(DISTINCT article_id) >= 2
ORDER BY viewer_id;

-- @lc code=end

