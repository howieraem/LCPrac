--
-- @lc app=leetcode id=1501 lang=mysql
--
-- [1501] Countries You Can Safely Invest In
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT c.name AS country
FROM Calls
INNER JOIN Person p 
    ON caller_id = p.id 
        OR callee_id = p.id 
INNER JOIN Country c ON country_code = LEFT(p.phone_number, 3)
GROUP BY c.name
HAVING AVG(duration) > (SELECT AVG(duration) FROM Calls);

-- @lc code=end

