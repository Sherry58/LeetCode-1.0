-- Write your PostgreSQL query statement below
WITH temp AS(
    SELECT *, 
        LAG(num,1) OVER(ORDER BY id) AS prev_num,
        LAG(num,2) OVER(ORDER BY id) AS prev2_num
    FROM Logs
)

SELECT DISTINCT num AS ConsecutiveNums
FROM temp
WHERE num = prev_num AND prev_num = prev2_num