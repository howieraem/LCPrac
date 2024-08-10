--
-- @lc app=leetcode id=1990 lang=mysql
--
-- [1990] Count the Number of Experiments
--

-- @lc code=start
-- Write your MySQL query statement below
WITH pe AS (
    SELECT * FROM (
        SELECT 'IOS' AS platform
        UNION ALL
        SELECT 'Android' AS platform
        UNION ALL
        SELECT 'Web' AS platform
    ) p
    CROSS JOIN (
        SELECT 'Programming' AS experiment_name
        UNION ALL
        SELECT 'Sports' AS experiment_name
        UNION ALL
        SELECT 'Reading' AS experiment_name
    ) e
)
SELECT 
    pe.platform,
    pe.experiment_name,
    COUNT(w.platform) AS num_experiments
FROM pe 
LEFT JOIN Experiments w
ON pe.platform = w.platform AND pe.experiment_name = w.experiment_name
GROUP BY 1, 2;


-- @lc code=end

