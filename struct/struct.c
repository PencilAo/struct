#define _CRT_SECURE_NO_WARNINGS
// �ṹ���������
// error 
struct Node
{
    int data;
    struct Node next; //������������ޣ�next���и�(data),(next next)�����������ʽ����
};
int main()
{

    return 0;
}


struct NOde
{
    int data;
    struct Node* next; //���ҵ�ͬ���͵Ľڵ㣬��ŵ�ַ
};


typedef struct Node
{
    int data;
    struct Node* next;
}Node;                         //������������  struct Node n1 == Node n1

//1
typedef struct Node
{
    int data;
    struct Node* next;
}* linklist;

// �ȼ���

//2
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node* linklist;



�ṹ������Ķ���ͳ�ʼ��

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
