#include <iostream>
#include<windows.h>
using namespace std;


//template <typename T>
//void Swap(T &a,T &b)
//{
//    T tmp;
//    tmp = a;
//    a = b;
//    b = tmp;
//}
//int main()
//{
//   int a = 18;
//   int b = 23;
//   Swap(a,b);
//   cout<<"a="<<a<<",b="<<b<<endl;
//    return 0;
//}



//为类的成员函数创建函数模板
//class A
//{
//public:
//    template<typename T>
//    A(T a)
//    {
//        cout<<"a="<<a<<endl;
//    }
//    template<typename T>
//    void print(T b)
//    {
//        cout<<"b="<<b<<endl;
//    }
//};

//int main()
//{
//    A a(3);
//    A a1("dong");
//    a.print(5);
//}


//使用函数模板时，如果是自动类型推导，不会发生隐式类型转换，如果显式指定了函数模板的数据类型，可以发生隐式类型转换。
//template<typename T>
//T add(T a,T b)
//{
//    return a+b;
//}
//int main()
//{
// //    int a = 18;
// //    int b = 23;
// //    cout<<"add="<<add(a,b)<<endl;

//    int a = 18;
//    char b = 23;
//    cout<<"add="<<add<int>(a,b)<<endl;
//    return 0;
//}





//支持多个通用数据类型
//template<typename T1,typename T2>
//void print(T1 no,T2 name)
//{
//    cout<<"编号："<<no<<", name"<<name<<endl;
//}
//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    int i = 6;
//    string name = "dong";
//    print(i,name);
//}
//支持重载


//函数模板具体化
//优先级：普通函数>具体化函数模板>函数模板
void Swap(int &a, int &b)    //普通函数

{
    int tmp = a;
    a = b;
    b = tmp;
    cout<<"普通函数"<<endl;
}

template <typename T>    //函数模板
void Swap(T &a,T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
    cout<<"函数模板"<<endl;
}

template <>
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    cout<<"模板具体化函数"<<endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int a=18;
    int b=13;
    Swap(a,b);
    cout<<"a="<<a<<", b="<<b<<endl;
    Swap<int>(a,b);
    return 0;
}
