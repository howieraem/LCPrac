--
-- @lc app=leetcode id=512 lang=mysql
--
-- [512] Game Play Analysis II
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    player_id, device_id
FROM (
    SELECT 
        player_id, 
        device_id, 
        ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY event_date) AS rn
    FROM Activity
) a
WHERE rn = 1;

-- @lc code=end

