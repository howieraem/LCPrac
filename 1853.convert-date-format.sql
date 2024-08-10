--
-- @lc app=leetcode id=1853 lang=mysql
--
-- [1853] Convert Date Format
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT DATE_FORMAT(`day`, "%W, %M %e, %Y") AS `day`
FROM `Days`;

/* 
MS SQL Server solution:
SELECT 
    datename(weekday, day) 
        + ', ' 
        + datename(mm, day) 
        + ' ' 
        + datename(d, day) 
        + ', ' 
        + datename(year, day) AS day
FROM Days
*/

-- @lc code=end

