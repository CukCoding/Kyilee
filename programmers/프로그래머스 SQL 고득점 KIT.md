# 프로그래머스 SQL 고득점 KIT

<a href="https://bronze-meteor-ab3.notion.site/SQL-KIT-b3bad63ba4124860be8f6424b36afe4d">SQL 고득점 킷 노션 정리본![https://bronze-meteor-ab3.notion.site/SQL-KIT-b3bad63ba4124860be8f6424b36afe4d] </a>


### 문자열 역순 정렬  - DESC

---

+ **역순 정렬하기**

  **SELECT** NAME, DATETIME **FROM** ANIMAL_INS **ORDER BY** ANIMAL_ID **DESC**;

<정렬 2개>
+ **여러기준으로 정렬하기**

  **SELECT** ANIMAL_ID, NAME, DATETIME **FROM** ANIMAL_INS **ORDER** **BY** NAME (**ASC)**, DATETIME **DESC**;

### 조건 - WHERE

---

+ **아픈 동물 찾기**
  
  **SELECT** ANIMAL_ID, NAME **FROM** ANIMAL_INS **WHERE** INTAKE_CONDITION="Sick" **ORDER** **BY** ANIMAL_ID;

  ```
  알파벳순 -ASC
  ```

+ **어린 동물 찾기**

  **SELECT** ANIMAL_ID, NAME **FROM** ANIMAL_INS **WHERE** **NOT** INTAKE_CONDITION="Aged" **ORDER** **BY** ANIMAL_ID;
  
### 상위 1개 뽑기(MAX, LIMIT)

---

<LIMIT 사용방법>

+ **상위 n개 레코드**

  **SELECT** NAME **FROM** ANIMAL_INS **ORDER** **BY** DATETIME **LIMIT** 1;

(비교기준이 select에 없을때)

<MIN,MAX 사용방법>

+ **최댓값 구하기**

  **SELECT** **MAX**(DATETIME) FROM ANIMAL_INS ;
  
  **SELECT** DATETIME **AS** "시간" **FROM** ANIMAL_INS **ORDER** **BY** DATETIME DESC **LIMIT** 1;
  
  (비교기준이 select에 있을 때 = **둘다가능**)

+ **최솟값 구하기**

  **SELECT** **MIN**(DATETIME) AS "시간" **FROM** ANIMAL_INS;
  
  
 ### 갯수세기

---

+ **동물 수 구하기**

  **SELECT** **COUNT**(ANIMAL_ID) **AS** 'count' **FROM** ANIMAL_INS;
  
  ```
  문자 쓸 때는 “” ‘’ 상관없음
  ```
+ **중복 제거하기**

  **SELECT** **COUNT**(**DISTINCT** NAME) AS "count" FROM ANIMAL_INS **WHERE** NAME **IS NOT NULL** ;

  <img width="196" alt="스크린샷 2022-02-26 오후 11 14 27" src="https://user-images.githubusercontent.com/74878998/155846366-62f830b3-b37f-4bc9-a412-7afbd6ae8e04.png">

  ```
  DISTINCT 는 열 이름 바로 옆에!
  IS NOT NULL은 WHERE 절에
  null 이 있는 열에 WHERE 조건 넣어주기
  ```
  
  
 ### ❗️GROUP BY

---

- **고양이와 개는 몇 마리 있을까**

  **SELECT** ANIMAL_TYPE, **COUNT**(ANIMAL_TYPE) **AS** "count" **FROM** ANIMAL_INS 
**GROUP** **BY** ANIMAL_TYPE **ORDER** **BY** ANIMAL_TYPE;

  <img width="241" alt="스크린샷 2022-02-26 오후 11 16 34" src="https://user-images.githubusercontent.com/74878998/155846433-ca53343c-364e-4d89-9d73-c4dc42224630.png">
  
  ```
  나온 조건들 명시하기 (이미 오름차순이어도 order by 조건 넣어주기)
  ```
- **동명 동물 수 찾기**

  **SELECT** NAME, COUNT(NAME) AS "COUNT" **FROM** ANIMAL_INS 
  **GROUP** **BY** NAME **HAVING** COUNT(NAME) >=2 **ORDER** **BY** NAME;
  
  ```
  ≥2 나 >1 이나 같음
  ```

  <img width="197" alt="스크린샷 2022-02-26 오후 11 16 47" src="https://user-images.githubusercontent.com/74878998/155846441-e201071b-247a-4a70-9081-d7150287f447.png">
  
  ```
  group by ~ having 순서
  HAVING : GROUP BY의 조건 설정
  선택할때는 컬럼만 설정말고 그 조건까지 (count(NAME)) 써놓기
  ```
  
  
- ❗️**입양 시각 구하기(1)**

  **SELECT** HOUR(DATETIME) HOUR, COUNT(DATETIME) AS "COUNT"
  **FROM** ANIMAL_OUTS **GROUP** **BY** HOUR(DATETIME)
  **HAVING** HOUR >= 9 **AND** HOUR <= 19 
  **ORDER** BY HOUR;

  <img width="237" alt="스크린샷 2022-02-26 오후 11 28 19" src="https://user-images.githubusercontent.com/74878998/155846787-0fcd12a8-041f-4437-8d41-f156b3554095.png">
  
  ```
  시간에는 HOUR(DATETIME)
  ```

- ❗️❗️**입양 시각 구하기(2)**

  **SET** @HOUR = -1; 
  **SELECT** (@HOUR := @HOUR +1) **AS** "HOUR",

    ( **SELECT** COUNT(HOUR(DATETIME)) **FROM** ANIMAL_OUTS
    **WHERE** HOUR(DATETIME) = @HOUR
    ) **AS** “COUNT”

  **FROM** ANIMAL_OUTS **WHERE** @HOUR <23; 

  <img width="191" alt="스크린샷 2022-02-26 오후 11 28 31" src="https://user-images.githubusercontent.com/74878998/155846794-32eedff3-7008-4cad-8ab8-7b3799ca2a2e.png">

  ```
  @HOUR =-1; 변수설정
  where @hour < 23; 24로 하니 24도 출력됨!
  특이한 컬럼을 만들고 싶다? select 열 안에 내부 문법 추가
  ```
  
  
 ### IS NULL - WHERE 절에 넣기

---

- **이름이 없는 동물의 아이디**

  **SELECT** ANIMAL_ID **FROM** ANIMAL_INS
  **WHERE** NAME **IS NULL**
  **ORDER BY** ANIMAL_ID

- **이름이 있는 동물의 아이디**

  **SELECT** ANIMAL_ID **FROM** ANIMAL_INS
  **WHERE** NAME **IS NOT NULL**
  **ORDER** **BY** ANIMAL_ID

- ❗️**NULL 처리하기**

  **SELECT** ANIMAL_TYPE, 
  **IFNULL**( NAME , "No name" ) **AS** NAME, 
  SEX_UPON_INTAKE **FROM** ANIMAL_INS **ORDER** **BY** ANIMAL_ID

  > null은 No name으로 처리


### ❗️❗️❗️❗️JOIN

---

<img width="529" alt="스크린샷 2022-02-26 오후 11 33 01" src="https://user-images.githubusercontent.com/74878998/155846921-8483fbf9-89d7-4d01-9f1a-bcf2a1f26f8a.png">

- INNER JOIN 교집합 (INNER 생략가능)
- LEFT,RIGHT JOIN (부분집합)
- OUTER JOIN(합집합, mysql 은 없음)

  > **JOIN~
  > ON**


- **없어진 기록 찾기**
  입양간 기록(OUTS)은 있는데, 보호소에 들어온(INS) 기록이 없는

  > **A** = OUTS, **B** = INS


  **SELECT** **OUTS**.ANIMAL_ID , **OUTS**.NAME
  **FROM** ANIMAL_OUTS **OUTS**

    **LEFT** **JOIN** ANIMAL_INS **INS**
    **ON** OUTS.ANIMAL_ID = INS.ANIMAL_ID

  **WHERE** INS.ANIMAL_ID **IS NULL**;


  > **A**= INS, **B**= OUTS

  **SELECT** OUTS.ANIMAL_ID , OUTS.NAME
  **FROM** ANIMAL_INS INS

    **RIGHT** **JOIN** ANIMAL_OUTS **OUTS**
    **ON** OUTS.ANIMAL_ID = INS.ANIMAL_ID

  **WHERE** INS.ANIMAL_ID **IS** **NULL**;
  
  
- **있었는데요 없었습니다**
  보호 시작일(INS)보다 입양일(OUTS)이 더 빠른 동물 조회
  = 빠르다? OUTS<INS 

                  
  **SELECT** OUTS.ANIMAL_ID, OUTS.NAME
  **FROM** ANIMAL_OUTS OUTS

    **JOIN** ANIMAL_INS INS
    **ON** OUTS.ANIMAL_ID = INS.ANIMAL_ID

  **WHERE** INS.DATETIME > OUTS.DATETIME
  **ORDER** **BY** INS.DATETIME
  
  
  
  
 - **오랜기간 보호한 동물(1)**
  아직 입양을 못 간 동물 중, 가장 오래 보호소에 있었던 동물 3마리
  = INS - O, OUTS - X

  **SELECT** INS.NAME, INS.DATETIME
  **FROM** ANIMAL_INS INS

   **LEFT** **JOIN** ANIMAL_OUTS OUTS
    **ON** OUTS.ANIMAL_ID = INS.ANIMAL_ID

  **WHERE** OUTS.ANIMAL_ID **IS NULL**
  **ORDER** **BY** INS.DATETIME **LIMIT** 3

- **보호소에서 중성화한 동물**
  INS- 중성화 x, OUTS - 중성화 O

  **SELECT** INS.ANIMAL_ID, INS.ANIMAL_TYPE, INS.NAME
  **FROM** ANIMAL_INS INS

    **JOIN** ANIMAL_OUTS OUTS
    **ON** INS.ANIMAL_ID = OUTS.ANIMAL_ID

  **WHERE** INS.SEX_UPON_INTAKE != OUTS.SEX_UPON_OUTCOME
  **ORDER** **BY** INS.ANIMAL_ID
  
  
  ### String, Date

---

- **루시와 엘라 찾기**

  **SELECT** ANIMAL_ID, NAME, SEX_UPON_INTAKE
  **FROM** ANIMAL_INS
  **WHERE** NAME= "Ella" or NAME= "Lucy" or NAME= "Pickle" or NAME= "Rogan" or 
  NAME= "Sabrina" or NAME= "Mitty"
  **ORDER** **BY** ANIMAL_ID

  <다른코드>

  **SELECT** ANIMAL_ID, NAME, SEX_UPON_INTAKE
  **FROM** ANIMAL_INS
  **WHERE** NAME **IN** ("Lucy", "Ella", "Pickle", "Rogan", "Sabrina", "Mitty")

- **이름에 el이 들어가는 동물 찾기**

  **SELECT** ANIMAL_ID, NAME
  **FROM** ANIMAL_INS
  **WHERE** NAME LIKE "%el%" **AND** ANIMAL_TYPE = "Dog"
  **ORDER** **BY** NAME

- **중성화 여부 판단하기**

  **SELECT** ANIMAL_ID, NAME,

    **IF** (SEX_UPON_INTAKE **LIKE** "%Neutered%" **OR**
    SEX_UPON_INTAKE **LIKE** "%Spayed%" , "O" , "X") AS "중성화"

  **FROM** ANIMAL_INS **ORDER** **BY** ANIMAL_ID

  <case 버전>

  **SELECT** ANIMAL_ID, NAME,

    **CASE** **WHEN** (SEX_UPON_INTAKE **LIKE** "%Neutered%" **OR** 
    SEX_UPON_INTAKE **LIKE** "%Spayed%")
    **THEN** "O" **ELSE** "X"
    **END**
    **AS** "중성화"

  **FROM** ANIMAL_INS **ORDER** **BY** ANIMAL_ID

- ❗️**오랜기간 보호한 동물(2)**

  **SELECT** OUTS.ANIMAL_ID, OUTS.NAME
  **FROM** ANIMAL_INS INS

    **LEFT** **JOIN** ANIMAL_OUTS OUTS
    **ON** OUTS.ANIMAL_ID**=**INS.ANIMAL_ID

  **ORDER** **BY** (OUTS.DATETIME**-**INS.DATETIME) DESC
  **LIMIT** 2

- **DATETIME에서 DATE로 형 변환**

  **SELECT** ANIMAL_ID, NAME, **DATE_FORMAT**(DATETIME,"%Y-%m-%d")  AS "날짜"
  **FROM** ANIMAL_INS
  **ORDER** **BY** ANIMAL_ID

  > Y이면 1998, y면 98

  
  
