-- select s1.stock_name , 
-- sum(s2.price)-sum(s1.price) as capital_gain_loss from Stocks s1 join Stocks s2
-- where s1.stock_name=s2.stock_name and 
-- s1.operation="Buy" and s2.operation="Sell"
-- group by s1.stock_name
SELECT 
    stock_name,
    SUM(CASE WHEN operation = 'Sell' THEN price ELSE 0 END) 
    - SUM(CASE WHEN operation = 'Buy' THEN price ELSE 0 END) AS capital_gain_loss
FROM Stocks
GROUP BY stock_name;
