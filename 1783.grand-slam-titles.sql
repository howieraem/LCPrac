--
-- @lc app=leetcode id=1783 lang=mysql
--
-- [1783] Grand Slam Titles
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT Wimbledon AS player_id FROM Championships
    UNION ALL
    SELECT Fr_open AS player_id FROM Championships
    UNION ALL
    SELECT US_open AS player_id FROM Championships
    UNION ALL
    SELECT Au_open AS player_id FROM Championships
)
SELECT 
    a.player_id, 
    p.player_name,
    COUNT(1) AS grand_slams_count
FROM a
INNER JOIN Players p
    ON a.player_id = p.player_id
GROUP BY a.player_id, p.player_name

-- @lc code=end

