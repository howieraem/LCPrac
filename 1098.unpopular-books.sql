--
-- @lc app=leetcode id=1098 lang=mysql
--
-- [1098] Unpopular Books
--

-- @lc code=start
-- Write your MySQL query statement below
SELECT 
    b.book_id,
    b.name
FROM (
    SELECT book_id, `name`
    FROM Books
    WHERE DATEDIFF('2019-06-23', available_from) >= 30
) b
LEFT JOIN (
    SELECT book_id, quantity
    FROM Orders
    WHERE DATEDIFF('2019-06-23', dispatch_date) <= 365
) o
ON b.book_id = o.book_id
GROUP BY b.book_id, b.name
HAVING SUM(IFNULL(o.quantity, 0)) < 10;

-- @lc code=end

