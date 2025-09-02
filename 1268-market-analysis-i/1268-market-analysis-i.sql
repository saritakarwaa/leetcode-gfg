-- select u.user_id as buyer_id,u.join_date,ifnull(count(o.order_id),0) as orders_in_2019 
-- from Users u left join Orders o on u.user_id=o.buyer_id 
-- and year(o.order_date) = '2019'
-- group by o.buyer_id,u.join_date
-- order by o.buyer_id
SELECT 
    u.user_id AS buyer_id,
    u.join_date,
    COUNT(CASE 
              WHEN o.order_date BETWEEN '2019-01-01' AND '2019-12-31' 
              THEN o.order_id 
         END) AS orders_in_2019
FROM Users u
LEFT JOIN Orders o
    ON u.user_id = o.buyer_id
GROUP BY u.user_id, u.join_date
ORDER BY u.user_id;
