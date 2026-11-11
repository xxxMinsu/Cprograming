
/*
    ****************************************
    제   목  :  실습과제1
    학   번  :  2600093
    작성자  :  서민수
    날   짜  :  2026-11-11
    ****************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct person {
    char name[10];
    char account[50];
    int num;
} Person;

Person get_data(void);
void put_data(Person data);

int main() {
    Person data;
    data = get_data();
    put_data(data);

    return 0;
}

Person get_data(void) {
    Person data;

    printf("학번 입력:");
    scanf("%d", &data.num);

    printf("이름 입력:");
    scanf("%9s", data.name);

    printf("주소 입력:");
    scanf("%49s", data.account);

    return data;
}

void put_data(Person data) {
    printf("%s %d %s", data.name, data.num, data.account);
}

/*
    ****************************************
    제   목  :  실습과제2
    학   번  :  2600093
    작성자  :  서민수
    날   짜  :  2026-11-11
    ****************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[10];
    int grade;
} Student;

void get_data(Student* plist);
Student get_best(Student* plist);

int main() {
    Student list[3];
    Student best;

    get_data(list);
    best = get_best(list);

    printf("%s %d", best.name, best.grade);

    return 0;
}

void get_data(Student* plist) {
    for (int i = 0; i < 3; i++) {
        printf("이름입력:");
        scanf("%9s", plist[i].name);

        printf("성적 입력:");
        scanf("%d", &plist[i].grade);
    }
}

Student get_best(Student* plist) {
    Student best;

    best.grade = plist[0].grade;
    strcpy(best.name, plist[0].name);

    for (int i = 0; i < 3; i++) {
        if (best.grade < plist[i].grade) {
            best.grade = plist[i].grade;
            strcpy(best.name, plist[i].name);
        }
    }

    return best;
}

/*
    ****************************************
    제   목  :  실습과제3
    학   번  :  2600093
    작성자  :  서민수
    날   짜  :  2026-11-11
    ****************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[10];
    int grade;
} Student;

void get_data(Student* plist);
Student get_first(Student* plist);

int main() {
    Student list[3];
    Student first;

    get_data(list);
    first = get_first(list);

    printf("%s %d", first.name, first.grade);

    return 0;
}

void get_data(Student* plist) {
    for (int i = 0; i < 3; i++) {
        printf("이름입력:");
        scanf("%9s", plist[i].name);

        printf("성적 입력:");
        scanf("%d", &plist[i].grade);
    }
}

Student get_first(Student* plist) {
    Student first;

    first.grade = plist[0].grade;
    strcpy(first.name, plist[0].name);

    for (int i = 0; i < 3; i++) {
        if (strcmp(first.name, plist[i].name) > 0) {
            first.grade = plist[i].grade;
            strcpy(first.name, plist[i].name);
        }
    }

    return first;
}

/*
    ****************************************
    제   목  :  실습과제4
    학   번  :  2600093
    작성자  :  서민수
    날   짜  :  2026-11-11
    ****************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct point {
    int xpos;
    int ypos;
} Point;

void swap_struct(Point* pos1, Point* pos2);

int main() {
    Point pos1 = { 1,2 };
    Point pos2 = { 3,4 };

    printf("pos1:[%d, %d], pos2:[%d, %d]\n",
        pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

    swap_struct(&pos1, &pos2);

    printf("pos1:[%d, %d], pos2:[%d, %d]\n",
        pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

    return 0;
}

void swap_struct(Point* pos1, Point* pos2) {
    Point temp;

    temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}

/*
    ****************************************
    제   목  :  실습과제5
    학   번  :  2600093
    작성자  :  서민수
    날   짜  :  2026-11-11
    ****************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct point {
    int xpos;
    int ypos;
} Point;

void SwapPoint(Point* pos1, Point* pos2);

int main() {
    Point pos1 = { 2,4 };
    Point pos2 = { 5,7 };

    printf("pos1:[%d, %d], pos2:[%d, %d]\n",
        pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

    SwapPoint(&pos1, &pos2);

    printf("pos1:[%d, %d], pos2:[%d, %d]\n",
        pos1.xpos, pos1.ypos, pos2.xpos, pos2.ypos);

    return 0;
}

void SwapPoint(Point* pos1, Point* pos2) {
    Point temp;

    temp = *pos1;
    *pos1 = *pos2;
    *pos2 = temp;
}
