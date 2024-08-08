--
-- @lc app=leetcode id=1113 lang=mysql
--
-- [1113] Reported Posts
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    extra AS report_reason,
    COUNT(DISTINCT(post_id)) AS report_count
FROM Actions
WHERE `action` = 'report'
  AND extra IS NOT NULL
  AND action_date = '2019-07-04'
GROUP BY extra;

-- @lc code=end

