/* Write your T-SQL query statement below */
-- get all substrings starting with '#'
WITH tag_info AS (
    SELECT
        SUBSTRING(tweet, CHARINDEX('#', tweet), LEN(tweet)) substr,
        LEN(SUBSTRING(tweet, CHARINDEX('#', tweet), LEN(tweet))) substr_len
    FROM Tweets
),
-- extract hashtags in these substrings based on the next space char
tags AS (
    SELECT
        LEFT(
            substr, 
            CASE 
                WHEN CHARINDEX(' ', substr) = 0 THEN substr_len 
                ELSE CHARINDEX(' ', substr)
            END
        ) AS hashtag
    FROM tag_info
)
SELECT TOP 3
    hashtag,
    COUNT(1) AS hashtag_count
FROM tags
GROUP BY hashtag
ORDER BY COUNT(1) DESC, hashtag DESC;

