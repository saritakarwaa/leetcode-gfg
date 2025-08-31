select t.request_at as Day,
round(sum(if(t.status!="completed",1,0))/count('*'),2) as "Cancellation Rate"
from trips t
inner join users u1 on t.client_id=u1.users_id 
inner join users u2 on t.driver_id=u2.users_id
where t.request_at between "2013-10-01" and "2013-10-03" and u1.banned='No' and u2.banned='No'
group by request_at


-- SELECT t.request_at as Day,ROUND(SUM(IF(t.status!="completed",1,0))/count('*'),2) AS "Cancellation Rate"
-- FROM Trips as t
-- LEFT JOIN Users AS u1 ON t.client_id=u1.users_id 
-- LEFT JOIN Users AS u2 ON t.driver_id=u2.users_id 
-- WHERE t.request_at BETWEEN "2013-10-01" AND "2013-10-03" AND u1.banned='NO' AND u2.banned='NO'
-- group by t.request_at