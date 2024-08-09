--
-- @lc app=leetcode id=1495 lang=mysql
--
-- [1495] Friendly Movies Streamed Last Month
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT DISTINCT c.title
FROM TVProgram t
INNER JOIN Content c
ON t.content_id = c.content_id
    AND c.kids_content = 'Y'
    AND c.content_type = 'Movies'
    AND t.program_date BETWEEN '2020-06-01' AND '2020-06-30';

-- @lc code=end

