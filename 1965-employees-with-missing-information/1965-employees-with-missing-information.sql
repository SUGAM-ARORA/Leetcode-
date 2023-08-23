# Write your MySQL query statement below
Select e.employee_id from Employees e 
LEFT JOIN Salaries s 
ON e.employee_id = s.employee_id
WHERE s.salary  is NULL

UNION

Select s.employee_id from Salaries s
LEFT JOIN Employees e 
ON e.employee_id = s.employee_id
WHERE e.name is NULL

ORDER BY employee_id;