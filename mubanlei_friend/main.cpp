#include <iostream>
#include<windows.h>
using namespace std;

//非模板友元

//template <class T1,class T2>
//class AA
//{
//    T1 m_a;
//    T2 m_b;
//public:
//    AA(const T1 a,const T2 b):m_a(a),m_b(b){}
//    friend void show(AA<T1,T2>& a)          //不是模板函数，只能类内实现，不能具体化
//    {
//        cout<<"a="<<a.m_a<<", b="<<a.m_b<<endl;
//    }

//    //friend void show(AA<int, string>& a);
//};
// //void show(AA<int, string>& a)
// //{
// //    cout<<"a="<<a.m_a<<", b="<<a.m_b<<endl;
// //}
//int main()
//{
//    AA<int, string>a(18,"dong");
//    show(a);
//    return 0;
//}


//约束模板友元

//template <typename T>
//void show(T& a);

//template <class T1,class T2>
//class AA
//{
//    friend void show<>(AA<T1,T2>& a);
//    T1 m_a;
//    T2 m_b;
//public:
//    AA(const T1 a,const T2 b):m_a(a),m_b(b){}
//};

//template <class T1,class T2>
//class BB
//{
//    friend void show<>(BB<T1,T2>& a);
//    T1 m_a;
//    T2 m_b;
//public:
//    BB(const T1 a,const T2 b):m_a(a),m_b(b){}
//};

//template <typename T>
//void show(T &a)
//{
//    cout<<"模板:a="<<a.m_a<<", b="<<a.m_b<<endl;
//}
//template <>
//void show(AA<int, string>& a)
//{
//    cout<<"具体:a="<<a.m_a<<", b="<<a.m_b<<endl;
//}

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    AA<int, string> a(18,"dong");
//    show(a);

//    AA<char,string> a1(18,"dong");
//    show(a1);

//    BB<int, string> b(23,"dong");
//    show(b);
//}

// 非类模板约束的友元函数，实例化后，每个函数都是每个每个类的友元。

template <class T1,class T2>
class AA
{
     template <typename T> friend void show(T &a);
    T1 m_a;
    T2 m_b;
public:
    AA(const T1 a,const T2 b):m_a(a),m_b(b){}

};
template <typename T> void show(T& a)                     // 通用的函数模板。
{
    cout << "通用：x = " << a.m_a << ", y = " << a.m_b << endl;
}

template <>void show(AA<int, string>& a)                 // 函数模板的具体版本。
{
    cout << "具体：x = " << a.m_a << ", y = " << a.m_b << endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    AA<int, string> a(88, "dong");
    show(a);

    AA<char, string> b(88, "dong");
    show(b);
}
