#include <iostream>
#include<windows.h>

using namespace std;


//重载运算符
//class student
//{
//    friend student& operator+(student &s,int score);
//    friend bool operator==(const student& s, int score);
//    friend int main();
//public:
//    int m_age;
//    string m_name;
//    student()
//    {
//        m_age = 18;
//        m_name = "haodong";
//        m_score = 60;
//    }

//    student(string name, int score)
//    {
//        m_name = name;
//        m_score  = score;
//    }

//    void print()
//    {
//        cout<<"name:"<<m_name<<", score:"<<m_score<<endl;
//    }
//    student &operator-(int score)
//    {
//        m_score = m_score - score;
//        return *this;
//    }
//    bool operator<(const student &s1)
//    {
//        if(m_score <s1.m_score)
//            return true;
//        else
//            return false;
//    }
//private:
//    int m_score;
//};

//student& operator+(student &s,int score)
//{
//    s.m_score = s.m_score + score;
//    return s;
//}


//bool operator==(const student& s, int score)
//{
//    if(s.m_score == score)
//        return true;
//    else
//        return false;
//}

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

////    student s;
////    s = s+30;
////    s.print();
////    s = s -20;
////    s.print();

//    student s("zhangsan",79),s1("lisi",80);
//    if(s.m_score == s1.m_score)
//    {
//        cout<<"s和s1同样优秀"<<endl;
//    }
//    if(s < s1)
//    {
//        cout<<"s1更优秀"<<endl;
//    }
//    return 0;
//}


//重载[]

//class stude
//{
//public:
//    string m_name;
//    int m_score[3];
//    stude()
//    {
//        m_score[0] = 87;
//        m_score[1] = 89;
//        m_score[2] = 91;
//    }
//    int &operator[](int i)
//    {
//        return m_score[i];
//    }
//};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    stude s;
//    cout<<"第一科成绩："<<s.m_score[0]<<endl;
//    return 0;
//}


//重载new delete
//void* operator new(size_t size)
//{
//    cout<<"调用了全局重载函数new"<<endl;
//    void* p = malloc(size);
//    cout<<"分配的内存"<<p<<endl;
//    return p;
//}
//void operator delete(void* p)
//{
//    cout<<"调用了全局重载delete"<<endl;
//    if(p == 0)
//        return;
//    free(p);
//}

//class Boy
//{
//public:
//    int m_age;
//    int m_score;
//    Boy(int age, int score)
//    {
//        m_age = age;
//        m_score = score;
//    }
//    ~Boy()
//    {
//        cout<<"调用了析构函数"<<endl;
//    }
//    void* operator new(size_t size)
//    {
//        cout<<"调用了类重载函数new"<<endl;
//        void* p = malloc(size);
//        cout<<"分配的内存"<<p<<endl;
//        return p;
//    }
//    void operator delete(void* p)
//    {
//        cout<<"调用了雷重载delete"<<endl;
//        if(p == 0)
//            return;
//        free(p);
//    }
//};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    int* i = new int(3);
//    cout<<*i<<endl;
//    delete i;

//    Boy* b = new Boy(18,80);
//    cout<<"b的年龄是："<<b->m_age<<", b的成绩是："<<b->m_score<<endl;
//    delete b;
//    return 0;
//}


//重载一元运算符

class Boy
{
public:
    string m_name;
    int m_age;
    Boy()
    {
        m_name = "xiaoming";
        m_age = 18;
    }
    ~Boy()
    {
        cout<<"析构"<<endl;
    }
    Boy& operator++()       //前置++
    {
        m_age++;
        return *this;
    }
    Boy operator++(int)     //后置
    {
        Boy tmp = *this;
        m_age++;
        return tmp;
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Boy b1,b2;
    Boy x = ++b1;
    cout<<b1.m_age<<endl;
    Boy y = b2++;
    cout<<b2.m_age<<endl;
    return 0;
}
