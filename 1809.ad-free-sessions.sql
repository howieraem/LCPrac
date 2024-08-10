--
-- @lc app=leetcode id=1809 lang=mysql
--
-- [1809] Ad-Free Sessions
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT `session_id`
FROM Playback p
LEFT JOIN Ads a
ON p.customer_id = a.customer_id
    AND a.timestamp >= p.start_time
    AND a.timestamp <= p.end_time
WHERE a.ad_id IS NULL;

-- @lc code=end

