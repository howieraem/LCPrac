--
-- @lc app=leetcode id=1951 lang=mysql
--
-- [1951] All the Pairs With the Maximum Number of Common Followers
--

-- @lc code=start
-- Write your MySQL query statement below
WITH a AS (
    SELECT
        r1.user_id AS user1_id,
        r2.user_id AS user2_id,
        COUNT(1) AS cnt
    FROM Relations r1
    LEFT JOIN Relations r2
    ON r1.user_id < r2.user_id
    WHERE r1.follower_id = r2.follower_id
    GROUP BY r1.user_id, r2.user_id
)
SELECT user1_id, user2_id
FROM a
WHERE cnt = (
    SELECT MAX(cnt) FROM a
);

-- @lc code=end

