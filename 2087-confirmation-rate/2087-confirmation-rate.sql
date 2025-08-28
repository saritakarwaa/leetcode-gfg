select s.user_id,
round(sum(if(c.action ='confirmed',1,0))/count(s.user_id), 2) as confirmation_rate
from Signups s left join Confirmations c
on s.user_id=c.user_id
group by user_id
order by confirmation_rate