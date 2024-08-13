--
-- @lc app=leetcode id=585 lang=mysql
--
-- [585] Investments in 2016
--

-- @lc code=start
-- Write your MySQL query statement below
/* Solution 1: window function */
SELECT 
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM (
    SELECT 
        tiv_2016,
        COUNT(*) OVER (PARTITION BY tiv_2015) AS count_tiv_2015,
        COUNT(*) OVER (PARTITION BY lat, lon) AS count_loc
    FROM Insurance
) t
WHERE count_loc = 1
    AND count_tiv_2015 > 1;

/* Solution 2: without window function 
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(*) > 1
) 
    AND CONCAT(lat, lon) IN (
        SELECT 
        FROM Insurance
        GROUP BY lat, lon
        HAVING COUNT(*) = 1
    ) 
*/

-- @lc code=end

