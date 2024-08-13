--
-- @lc app=leetcode id=180 lang=mysql
--
-- [180] Consecutive Numbers
--

-- @lc code=start
-- Write your MySQL query statement below

/* Solution 1: cross join, without window function 
SELECT DISTINCT l1.num AS ConsecutiveNums
FROM Logs l1 
CROSS JOIN Logs l2
CROSS JOIN Logs l3
WHERE l1.id = l2.id - 1
    AND l2.id = l3.id - 1
    AND l1.Num = l2.Num
    AND l2.Num = l3.Num;
*/

/* Solution 2: window function */
WITH a AS (
    SELECT 
        num,
        LEAD(num, 1) OVER() num1,
        LEAD(num, 2) OVER() num2,
        id,
        LEAD(id, 1) OVER() id1,
        LEAD(id, 2) OVER() id2
    FROM Logs
    ORDER BY id
)
SELECT DISTINCT num AS ConsecutiveNums 
FROM a 
WHERE num = num1 
    AND num = num2
    AND id1 - id = 1
    AND id2 - id1 = 1;

-- @lc code=end

