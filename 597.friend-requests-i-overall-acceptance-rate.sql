--
-- @lc app=leetcode id=597 lang=mysql
--
-- [597] Friend Requests I: Overall Acceptance Rate
--

-- @lc code=start
-- Write your MySQL query statement below
WITH c1 AS (
    SELECT CAST(COUNT(*) AS FLOAT) AS count1 
    FROM (
        SELECT DISTINCT requester_id, accepter_id
        FROM RequestAccepted
    ) a
),
c2 AS (
    SELECT CAST(COUNT(*) AS FLOAT) AS count2 
    FROM (
        SELECT DISTINCT sender_id, send_to_id
        FROM FriendRequest
    ) b
)
SELECT ROUND(IFNULL(count1 / count2, 0.0), 2) AS accept_rate  -- need to include IFNULL in case both tables are empty
FROM c1, c2;

-- Follow-up 1: monthly acceptance rate
-- SELECT 
--     EXTRACT(YEAR_MONTH from f.request_date) as year_month, 
--     ROUND(
--         IFNULL(
--             CAST(COUNT(DISTINCT r.requester_id, r.accepter_id) AS FLOAT) / 
--                 CAST(COUNT(DISTINCT f.sender_id, f.send_to_id) AS FLOAT), 
--             0.0), 
--         2) AS accept_rate
-- FROM FriendRequest f 
-- JOIN RequestAccepted r 
-- ON EXTRACT(YEAR_MONTH FROM f.request_date) = EXTRACT(YEAR_MONTH FROM r.accept_date)
-- GROUP BY 1;

-- Follow-up 2: daily accumulative acceptance rate 
/*
-- sum up the case when ind is 'a', which means it belongs to accept table, divided by sum of ind is 'r', which means it belong to request table
select 
    s.date1, 
    ifnull(
        round(
            sum(case when t.ind = 'a' then t.cnt else 0 end) / 
                sum(case when t.ind = 'r' then t.cnt else 0 end),
            2), 
        0) as accept_rate
from
-- get a table of all unique dates
    (
        select distinct x.request_date as date1 
        from FriendRequest x
        -- The reason here use union since we don't want duplicate date
        union 
        select distinct y.accept_date as date1 
        from RequestAccepted y 
    ) s
-- left join to make sure all dates are in the final output
left join 
-- get a table of all dates, count of each days, ind to indicate which table it comes from
    (
        select v.request_date as date1, count(*) as cnt, 'r' as ind 
        from 
            (
                select sender_id, send_to_id, min(request_date) as request_date 
                from FriendRequest 
                group by sender_id, send_to_id
            ) v
        group by v.request_date
        -- The reason here use union all since union all will be faster
        union all
        select w.accept_date as date1, count(*) as cnt, 'a' as ind 
        from 
            (
                select requester_id, accepter_id, min(accept_date) as accept_date 
                from RequestAccepted 
                group by requester_id, accepter_id
            ) w 
        group by w.accept_date
    ) t
-- s.date1 >= t.date1, which for each record in s, it will join with all records earlier than it in t
on s.date1 >= t.date1
-- group by s.date1 then we can get a cumulative result to that day
group by s.date1
order by s.date1;
*/

-- @lc code=end

