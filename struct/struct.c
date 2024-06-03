#define _CRT_SECURE_NO_WARNINGS
// 结构体的自引用
// error 
struct Node
{
    int data;
    struct Node next; //这里会无限套娃，next里有个(data),(next next)，所以这个方式不对
};
int main()
{

    return 0;
}


struct NOde
{
    int data;
    struct Node* next; //能找到同类型的节点，存放地址
};


typedef struct Node
{
    int data;
    struct Node* next;
}Node;                         //这样重命名后  struct Node n1 == Node n1

//1
typedef struct Node
{
    int data;
    struct Node* next;
}* linklist;

// 等价于

//2
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node* linklist;



结构体变量的定义和初始化

struct Point
{
    int x;
    int y;
}p1 = {2,3};


struct score
{
    int n;
    char ch;
};
struct stu
{
    char name[20];
    int age;
    struct score s;
};
int main()
{
    struct Point p2 = { 4,6 };
    struct stu s1 = { "lisi",20,{29,'o'} };
    printf("%s %d %d %c", s1.name, s1.age, s1.s.n, s1.s.ch);
}
                       结构体内存对齐
     结构体在内存中的储存方式
  1. 结构体的第⼀个成员对⻬到和结构体变量起始位置偏移量为0的地址处
  2.其他成员变量要对⻬到某个数字（对⻬数）的整数倍的地址处。
  对⻬数 = 编译器默认的⼀个对⻬数 与 该成员变量⼤⼩的较⼩值。
  其中vs的的默认对齐数是8       可以用通过 #pragma pack(8) 修改默认对齐数//设置默认对齐数为8
  3.结构体总⼤⼩为最⼤对⻬数（结构体中每个成员变量都有⼀个对⻬数，所有对⻬数中最⼤的)的整数倍。
  4.如果嵌套了结构体的情况，嵌套的结构体成员对⻬到⾃⼰的成员中最⼤对⻬数的整数倍处，结构体的整体⼤⼩就是所有最⼤对⻬数（含嵌套结构体中成员的对⻬数）的整数倍。
#include <stddef.h>
struct S1
{
    char c1;
    int i;
    char c2;
};
struct S2
{
    char c1;
    char c2;
    int i;
};
struct S3
{
    double c;
    char c2;
    int i;
};
struct S4
{
    char c1;
    struct S3 s;
    double d;
};
int main()
{
    printf("%d\n", sizeof(struct S1));    //12

    printf("%d\n", offsetof(struct S1, c1));   //0    //要引用头文件  可以算出结构体成员在内存中的偏移量
    printf("%d\n", offsetof(struct S1, i));    //4
    printf("%d\n", offsetof(struct S1, c2));   //8


    printf("%d\n", sizeof(struct S2));    //8


    printf("%d\n", sizeof(struct S3));    //16

    printf("%d\n", sizeof(struct S4));    //32
    return 0;
}



 #pragma once
 在头文件中使用，功能是：防止头文件被多次引用



#pragma pack(4)
struct S
{
    int i;
    double d;
}; //12
#pragma pack()   // 恢复到默认值

#pragma pack(1)
struct S1
{
    char c1;
    int i;
    char c2;
};  // 6
#pragma pack()
int main()
{ 
    printf("%d\n", sizeof(struct S)); //12  因为将默认对齐数修改了
    return 0;
}



