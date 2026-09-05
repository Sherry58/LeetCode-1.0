-- Write your PostgreSQL query statement below
WITH temp AS(
    SELECT *, 
        LEAD(num,1) OVER(ORDER BY id) AS next_num,
        LEAD(num,2) OVER(ORDER BY id) AS next2_num
    FROM Logs
)

SELECT DISTINCT num AS ConsecutiveNums
FROM temp
WHERE num = next_num AND next_num = next2_num