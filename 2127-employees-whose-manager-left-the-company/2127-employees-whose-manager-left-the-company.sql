# Write your MySQL query statement below
select e.employee_id from Employees e
left join Employees m on e.manager_id = m.employee_id
where m.employee_id is null and e.manager_id is not null and e.salary < 30000
order by e.employee_id;