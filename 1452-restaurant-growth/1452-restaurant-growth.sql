# Write your MySQL query statement below
select distinct visited_on,
sum(amount) over (order by visited_on RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW) as amount
,round(sum(amount) over (order by visited_on RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW)/7,2) as average_amount
from Customer
limit 1000000
offset 6