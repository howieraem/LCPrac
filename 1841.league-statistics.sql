--
-- @lc app=leetcode id=1841 lang=mysql
--
-- [1841] League Statistics
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    team_name,
    COUNT(*) AS matches_played,
    SUM(
        CASE
            WHEN team_id = home_team_id AND home_team_goals > away_team_goals THEN 3
            WHEN team_id = home_team_id AND home_team_goals < away_team_goals THEN 0
            WHEN team_id = away_team_id AND home_team_goals < away_team_goals THEN 3
            WHEN team_id = away_team_id AND home_team_goals > away_team_goals THEN 0
            ELSE 1  -- draw
        END
    ) AS points,
    SUM(CASE WHEN team_id = home_team_id THEN home_team_goals ELSE away_team_goals END) AS goal_for,
    SUM(CASE WHEN team_id = home_team_id THEN away_team_goals ELSE home_team_goals END) AS goal_against,
    SUM(CASE WHEN team_id = home_team_id THEN home_team_goals ELSE away_team_goals END) - SUM(CASE WHEN team_id = home_team_id THEN away_team_goals ELSE home_team_goals END) AS goal_diff
FROM Teams
INNER JOIN Matches
    ON team_id = home_team_id 
        OR team_id = away_team_id  
GROUP BY team_name
ORDER BY points DESC, goal_diff DESC, team_name;

-- @lc code=end

