-- Keep a log of any SQL queries you execute as you solve the mystery.

-- 1. search info (discription) by current info (date & place)
SELECT description FROM crime_scene_reports
WHERE day = 28 AND month = 7 AND year = 2021
AND street = 'Humphrey Street';

-- Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
-- Interviews were conducted today with three witnesses who were present at the time
-- – each of their interview transcripts mentions the bakery. |
-- | Littering took place at 16:36. No known witnesses.

-- WRONG 2. .schema bakery_security_logs => check bakery but not right direction so far
-- know the entrance & exit something happened around 10:15am (there's no exact minute)
SELECT activity, license_plate, minute FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021
AND hour = 10; -- AND minute = 15;

-- +----------+---------------+--------+
-- | activity | license_plate | minute |
-- +----------+---------------+--------+
-- | entrance | R3G7486       | 8      |
-- | entrance | 13FNH73       | 14     |
-- | exit     | 5P2BI95       | 16     |

-- 2. .schema interviews => choose interviews table to find on that date who mentioned bakery
SELECT id, name, transcript FROM interviews
WHERE day = 28 AND month = 7 AND year = 2021 AND transcript LIKE '%bakery%';

-- 2-1. Ruth: cars/ security +- 5 (within 10 mins)
-- 2-2. Eugene: ATM on Leggett Street, withdrawing some money, before theft
-- 2-3. Raymond: phone / <1min/ the earliest flight/tomorrow (7/29/2021)

-- 2-1 Ruth: cars/ security +- 5 (within 10 mins)
SELECT id, activity, license_plate, minute FROM bakery_security_logs
WHERE day = 28 AND month = 7 AND year = 2021
AND hour = 10;

-- | 260 | exit     | 5P2BI95       | 16     |
-- | 261 | exit     | 94KL13X       | 18     |
-- | 262 | exit     | 6P58WS2       | 18     |
-- | 263 | exit     | 4328GD8       | 19     |
-- | 264 | exit     | G412CB7       | 20     |
-- | 265 | exit     | L93JTIZ       | 21     |
-- | 266 | exit     | 322W7JE       | 23     |
-- | 267 | exit     | 0NTHK55       | 23     |

-- 2-2 Eugene: ATM on Leggett Street, withdrawing some money, before theft
-- .schema atm_transactions
SELECT DISTINCT transaction_type FROM atm_transactions;

SELECT DISTINCT atm_location FROM atm_transactions;

SELECT id, account_number, amount FROM atm_transactions
WHERE transaction_type = 'withdraw' AND atm_location = 'Leggett Street'
AND day = 28 AND month = 7 AND year = 2021;

-- +-----+----------------+--------+
-- | id  | account_number | amount |
-- +-----+----------------+--------+
-- | 246 | 28500762       | 48     |
-- | 264 | 28296815       | 20     |
-- | 266 | 76054385       | 60     |
-- | 267 | 49610011       | 50     |
-- | 269 | 16153065       | 80     |
-- | 288 | 25506511       | 20     |
-- | 313 | 81061156       | 30     |
-- | 336 | 26013199       | 35     |
-- +-----+----------------+--------+

-- 2-3 Raymond: phone / <1min/ the earliest flight/tomorrow (7/29/2021)
-- .schema phone_calls
SELECT DISTINCT duration FROM phone_calls WHERE duration < 60;

SELECT id, caller, receiver FROM phone_calls
WHERE duration < 60
AND day = 28 AND month = 7 AND year = 2021;

-- +-----+----------------+----------------+
-- | id  |     caller     |    receiver    |
-- +-----+----------------+----------------+
-- | 221 | (130) 555-0289 | (996) 555-8899 |
-- | 224 | (499) 555-9472 | (892) 555-8872 |
-- | 233 | (367) 555-5533 | (375) 555-8161 |
-- | 251 | (499) 555-9472 | (717) 555-1342 |
-- | 254 | (286) 555-6063 | (676) 555-6554 |
-- | 255 | (770) 555-1861 | (725) 555-3243 |
-- | 261 | (031) 555-6622 | (910) 555-3251 |
-- | 279 | (826) 555-1652 | (066) 555-9701 |
-- | 281 | (338) 555-6650 | (704) 555-2131 |
-- +-----+----------------+----------------+


-- 3. bank account 裡面有 person_id, account_number, creation_year

-- 4. 比對 flights 中的 airport id 與 airpot 中的 id
SELECT * FROM airports;
-- +----+--------------+-----------------------------------------+---------------+
-- | id | abbreviation |                full_name                |     city      |
-- +----+--------------+-----------------------------------------+---------------+
-- | 1  | ORD          | O'Hare International Airport            | Chicago       |
-- | 2  | PEK          | Beijing Capital International Airport   | Beijing       |
-- | 3  | LAX          | Los Angeles International Airport       | Los Angeles   |
-- | 4  | LGA          | LaGuardia Airport                       | New York City |
-- | 5  | DFS          | Dallas/Fort Worth International Airport | Dallas        |
-- | 6  | BOS          | Logan International Airport             | Boston        |
-- | 7  | DXB          | Dubai International Airport             | Dubai         |
-- | 8  | CSF          | Fiftyville Regional Airport             | Fiftyville    |
-- | 9  | HND          | Tokyo International Airport             | Tokyo         |
-- | 10 | CDG          | Charles de Gaulle Airport               | Paris         |
-- | 11 | SFO          | San Francisco International Airport     | San Francisco |
-- | 12 | DEL          | Indira Gandhi International Airport     | Delhi         |
-- +----+--------------+-----------------------------------------+---------------+

SELECT * FROM flights
WHERE day = 29 AND month = 7 AND year = 2021;
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | id | origin_airport_id | destination_airport_id | year | month | day | hour | minute |
-- +----+-------------------+------------------------+------+-------+-----+------+--------+
-- | 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |

-- => 7/29/2021 8:20 的飛機，飛往紐約
-- | 4  | LGA          | LaGuardia Airport                       | New York City |

-- 5. 檢視一下人員名單，舉例：
SELECT * FROM people;
-- +--------+-------------+----------------+-----------------+---------------+
-- |   id   |    name     |  phone_number  | passport_number | license_plate |
-- +--------+-------------+----------------+-----------------+---------------+
-- | 205082 | Pamela      | (113) 555-7544 | 1050247273      | 5CIO816       |


-- 6. 試著檢視搭機名單
SELECT * FROM passengers;
-- +-----------+-----------------+------+
-- | flight_id | passport_number | seat |
-- +-----------+-----------------+------+
-- | 1         | 2400516856      | 2C   |


-- 6-2. 哩出 護照號碼
SELECT passport_number, seat FROM passengers
JOIN flights ON passengers.flight_id = flights.id
WHERE hour = 8 AND day = 29 AND month = 7 AND year = 2021;

-- +-----------------+------+
-- | passport_number | seat |
-- +-----------------+------+
-- | 7214083635      | 2A   |
-- | 1695452385      | 3B   |
-- | 5773159633      | 4A   |
-- | 1540955065      | 5C   |
-- | 8294398571      | 6C   |
-- | 1988161715      | 6D   |
-- | 9878712108      | 7A   |
-- | 8496433585      | 7B   |
-- +-----------------+------+

-- 7. 現在有的資料：
-- 共犯：receiver number
-- 小偷(似乎不只一個）they!?：護照號碼 ＋ call number ＋ bank account 比對 id ? => 找到三個人
-- 不一定是誰的：車牌號碼

-- 7-1 passport num -> people 比對
SELECT * FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
WHERE hour = 8 AND day = 29 AND month = 7 AND year = 2021;

-- 7-2 比對電話？ 有重複的
-- 先確認一下各個表頭，因此用 ＊
SELECT * FROM people
JOIN phone_calls AS pc ON people.phone_number = pc.caller AND pc.duration < 60
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights AS fl ON passengers.flight_id = fl.id
WHERE fl.hour = 8 AND fl.day = 29 AND fl.month = 7 AND fl.year = 2021
AND pc.day = 28 AND pc.month = 7 AND pc.year = 2021;

-- 比對一下 bank_account & atm_trans 不用這行也可以

SELECT * FROM people AS pp
JOIN phone_calls AS pc ON pp.phone_number = pc.caller AND pc.duration < 60
JOIN passengers AS ps ON pp.passport_number = ps.passport_number
JOIN flights AS fl ON ps.flight_id = fl.id
JOIN bank_accounts AS ba ON pp.id = ba.person_id
-- JOIN atm_transactions AS atm ON ba.account_number = atm.account_number 不用這行也可以
WHERE fl.hour = 8 AND fl.day = 29 AND fl.month = 7 AND fl.year = 2021
AND pc.day = 28 AND pc.month = 7 AND pc.year = 2021
-- AND atm.day = 28 AND atm.month = 7 AND atm.year = 2021;


-- 小偷(似乎不只一個）they!?：護照號碼 ＋ call number ＋ bank account 比對 id ? => 找到三個人
SELECT * FROM people AS pp
JOIN phone_calls AS pc ON pp.phone_number = pc.caller AND pc.duration < 60
JOIN passengers AS ps ON pp.passport_number = ps.passport_number
JOIN flights AS fl ON ps.flight_id = fl.id
JOIN bank_accounts AS ba ON pp.id = ba.person_id
WHERE fl.hour = 8 AND fl.day = 29 AND fl.month = 7 AND fl.year = 2021
AND pc.day = 28 AND pc.month = 7 AND pc.year = 2021;

-- 詳列重點
SELECT pp.id, pp.name, pp.phone_number, pp.passport_number, pp.license_plate, pc.receiver, ps.seat, ba.account_number FROM people AS pp
JOIN phone_calls AS pc ON pp.phone_number = pc.caller AND pc.duration < 60
JOIN passengers AS ps ON pp.passport_number = ps.passport_number
JOIN flights AS fl ON ps.flight_id = fl.id
JOIN bank_accounts AS ba ON pp.id = ba.person_id
WHERE fl.hour = 8 AND fl.day = 29 AND fl.month = 7 AND fl.year = 2021
AND pc.day = 28 AND pc.month = 7 AND pc.year = 2021;

-- +--------+--------+----------------+-----------------+---------------+----------------+------+----------------+
-- |   id   |  name  |  phone_number  | passport_number | license_plate |    receiver    | seat | account_number |
-- +--------+--------+----------------+-----------------+---------------+----------------+------+----------------+
-- | 686048 | Bruce  | (367) 555-5533 | 5773159633      | 94KL13X       | (375) 555-8161 | 4A   | 49610011       |
-- | 395717 | Kenny  | (826) 555-1652 | 9878712108      | 30G67EN       | (066) 555-9701 | 7A   | 28296815       |
-- | 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       | (676) 555-6554 | 6D   | 76054385       |
-- +--------+--------+----------------+-----------------+---------------+----------------+------+----------------+

-- 8.確定下來，一樣車牌的即是犯人
SELECT pp.id, pp.name, pp.phone_number, pp.passport_number, pp.license_plate, pc.receiver, ps.seat, ba.account_number FROM people AS pp
JOIN phone_calls AS pc ON pp.phone_number = pc.caller AND pc.duration < 60
JOIN passengers AS ps ON pp.passport_number = ps.passport_number
JOIN flights AS fl ON ps.flight_id = fl.id
JOIN bank_accounts AS ba ON pp.id = ba.person_id
JOIN bakery_security_logs AS bsl ON pp.license_plate = bsl.license_plate
WHERE fl.hour = 8 AND fl.day = pc.day + 1 AND fl.month = 7 AND fl.year = 2021
AND pc.day = 28 AND pc.month = 7 AND pc.year = 2021
AND bsl.minute < 15 + 10 AND bsl.hour = 10 AND bsl.day = 28 AND bsl.month = 7 AND bsl.year = 2021;


-- 9. receiver 即是共犯 Robin
SELECT pp.id, pp.name, pp.phone_number, pp.passport_number, pp.license_plate, ps.seat, ba.account_number, pp2.name, pc.receiver FROM people AS pp
JOIN phone_calls AS pc ON pp.phone_number = pc.caller AND pc.duration < 60
JOIN passengers AS ps ON pp.passport_number = ps.passport_number
JOIN flights AS fl ON ps.flight_id = fl.id
JOIN bank_accounts AS ba ON pp.id = ba.person_id
JOIN bakery_security_logs AS bsl ON pp.license_plate = bsl.license_plate
JOIN people AS pp2 ON pc.receiver = pp2.phone_number
WHERE fl.hour = 8 AND fl.day = pc.day + 1 AND fl.month = 7 AND fl.year = 2021
AND pc.day = 28 AND pc.month = 7 AND pc.year = 2021
AND bsl.minute < 15 + 10 AND bsl.hour = 10 AND bsl.day = 28 AND bsl.month = 7 AND bsl.year = 2021;

--10 小結
-- The THIEF is: Bruce
-- The city the thief ESCAPED TO: New York City
-- The ACCOMPLICE is: Robin