SELECT a.NAME, b.BALANCE FROM Users a JOIN
(SELECT account, SUM(amount) AS balance FROM Transactions GROUP BY account HAVING SUM(amount) > 10000) b ON a.account = b.account;
