-- Write your PostgreSQL query statement below
WITH temp AS (SELECT *,
    SUM(weight) OVER (ORDER BY turn) AS Total_Weight
FROM Queue
) 

SELECT person_name FROM temp
WHERE Total_Weight <= 1000
ORDER BY Total_Weight DESC
LIMIT 1
