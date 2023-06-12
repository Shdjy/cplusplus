#include <iostream>
#include<windows.h>
using namespace std;

//模板类继承普通类

//class AA
//{
//public:
//    int m_x;
//    AA(int a):m_x(a)
//    {
//        cout<<"AA的构造函数"<<endl;
//    }

//};
//template <class T1,class T2>
//class BB:public AA
//{
//public:
//    T1 m_a;
//    T2 m_b;
//    BB(int a,T1 b,T2 c):AA(a),m_a(b),m_b(c)
//    {
//        cout<<"BB的构造函数"<<endl;
//    }
//};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//   BB<int, string> bb(20,18,"dong");

//    return 0;
//}


//普通类继承模板类的实例化版本
//template <class T1,class T2>
//class AA
//{
//public:
//        T1 m_a;
//        T2 m_b;
//        AA(const T1 a,const T2 b):m_a(a),m_b(b)
//        {
//            cout<<"AA的构造函数"<<endl;
//        }
//};
//class BB:public AA<int, string>
//{
//public:
//    int m_x;
//    BB(int x,int a,string s):AA(a,s),m_x(x)
//    {
//        cout<<"BB的构造函数"<<endl;
//    }
//};
//int main()
//{
//     SetConsoleOutputCP(CP_UTF8);

//    BB bb(18,23,"dong");
//}

//普通类继承模板类

//template <class T1,class T2>
//class AA
//{
//public:
//        T1 m_a;
//        T2 m_b;
//        AA(const T1 a,const T2 b):m_a(a),m_b(b)
//        {
//            cout<<"AA的构造函数"<<endl;
//        }
//};
//template <class T1,class T2>
//class BB:public AA<T1, T2>
//{
//public:
//    int m_x;
//    BB(int x,const T1 a,const T2 s):AA<T1, T2>(a,s),m_x(x)
//    {
//        cout<<"BB的构造函数"<<endl;
//    }
//};
//int main()
//{
//     SetConsoleOutputCP(CP_UTF8);

//    BB<int, string> bb(18,23,"dong");
//}


//模板类继承模板类

//template <class T1 ,class T2>
//class AA
//{
//public:
//    T1 m_a;
//    T2 m_b;
//    AA(T1 a,T2 b):m_a(a),m_b(b)
//    {
//        cout<<"AA类构造函数"<<endl;
//    }
//};
//template <class T,class T1,class T2>
//class BB:public AA<T1,T2>
//{
//public:
//    T m_c;
//    BB(const T c,const T1 a,const T2 b):AA<T1,T2>(a,b),m_c(c)
//    {
//        cout<<"BB类的构造函数"<<endl;
//    }
//};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    BB<int, double, string> bb(18,23.5,"dong");
//}


//模板类继承模板参数给出的基类
class AA
{
public:
    int m_a;
    AA()
    {
        cout<<"调用了AA的构造函数"<<endl;
    }
    AA(int a)
    {
        cout<<"调用了AA的构造函数2"<<endl;
    }
};
class BB
{
public:
    int m_a;
    BB()
    {
        cout<<"调用了BB的构造函数"<<endl;
    }
    BB(int a)
    {
        cout<<"调用了BB的构造函数2"<<endl;
    }
};
class CC
{
public:
    int m_a;
    CC()
    {
        cout<<"调用了CC的构造函数"<<endl;
    }
    CC(int a)
    {
        cout<<"调用了CC的构造函数2"<<endl;
    }
};
template <class T>
class DD
{
public:
    int m_a;
    DD()
    {
        cout<<"调用了DD的构造函数"<<endl;
    }
    DD(int a)
    {
        cout<<"调用了DD的构造函数2"<<endl;
    }
};
template <class T>
class EE:public T
{
public:
    int m_a;
    EE():T()
    {
        cout<<"调用了EE的构造函数"<<endl;
    }
    EE(int a):T(a)
    {
        cout<<"调用了EE构造函数2"<<endl;
    }
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    EE<AA> ea1;                 // AA作为基类。
       EE<BB> eb1;                 // BB作为基类。
       EE<CC> ec1;                 // CC作为基类。
       EE<DD<int>> ed1;      // EE<int>作为基类。
}
