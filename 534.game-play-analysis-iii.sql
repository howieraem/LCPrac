--
-- @lc app=leetcode id=534 lang=mysql
--
-- [534] Game Play Analysis III
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    player_id,
    event_date,
    SUM(games_played) OVER (PARTITION BY player_id ORDER BY event_date) AS games_played_so_far
FROM Activity
WHERE event_date is NOT NULL
ORDER BY player_id, event_date;

-- @lc code=end

