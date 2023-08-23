# Write your MySQL query statement below
    select employee_id , salary as bonus 
            from employees 
            where employee_id%2 <>0 and name not like 'M%'
 
            union
            
            select employee_id , 0 as bonus
            from employees
            where employee_id%2 = 0 or name like 'M%'
            order by employee_id;