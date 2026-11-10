
# C언어 구조체 오답노트

## 1. 구조체 문자열 입력 시 & 사용

### 틀린 코드
```c
scanf("%s", &data.name);
```

### 올바른 코드
```c
scanf("%s", data.name);
```

### 이유
- `data.name`은 문자 배열이다.
- 배열의 이름 자체가 배열의 시작 주소를 의미한다.
- 따라서 문자열 입력 시 `&`를 붙일 필요가 없다.

### 기억할 점
```c
scanf("%d", &data.grade);  // 정수형: & 필요
scanf("%s", data.name);    // 문자 배열: & 불필요
```

---

## 2. 구조체 반환과 문자열 복사 혼동

### 틀린 코드
```c
strcpy(first.name, get_first(list));
```

### 올바른 코드
```c
first = get_first(list);
```

### 이유
- `get_first()`의 반환형은 `Student`이다.
- 즉, 문자열이 아니라 구조체 전체를 반환한다.
- `strcpy()`는 문자열을 복사하는 함수이므로 구조체 전체를 전달할 수 없다.
- 구조체 전체를 대입할 때는 `=`을 사용한다.

### 기억할 점
```c
first = get_first(list);          // 구조체 전체 대입
strcpy(first.name, list[0].name); // 문자열 복사
```

---

## 3. 문자열 비교에 비교 연산자 사용

### 틀린 코드
```c
if (first.name > plist[i].name)
```

### 올바른 코드
```c
if (strcmp(first.name, plist[i].name) > 0)
```

### 이유
- 문자열은 `>`, `<`, `==` 연산자로 내용을 비교하면 안 된다.
- 문자열 비교에는 `strcmp()` 함수를 사용한다.

### strcmp() 반환값

| 반환값 | 의미 |
|---|---|
| 양수 | 첫 번째 문자열이 사전순으로 뒤에 있음 |
| 0 | 두 문자열이 같음 |
| 음수 | 첫 번째 문자열이 사전순으로 앞에 있음 |

### 기억할 점
```c
strcmp(a, b) > 0   // a가 b보다 뒤
strcmp(a, b) < 0   // a가 b보다 앞
strcmp(a, b) == 0  // a와 b가 같음
```

---

## 4. strcmp() 괄호 위치 오류

### 틀린 코드
```c
if (strcmp(first.name, plist[i].name > 0))
```

### 올바른 코드
```c
if (strcmp(first.name, plist[i].name) > 0)
```

### 이유
- `strcmp()` 함수에는 비교할 문자열 두 개가 들어간다.
- `> 0`은 함수가 반환한 결과를 비교하는 조건이다.
- 따라서 `> 0`은 함수의 괄호 바깥에 작성해야 한다.

### 기억할 점
```c
if (함수(인자1, 인자2) 비교연산자 값)
```

괄호 위치에 주의하자.

---

## 5. return 위치 오류

### 틀린 코드
```c
for (int i = 0; i < 3; i++) {
    if (strcmp(first.name, plist[i].name) > 0) {
        strcpy(first.name, plist[i].name);
    }
    return first;
}
```

### 올바른 코드
```c
for (int i = 0; i < 3; i++) {
    if (strcmp(first.name, plist[i].name) > 0) {
        strcpy(first.name, plist[i].name);
    }
}
return first;
```

### 이유
- `return`을 반복문 안에 작성하면 첫 번째 반복이 끝난 직후 함수가 종료된다.
- 모든 학생의 이름을 비교하려면 반복문이 끝난 다음 반환해야 한다.

### 기억할 점
- 반복문 안의 `return`: 반복 중 함수 종료
- 반복문 밖의 `return`: 반복을 모두 마친 뒤 함수 종료

---

## 6. 함수 원형과 함수 정의 불일치

### 틀린 코드
```c
Person get_data(Person data);
```

```c
Person get_data() {
    Person data;
    return data;
}
```

### 올바른 코드
```c
Person get_data(void);
```

```c
Person get_data(void) {
    Person data;
    return data;
}
```

### 이유
- 함수 원형과 함수 정의의 매개변수 형태가 일치하지 않았다.
- `void`는 매개변수가 없다는 것을 명확하게 나타낸다.

### 기억할 점
```c
int sum(int a, int b);  // 함수 원형
sum(10, 20);            // 함수 호출
int sum(int a, int b)   // 함수 정의
```

함수 원형, 함수 호출, 함수 정의를 구분하자.

---

## 7. 문자열 입력 크기 초과

### 주의할 코드
```c
scanf("%s", data.name);
```

### 권장 코드
```c
scanf("%9s", data.name);
```

### 이유
```c
char name[10];
```

- 문자 배열의 크기가 10이라면 실제 문자는 최대 9개까지 저장할 수 있다.
- 마지막 한 칸은 문자열 종료 문자 `'\0'`이 차지한다.
- `%s`는 입력 길이에 제한이 없어 배열의 크기를 초과할 수 있다.
- `%9s`는 최대 9개의 문자만 입력받는다.

---

# 핵심 개념 암기표

| 개념 | 기억해야 할 코드 |
|---|---|
| 정수 입력 | `scanf("%d", &a);` |
| 문자열 입력 | `scanf("%s", a);` |
| 문자열 복사 | `strcpy(a, b);` |
| 문자열 비교 | `strcmp(a, b);` |
| 구조체 대입 | `a = b;` |
| 구조체 반환 | `return data;` |
| 구조체 포인터 접근 | `plist[i].grade` |
| 함수 매개변수 없음 | `get_data(void)` |
| 문자열 길이 제한 | `scanf("%9s", a);` |

---

# 최종 복습 사항

1. 문자 배열의 이름은 배열의 시작 주소를 의미한다.
2. 구조체 전체를 대입할 때는 `=`을 사용한다.
3. 문자열을 복사할 때는 `strcpy()`를 사용한다.
4. 문자열을 비교할 때는 `strcmp()`를 사용한다.
5. `strcmp()`의 반환값과 비교 연산자의 위치를 구분한다.
6. 반복문이 모두 실행된 후 반환하려면 `return`을 반복문 밖에 작성한다.
7. 함수 원형과 함수 정의의 매개변수를 일치시킨다.
8. 문자 배열의 크기를 고려하여 문자열 입력 길이를 제한한다.

**중점 복습:** `strcmp()`, `strcpy()`, 구조체 반환의 차이를 확실하게 이해하자.
