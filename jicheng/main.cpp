#include <iostream>
#include<windows.h>
using namespace std;

//class A
//{
//public:
//    int m_a;
//private:
//    int m_b;
//public:
//    A():m_a(0),m_b(0)
//    {
//        cout<<"调用基类构造函数1"<<endl;
//    }
//    A(int a, int b):m_a(a),m_b(b)
//        {
//            cout<<"调用了基类构造函数2"<<endl;
//        }
//    A(const A& a):m_a(a.m_a+1),m_b(a.m_b+1)
//    {
//        cout<<"调用了基类拷贝构造函数"<<endl;
//    }
//    void show()
//    {
//        cout<<"m_a="<<m_a<<", m_b="<<m_b<<endl;
//    }
//};
//class B:public A
//{
//public:
//    int m_c;
//    B():m_c(0)
//    {
//        cout<<"调用了子类构造1"<<endl;
//    }
//    B(int a,int b, int c):A(a,b),m_c(c)
//    {
//        cout<<"调用了子类构造函数2"<<endl;
//    }
//    B(const A& a,int c):A(a),m_c(c)
//    {
//        cout<<"调用了子类拷贝函数"<<endl;
//    }
//    void show1()
//    {
//        cout<<"m_c="<<m_c<<endl;
//    }
//};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    B b1;
//    b1.show();
//    b1.show1();

//    B b2(1, 2, 3);      // 将调用基类有两个参数的构造函数。
//    b2.show();
//    b2.show1();

//    A a(10, 20);      // 创建基类对象。
//    B b3(a, 30);      // 将调用基类的拷贝造函数。
//    b3.show();
//    b3.show1();
//    return 0;
//}


//多态

//class Boy
//{
//public:
//    int m_age;
//    virtual void show()
//    {
//        cout<<"调用了Boy::show"<<endl;
//    }
//    virtual void show(int a)
//    {
//        cout<<"Boy::show(int)"<<endl;
//    }
//};
//class Sboy:public Boy
//{
//public:
//    int m_score;
//    void show()
//    {
//        cout<<"Sboy::show"<<endl;
//    }
//    void show(int a)
//    {
//        cout<<"Sboy::show(int a)"<<endl;
//    }
//};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);


//    Boy b1;
//    b1.m_age = 18;
//    Sboy s1;
//    s1.m_age = 20;s1.m_score =  90;

//    Boy* b;
//    b = &b1;
//    b->show();

//    b = &s1;
//    b->show();
//    b->show(5);
//    b->Boy::show(5);
//}


//析构派生类

//class AA
//{
//public:
//    AA()
//    {
//        cout<<"基类构造函数"<<endl;
//    }
//    virtual void fun() = 0;  //纯虚函数，AA抽象类
//    virtual ~AA()
//    {
//        cout<<"基类析构函数"<<endl;
//    }
//};
//class BB:public AA
//{
//public:
//    BB()
//    {
//        cout<<"子类构造函数"<<endl;
//    }
//    void fun() {cout<<"子类的fun函数"<<endl;}
//    ~BB()
//    {
//        cout<<"子类析构函数"<<endl;
//    }
//};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

// //    BB* b = new BB;
// //    delete b;
// //    AA* p = new BB;
// //    delete p;

//    BB b;
//    AA* a = &b;
//    a->fun();
//    return 0;
//}


// dynamic_cast  将基类指针转化为派生类

class Animal
{
public:
    virtual void sound()
    {
        cout<<"叫声"<<endl;
    }
};
class cat:public Animal
{
public:
    void sound()
    {
        cout<<"喵"<<endl;
    }
};
class dog:public Animal
{
public:
    void sound()
    {
        cout<<"旺"<<endl;
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int i = 0;
    cout<<"选择你想听的叫声（1.猫叫，2.狗叫）"<<endl;
    cin>>i;
    Animal* ptr = nullptr;
    if(i == 1)
    {
        ptr = new cat;
    }
    if(i == 2)
    {
        ptr = new dog;
    }


//    cat* p = dynamic_cast<cat*>(ptr);
//    if(p != nullptr)
//        p->sound();

   if(typeid (cat) == typeid(*ptr))     //typeid运算符的使用
   {
       cat* p = dynamic_cast<cat*>(ptr);
       if(p != nullptr)
           p->sound();
   }

    return 0;
}
