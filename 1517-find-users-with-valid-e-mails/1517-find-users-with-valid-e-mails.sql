-- Write your PostgreSQL query statement below
SELECT user_id, name, mail
FROM Users
WHERE mail IN (
    SELECT mail FROM Users
    WHERE mail ~ '^[A-Za-z][A-Za-z0-9_.-]*@leetcode\.com$'
)