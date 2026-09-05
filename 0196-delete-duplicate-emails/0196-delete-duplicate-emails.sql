-- Write your PostgreSQL query statement below
-- WITH temp AS(
--     SELECT id, COUNT(*) OVER(PARTITION BY email)
--         FROM Person
        

-- )


-- DELETE FROM Person
-- WHERE id IN(
--     SELECT id FROM(
--         SELECT id, ROW_NUMBER() OVER(PARTITION BY email ORDER BY id) rn
--         FROM Person
--     ) t
--     WHERE rn > 1
-- )

DELETE
FROM Person p1
USING Person p2
WHERE p1.email = p2.email
AND 
p1.id > p2.id