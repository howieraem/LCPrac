--
-- @lc app=leetcode id=578 lang=mysql
--
-- [578] Get Highest Answer Rate Question
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    question_id AS survey_log
FROM SurveyLog
GROUP BY question_id
ORDER BY
    SUM(CASE WHEN `action` = 'answer' THEN 1.00 ELSE 0.00 END) / SUM(CASE WHEN `action` = 'show' THEN 1.00 ELSE 0.00 END) DESC,
    question_id
LIMIT 1;

-- @lc code=end

