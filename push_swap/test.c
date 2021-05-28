#include <stdio.h>

//포인터를 동적할당해서 사용하는 방법
void fn_pointer_malloc()
{
    //변수를 생성하고 초기화 합니다.
    int i = 0;
    int max = 10;
    char *p = NULL;

    //포인터에 max의 크기로 메모리를 할당합니다.
    p = (char *)malloc(max);

    //최대 max의 크기까지 p에 값을 넣습니다.
    for (i = 0; i < max; i++)
    {
        // *(p+i) = i;
        p[i] = i;
    }

    //최대 max의 크기까지 p에 값을 화면에 출력합니다.
    for (i = 0; i < max; i++)

    {
        // printf("%d\n", *(p+i));
        printf("%d\n", p[i]);
    }

    //할당된 메모리를 해지 합니다.
    free(p);

    //해지한 메모리를 NULL로 깔끔하게 초기화 합니다.
    p = NULL;
}

//이중 포인터 배열 출력하기
void fn_array(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}

//포인터를 2중배열로 사용하는 쉬운 방법
void fn_pointer_array()
{
    //포인터 3개에 100짜리 메모리를 할당
    int number = 3; //갯수
    int address_size = sizeof(int);
    int array_size = address_size * number; //주소는 하나당 4바이트
    char **v = NULL;

    v = (char **)malloc(array_size); //메모리 생성

    //생성하고 싶은 크기 지정
    int size = 100;
    v[0] = (char *)malloc(size); //메모리 생성
    v[1] = (char *)malloc(size);
    v[2] = (char *)malloc(size);
    memset(v[0], 0x00, size); //메모리 초기화
    memset(v[1], 0x00, size);
    memset(v[2], 0x00, size);
    strcpy(v[0], "shint1"); //문자열 넣기
    strcpy(v[1], "shint2");
    strcpy(v[2], "shint3");
    fn_array(3, v); //함수에 넣기
    free(v[0]);     //메모리 해지 하기
    free(v[1]);
    free(v[2]);
    free(v);
}

//구조체 타입 선언
typedef struct DF_DATA
{
    int a; //아무거나 변수 생성
    int b; //아무거나 변수 생성
} stDATA;  //DF_DATA에 구조체 인스턴스 stDATA 생성

//포인터 구조체에 메모리를 할당해 봅시다.
void fn_pointer_struct()
{

    //구조체 인스턴스(복사본) 생성해서 사용하는 방법
    stDATA st; //구조체 인스턴스 생성
    st.a = 10; //변수 접근
    st.b = 20; //변수 접근

    //구조체 포인터를 사용하는 방법

    stDATA *pst;
    int size = sizeof(DF_DATA);
    pst = (stDATA *)malloc(size);
    pst->a = 30; //변수 접근
    pst->b = 40; //변수 접근

    //printf()에서 주소는 %x를 사용하고

    //printf()에서 int 값은 %d로 확인합니다.

    //printf()에서 %를 화면에 출력하고 싶으면. %%로 중복 사용합니다.

    //pst 에 주소를 확인하는 방법

    printf("%%x &pst      : %x\n", &pst);

    //pst 를 확인하는 방법

    printf("%%x pst       : %x\n", pst);

    //pst->a 에 주소를 확인하는 방법

    printf("%%x &pst->a   : %x\n", &pst->a);

    //데이터를 확인하는 방법

    printf("%%d pst->a    : %d\n", pst->a);

    free(pst);

    pst = NULL;
}

//포인터 구조체 배열에 메모리를 할당해 봅시다.

void fn_pointer_struct_array()

{

    //구조체 포인터를 사용하는 방법

    stDATA **ppst = NULL;

    //포인터 3개에 각각에 구조체를 메모리에 할당

    int number = 3; //갯수

    int array_size = sizeof(int) * number; //주소는 하나당 4바이트

    ppst = (stDATA **)malloc(array_size);

    int size = sizeof(DF_DATA);

    ppst[0] = (stDATA *)malloc(size);

    ppst[1] = (stDATA *)malloc(size);

    ppst[2] = (stDATA *)malloc(size);

    memset(ppst[0], 0x00, size); //메모리 초기화

    memset(ppst[1], 0x00, size);

    memset(ppst[2], 0x00, size);

    ppst[0]->a = 10; //변수 접근

    ppst[0]->b = 20; //변수 접근

    ppst[1]->a = 30; //변수 접근

    ppst[1]->b = 40; //변수 접근

    ppst[2]->a = 50; //변수 접근

    ppst[2]->b = 60; //변수 접근

    free(ppst[0]); //메모리 해지

    ppst[0] = NULL;

    free(ppst[1]); //메모리 해지

    ppst[1] = NULL;

    free(ppst[2]); //메모리 해지

    ppst[2] = NULL;

    free(ppst); //할당한 포인터 갯수만큼 메모리 해지

    ppst = NULL;
}

typedef struct DF_DATA_POINTER

{

    int a;

    DF_DATA *p;

} stDataPointer;

//구조체에서 구조체 포인터를 사용하는 방법

void fn_struct_in_use_pointer()

{

    stDataPointer st;

    st.a = 10;

    int size = sizeof(DF_DATA);

    st.p = (DF_DATA *)malloc(size);

    st.p->a = 10;

    st.p->b = 20;

    free(st.p);
}

typedef struct DF_DATA_POINTER2

{

    int a;

    DF_DATA **p;

} stDataPointer2;

//구조체에서 이중 구조체 포인터를 사용하는 방법

void fn_struct_in_use_2pointer()

{

    stDataPointer2 st;

    st.a = 10;

    int number = 2;

    int address_size = sizeof(int);

    int array_size = address_size * number; //주소는 하나당 4바이트

    st.p = (DF_DATA **)malloc(array_size);

    int size = sizeof(DF_DATA);

    st.p[0] = (DF_DATA *)malloc(size);

    st.p[0]->a = 10;

    st.p[0]->b = 20;

    st.p[1] = (DF_DATA *)malloc(size);

    st.p[1]->a = 10;

    st.p[1]->b = 20;

    free(st.p[0]);

    st.p[0] = NULL;

    free(st.p[1]);

    st.p[1] = NULL;

    free(st.p);

    st.p = NULL;
}

int main(int argc, char *argv[])

{

    fn_pointer_malloc();

    fn_pointer_array();

    fn_pointer_struct();

    fn_pointer_struct_array();

    fn_struct_in_use_2pointer();

    system("pause");

    return 0;
}