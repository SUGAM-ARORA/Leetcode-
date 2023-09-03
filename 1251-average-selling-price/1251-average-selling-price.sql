# Write your MySQL query statement below
SELECT
    p.product_id AS product_id,
    ROUND(SUM(u.units * p.price) / SUM(u.units), 2) AS average_price

FROM
    Prices AS p JOIN
    UnitsSold AS u

ON (
    (u.purchase_date BETWEEN p.start_date AND p.end_date) AND
    u.product_id = p.product_id
)

GROUP BY p.product_id