SELECT 
    request_at AS "Day",
    round(
        (sum(case when status = "cancelled_by_driver" OR status = "cancelled_by_client" then 1 else 0 end) / count(status)), 2
    ) AS "Cancellation Rate"
FROM
    Trips
WHERE
    client_id NOT IN (SELECT users_id FROM Users WHERE role = 'client' AND banned ='Yes') 
AND
    driver_id NOT IN (SELECT users_id FROM Users WHERE role = 'driver' AND banned ='Yes') 
AND 
    request_at >= "2013-10-01" AND request_at <= "2013-10-03"
GROUP BY 
    request_at;
