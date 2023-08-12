# Write your MySQL query statement below
select e.name , b.bonus
from Employee e
left Join Bonus b
On e.empid = b.empid
where b.bonus < 1000 || b.bonus is null ;