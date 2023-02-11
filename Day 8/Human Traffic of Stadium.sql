WITH  q1 AS (
SELECT *, id - row_number() over() AS id_diff
FROM stadium
WHERE people > 99
)
SELECT id, visit_date, people
FROM q1
WHERE id_diff IN (SELECT id_diff FROM q1 GROUP BY id_diff HAVING COUNT(*) > 2)
ORDER BY visit_date;
