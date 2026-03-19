# 분수 추상 자료형 (Fraction ADT)

## 개요
정수형 분자(numerator)와 분모(denominator)로 이루어진 분수를 표현하는 추상 자료형이다.  
하나의 `unsigned int` 값에 **상위 16비트는 분자**, **하위 16비트는 분모**를 저장하는 비트 패킹 방식으로 구현된다.

---

## 데이터 구조

```
my_fraction = unsigned int

[ 31 ........... 16 | 15 ........... 0 ]
     분자(numerator)     분모(denominator)
```

---

## 연산 목록

### 1. 분수 생성
```c
my_fraction create(int numerator, int denominator)
```
- **입력**: 분자(numerator), 분모(denominator) — 정수
- **출력**: my_fraction 자료형
- **설명**: 분자를 상위 16비트, 분모를 하위 16비트에 저장하여 하나의 unsigned int로 반환한다.

---

### 2. 최대공약수 계산
```c
int find_gcd(int a, int b)
```
- **입력**: 정수 두 개 (a, b)
- **출력**: 두 정수의 최대공약수 (int)
- **설명**: 유클리드 호제법을 사용하여 최대공약수를 계산한다. `reduce()` 및 `print()` 내부에서 사용된다.

---

### 3. 기약분수 변환
```c
my_fraction reduce(my_fraction f)
```
- **입력**: 분수 하나 (my_fraction)
- **출력**: 기약분수로 변환된 분수 (my_fraction)
- **설명**: 분자와 분모를 최대공약수(GCD)로 나누어 기약분수로 반환한다.

---

### 4. 덧셈
```c
my_fraction add(my_fraction i, my_fraction j)
```
- **입력**: 분수 두 개 (my_fraction)
- **출력**: 두 분수의 합 (my_fraction)
- **설명**: 분모가 같으면 분자끼리 더하고, 다르면 통분 후 계산한다.  
  `a/b + c/d = (ad + bc) / bd`

---

### 5. 뺄셈
```c
my_fraction minus(my_fraction i, my_fraction j)
```
- **입력**: 분수 두 개 (my_fraction)
- **출력**: 두 분수의 차 (my_fraction)
- **설명**: 분모가 같으면 분자끼리 빼고, 다르면 통분 후 계산한다.  
  `a/b - c/d = (ad - bc) / bd`

---

### 6. 곱셈
```c
my_fraction mult(my_fraction i, my_fraction j)
```
- **입력**: 분수 두 개 (my_fraction)
- **출력**: 두 분수의 곱 (my_fraction)
- **설명**: 분자끼리, 분모끼리 곱한다.  
  `a/b × c/d = ac / bd`

---

### 7. 나눗셈
```c
my_fraction divid(my_fraction i, my_fraction j)
```
- **입력**: 분수 두 개 (my_fraction)
- **출력**: 두 분수의 몫 (my_fraction)
- **설명**: 두 번째 분수의 역수를 곱한다.  
  `a/b ÷ c/d = ad / bc`

---

### 8. 분수 출력
```c
void print(my_fraction f)
```
- **입력**: 분수 하나 (my_fraction)
- **출력**: 없음 (표준 출력)
- **설명**: 분수를 기약분수로 변환 후 `A/B` 꼴로 표준 출력한다.

---

## 실행 흐름

```
입력: 2/5 + 2/4
        ↓
create(2,5), create(2,4)  →  분수 생성
        ↓
add()  →  18/20
        ↓
reduce()  →  9/10
        ↓
print()  →  출력: 9/10
```

---

## 입출력 예시

| 입력 | 출력 |
|------|------|
| 2/5 + 2/4 | 9/10 |
| 1/2 - 1/4 | 1/4 |
| 2/3 * 3/4 | 1/2 |
| 3/4 / 1/2 | 3/2 |

---

## 파일 구조

```
├── my_fraction.h   # 분수 자료형 및 함수 선언
├── my_fraction.c   # 분수 연산 함수 구현
└── operation.c     # main 함수 (입력 처리 및 연산 실행)
```

