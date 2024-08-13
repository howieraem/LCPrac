--
-- @lc app=leetcode id=608 lang=mysql
--
-- [608] Tree Node
--

-- @lc code=start
-- Write your MySQL query statement below

SELECT
    a.id AS id,
    CASE 
        WHEN a.p_id IS NULL THEN 'Root'
        WHEN a.p_id IS NOT NULL AND b.p_id IS NOT NULL THEN 'Inner'
        ELSE 'Leaf' 
    END AS `type`
FROM Tree a
LEFT JOIN (
    SELECT DISTINCT p_id FROM Tree
) b
ON a.id = b.p_id
ORDER BY a.id;

-- @lc code=end

