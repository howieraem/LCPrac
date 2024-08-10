--
-- @lc app=leetcode id=2072 lang=mysql
--
-- [2072] The Winner University
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT
    CASE
        WHEN c1 > c2 THEN 'New York University'
        WHEN c1 < c2 THEN 'California University'
        ELSE 'No Winner'
    END AS winner
FROM (
    SELECT SUM(CASE WHEN score >= 90 THEN 1 ELSE 0 END) c1 FROM NewYork
) ny 
CROSS JOIN (
    SELECT SUM(CASE WHEN score >= 90 THEN 1 ELSE 0 END) c2 FROM California
) ca;

-- @lc code=end

