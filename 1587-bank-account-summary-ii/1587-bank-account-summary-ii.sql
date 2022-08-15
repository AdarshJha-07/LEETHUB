# Write your MySQL query statement below

select tt.name,tt.balance from 
(select  Sum(t.amount) as balance ,t.account,u.name from Transactions t join Users u on t.account = u.account group by t.account)as tT WHERE tt.balance >10000; 