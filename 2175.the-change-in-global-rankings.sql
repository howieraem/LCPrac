WITH a AS (
    SELECT 
        t.team_id,
        t.name,
        CAST(ROW_NUMBER() OVER (ORDER BY t.points DESC, t.name) AS SIGNED) AS pre_rn,
        CAST(ROW_NUMBER() OVER (ORDER BY (t.points + c.points_change) DESC, t.name) AS SIGNED) AS cur_rn
    FROM TeamPoints t
    LEFT JOIN PointsChange c
    ON t.team_id = c.team_id
)
SELECT team_id, `name`, (pre_rn - cur_rn) AS rank_diff
FROM a;