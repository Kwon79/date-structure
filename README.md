# 분수 추상 자료형 (Fraction ADT)

## 개요
정수형 분자(numerator)와 분모(denominator)로 이루어진 분수를 표현하는 추상 자료형이다.
하나의 `int` 값에 **상위 16비트는 분자**, **하위 16비트는 분모**를 저장하는 비트 패킹 방식으로 구현된다.
분수, 정수, 소수 형태의 입력을 모두 지원하며, 음수 분수도 지원한다.

---

## 데이터 구조

```
my_fraction = int

[ 31 ........... 16 | 15 ........... 0 ]
     분자(numerator)     분모(denominator)
```

- 분모는 항상 양수로 유지되며, 음수는 분자에만 저장된다.
- 분자 추출 시 `(short)(f >> 16)` 으로 캐스팅하여 음수 부호를 유지한다.

---

## 연산 목록

### 1. 분수 생성
```c
my_fraction create(int numerator, int denominator)
```
- **입력**: 분자(numerator), 분모(denominator) — 정수
- **출력**: my_fraction 자료형
- **설명**: 분모가 음수인 경우 부호를 뒤집어 분모를 양수로 유지한다. 분자를 상위 16비트, 분모를 하위 16비트에 저장하여 하나의 int로 반환한다.

---

### 2. 문자열 → 분수 변환
```c
my_fraction parse(char* str)
```
- **입력**: 문자열 (분수: `"A/B"`, 정수: `"A"`, 소수: `"0.A"`)
- **출력**: my_fraction 자료형
- **설명**: 입력 문자열의 형태를 판별하여 분수 자료형으로 변환한다.
  - `/` 포함 → 분수 형태로 파싱
  - `.` 포함 → 소수를 분수로 변환 (소수점 자릿수만큼 10^n을 분모로 사용)
  - 둘 다 없음 → 정수로 파싱, 분모를 1로 설정

---

### 3. 최대공약수 계산
```c
int find_gcd(int a, int b)
```
- **입력**: 정수 두 개 (a, b)
- **출력**: 두 정수의 최대공약수 (int)
- **설명**: 유클리드 호제법을 사용하여 GCD를 계산한다. `reduce()` 내부에서 사용된다.

---

### 4. 기약분수 변환
```c
my_fraction reduce(my_fraction f)
```
- **입력**: 분수 하나 (my_fraction)
- **출력**: 기약분수로 변환된 분수 (my_fraction)
- **설명**: 분자와 분모를 최대공약수(GCD)로 나누어 기약분수로 반환한다.

---

### 5. 덧셈
```c
my_fraction add(my_fraction i, my_fraction j)
```
- **입력**: 분수 두 개 (my_fraction)
- **출력**: 두 분수의 합 (my_fraction)
- **설명**: 분모가 같으면 분자끼리 더하고, 다르면 통분 후 계산한다.
  `a/b + c/d = (ad + bc) / bd`

---

### 6. 뺄셈
```c
my_fraction minus(my_fraction i, my_fraction j)
```
- **입력**: 분수 두 개 (my_fraction)
- **출력**: 두 분수의 차 (my_fraction)
- **설명**: 분모가 같으면 분자끼리 빼고, 다르면 통분 후 계산한다.
  `a/b - c/d = (ad - bc) / bd`

---

### 7. 곱셈
```c
my_fraction mult(my_fraction i, my_fraction j)
```
- **입력**: 분수 두 개 (my_fraction)
- **출력**: 두 분수의 곱 (my_fraction)
- **설명**: 분자끼리, 분모끼리 곱한다.
  `a/b × c/d = ac / bd`

---

### 8. 나눗셈
```c
my_fraction divid(my_fraction i, my_fraction j)
```
- **입력**: 분수 두 개 (my_fraction)
- **출력**: 두 분수의 몫 (my_fraction)
- **설명**: 두 번째 분수의 역수를 곱한다.
  `a/b ÷ c/d = ad / bc`

---

### 9. 분수 출력
```c
void print(my_fraction f)
```
- **입력**: 분수 하나 (my_fraction)
- **출력**: 없음 (표준 출력)
- **설명**: 분수를 A/B 꼴로 출력한다. 분모가 1인 경우 정수로 출력한다.

---

## 실행 흐름

```
입력: 0.5 + 2/4
        ↓
parse("0.5") → create(5, 10)
parse("2/4") → create(2, 4)
        ↓
add() → 18/40
        ↓
reduce() → 9/20
        ↓
print() → 출력: 9/20
```

---

## 입출력 예시
<img width="2170" height="332" alt="image" src="https://github.com/user-attachments/assets/c7aae6dc-131e-4d7a-a5cb-1f7dbc2c2380" />
<img width="2330" height="384" alt="image" src="https://github.com/user-attachments/assets/3742e7e9-56fd-4cca-882e-c99a571ee587" />
<img width="2318" height="436" alt="image" src="https://github.com/user-attachments/assets/0929fa32-8d5c-4d2a-9297-de309e3e1db5" />
<img width="2130" height="386" alt="image" src="https://github.com/user-attachments/assets/bf302c71-225b-4a10-9b59-1cdf58ace5d2" />

---

## 파일 구조

```
├── my_fraction.h   # 분수 자료형 및 함수 선언
├── my_fraction.c   # 분수 연산 함수 구현
└── operation.c     # main 함수 (입력 처리 및 연산 실행)
```

