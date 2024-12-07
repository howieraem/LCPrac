/* Write your T-SQL query statement below */
SELECT tweet_id
FROM Tweets
WHERE LEN(content) > 140
    OR content LIKE '%@%@%@%@%'
    OR content LIKE '%#%#%#%#%'