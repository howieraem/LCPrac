--
-- @lc app=leetcode id=1212 lang=mysql
--
-- [1212] Team Scores in Football Tournament
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    t.team_id,
    t.team_name,
    IFNULL(SUM(
        CASE 
            WHEN m.host_goals > m.guest_goals AND t.team_id = m.host_team THEN 3
            WHEN m.host_goals = m.guest_goals AND t.team_id = m.host_team THEN 1
            WHEN m.host_goals < m.guest_goals AND t.team_id = m.host_team THEN 0
            WHEN m.host_goals > m.guest_goals AND t.team_id = m.guest_team THEN 0
            WHEN m.host_goals = m.guest_goals AND t.team_id = m.guest_team THEN 1
            WHEN m.host_goals < m.guest_goals AND t.team_id = m.guest_team THEN 3
        END), 0) AS num_points
FROM Teams t
CROSS JOIN Matches m
GROUP BY t.team_id, t.team_name
ORDER BY num_points DESC, t.team_id;

-- @lc code=end

