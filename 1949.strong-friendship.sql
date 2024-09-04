--
-- @lc app=leetcode id=1949 lang=mysql
--
-- [1949] Strong Friendship
--

-- @lc code=start
-- Write your MySQL query statement below
WITH tmp AS (
    SELECT user1_id, user2_id
    FROM Friendship
    UNION
    SELECT user2_id AS user1_id, user1_id AS user2_id
    FROM Friendship
)
SELECT 
    a.user1_id,
    a.user2_id,
    COUNT(c.user2_id) AS common_friend
FROM Friendship a
INNER JOIN tmp b 
    ON a.user1_id = b.user1_id  -- u1 friends
INNER JOIN tmp c
    ON a.user2_id = c.user1_id  -- u2 friends
    AND b.user2_id = c.user2_id -- u1 & u2 common friends
GROUP BY a.user1_id, a.user2_id
HAVING COUNT(c.user2_id) > 2;

-- @lc code=end

