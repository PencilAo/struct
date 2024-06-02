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
