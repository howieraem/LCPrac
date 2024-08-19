--
-- @lc app=leetcode id=1308 lang=mysql
--
-- [1308] Running Total for Different Genders
--

-- @lc code=start
-- Write your MySQL query statement below
/* Solution 1: window func */
SELECT
    gender,
    `day`,
    SUM(score_points) OVER (PARTITION BY gender ORDER BY `day`) AS total
FROM Scores;

/* Solution 2: without window func
SELECT s1.gender, s1.day, SUM(s2.score_points) AS total
FROM Scores s1
INNER JOIN Scores s2
ON s1.gender = s2.gender AND s1.day >= s2.day
GROUP BY s1.gender, s1.day
ORDER BY s1.gender, s1.day;
*/

-- @lc code=end

