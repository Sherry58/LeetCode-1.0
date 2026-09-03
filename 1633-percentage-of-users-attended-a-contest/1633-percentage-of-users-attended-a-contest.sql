-- Write your PostgreSQL query statement below

SELECT contest_id, 
    ROUND(COUNT(DISTINCT u.user_id)*100/ (SELECT COUNT(*) FROM users) :: NUMERIC,2) AS percentage       
FROM
Register r LEFT JOIN Users u
ON r.user_id = u.user_id
GROUP BY contest_id
ORDER BY percentage DESC, r.contest_id ASC