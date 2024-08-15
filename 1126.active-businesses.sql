--
-- @lc app=leetcode id=1126 lang=mysql
--
-- [1126] Active Businesses
--

-- @lc code=start
-- Write your MySQL query statement below
/* Solution 1: with window function and case */
WITH a AS (
    SELECT 
        business_id, 
        CASE
            WHEN occurrences > AVG(occurrences) OVER (PARTITION BY event_type) THEN 1
            ELSE 0
        END AS active_flag 
    FROM Events
)
SELECT business_id
FROM a
GROUP BY business_id
HAVING SUM(active_flag) > 1;

/* Solution 2: without window function 
SELECT business_id
FROM Events e1
INNER JOIN (
    SELECT event_type, AVG(occurrences) AS avg_occur
    FROM Events
    GROUP BY event_type
) e2
ON e1.event_type = e2.event_type AND e1.occurrences > e2.avg_occur
GROUP BY business_id
HAVING COUNT(*) > 1;
*/

-- @lc code=end

