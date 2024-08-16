--
-- @lc app=leetcode id=1204 lang=mysql
--
-- [1204] Last Person to Fit in the Bus
--

-- @lc code=start
-- Write your MySQL query statement below
/* Solution 1: without window function 
SELECT a.person_name
FROM `Queue` a
INNER JOIN `Queue` b
ON a.turn >= b.turn
GROUP BY a.person_id, a.person_name
HAVING SUM(b.weight) <= 1000
ORDER BY MIN(a.turn) DESC
LIMIT 1;
*/

/* Solution 2: with window function */
WITH a AS (
    SELECT 
        person_name, 
        turn, 
        SUM(`weight`) OVER (ORDER BY turn) AS sum_w
    FROM `Queue`
)
SELECT person_name
FROM a
WHERE sum_w <= 1000
ORDER BY turn DESC
LIMIT 1;

-- @lc code=end

