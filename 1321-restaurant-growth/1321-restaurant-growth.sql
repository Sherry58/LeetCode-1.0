-- Write your PostgreSQL query statement below
WITH dailySum AS(
    SELECT visited_on, SUM(amount) AS daily_amount
    FROM Customer
    GROUP BY visited_on
),

rolling AS(
    SELECT visited_on, 
        SUM(daily_amount) OVER(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS amount,
        ROUND(AVG(daily_amount) OVER(ORDER BY visited_on ROWS BETWEEN 6 PRECEDING AND CURRENT ROW),2) AS average_amount
    FROM dailySum
)

SELECT visited_on, amount, average_amount
FROM rolling
WHERE visited_on >= (SELECT MIN(visited_on) + INTERVAL '6 days' FROM dailySum)
ORDER BY visited_on





        

