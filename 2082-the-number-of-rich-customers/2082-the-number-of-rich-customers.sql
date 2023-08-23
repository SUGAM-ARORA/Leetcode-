# Write your MySQL query statement below
select Count(Distinct customer_id) as rich_count
from Store
where amount > 500;