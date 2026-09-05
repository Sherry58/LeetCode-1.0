-- Write your PostgreSQL query statement below

SELECT t.id AS id, SUM(t.num) AS num
FROM
    (SELECT requester_id AS id, COUNT(accepter_id) AS num
    FROM RequestAccepted
    GROUP BY requester_id

    UNION ALL

    SELECT accepter_id, COUNT(requester_id) 
    FROM RequestAccepted
    GROUP BY accepter_id
) t

GROUP BY id
ORDER BY num DESC
LIMIT 1