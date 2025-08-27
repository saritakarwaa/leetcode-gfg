# Write your MySQL query statement below
select department,employee,salary from
(
    select d.name as department,e.name as employee,e.salary as salary,
        dense_rank() over (partition by departmentId order by salary desc)
    as ranks
    from Employee e left join Department d
    on e.departmentId=d.id
) temp
where ranks<=3