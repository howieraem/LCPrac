--
-- @lc app=leetcode id=619 lang=mysql
--
-- [619] Biggest Single Number
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT MAX(num) as num
FROM (
    SELECT num 
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
) a;

-- @lc code=end

