# SQL

## SELECT

### 문자열 역순 정렬  - DESC

---

**SELECT** NAME, DATETIME **FROM** ANIMAL_INS **ORDER BY** ANIMAL_ID **DESC**;

**SELECT** ANIMAL_ID, NAME, DATETIME **FROM** ANIMAL_INS **ORDER** **BY** NAME (**ASC)**, DATETIME **DESC**;

> 정렬 2개일 때



### 조건 - WHERE

---

**SELECT** ANIMAL_ID, NAME **FROM** ANIMAL_INS **WHERE** INTAKE_CONDITION="Sick" **ORDER** **BY** ANIMAL_ID;

> id 순이라고 해서 (기본 ASC)

**SELECT** ANIMAL_ID, NAME **FROM** ANIMAL_INS **WHERE** **NOT** INTAKE_CONDITION="Aged" **ORDER** **BY** ANIMAL_ID;

### 상위 1개 뽑기(MAX, LIMIT)

---

**SELECT** NAME **FROM** ANIMAL_INS **ORDER** **BY** DATETIME **LIMIT** 1;

> (비교기준이 select에 없을때)

**SELECT** DATETIME **AS** "시간" **FROM** ANIMAL_INS **ORDER** **BY** DATETIME DESC **LIMIT** 1;

**SELECT** **MAX**(DATETIME) FROM ANIMAL_INS ;

>(비교기준이 select에 있을 때 = **둘다가능**)

**SELECT** **MIN**(DATETIME) AS "시간" **FROM** ANIMAL_INS;

### 갯수세기

---

**SELECT** **COUNT**(ANIMAL_ID) **AS** 'count' **FROM** ANIMAL_INS;

> 문자 쓸 때는 “” ‘’ 상관없음
> 

**SELECT** **COUNT**(**DISTINCT** NAME) AS "count" FROM ANIMAL_INS **WHERE** NAME **IS NOT NULL** ;

> DISTINCT 는 열 이름 바로 앞에!
> 
> 
> IS NOT NULL은 WHERE 절에
> - null 이 있는 열에 WHERE 조건 넣어주기
> 

### GROUP BY

---

**SELECT** ANIMAL_TYPE, **COUNT**(ANIMAL_TYPE) **AS** "count" **FROM** ANIMAL_INS **GROUP** **BY** ANIMAL_TYPE **ORDER** **BY** ANIMAL_TYPE;

*나온 조건들 명시하기 (이미 오름차순이어도 order by 조건 넣어주기)

### +HAVING (GROUP BY 에 조건 붙일 때!)

---

**SELECT** NAME, **COUNT**(NAME) **AS** "COUNT" **FROM** ANIMAL_INS **GROUP** **BY** NAME **HAVING** COUNT(NAME) >1 **ORDER** **BY** NAME;

> ≥2 나 >1 이나 같음
>
