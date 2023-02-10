SELECT customers.name AS 'Customers'
FROM customers
WHERE customers.id NOT IN
(
    SELECT customerid FROM orders
);
