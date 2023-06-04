#include <iostream>
#include<windows.h>

using namespace std;

//int main()
//{
//   SetConsoleOutputCP(CP_UTF8);

//   int a = 618;
//   int &aa = a;
//   cout<<"a的地址:"<<&a<<"a的值:"<<a<<endl;
//   cout<<"aa的地址："<<&aa<<"aa的值："<<aa<<endl;

//   aa = 710;
//   cout<<"a的地址:"<<&a<<"a的值:"<<a<<endl;
//   cout<<"aa的地址："<<&aa<<"aa的值："<<aa<<endl;
//    return 0;
//}
//引用本质上跟指针没有区别。


//引用用于函数参数

//void fun(int &age, string &name)
//{
//    cout<<"age:"<<age<<"name:"<<name<<endl;
//    age = 18;
//    name = "haodong";
//    cout<<"age:"<<age<<"name:"<<name<<endl;
//}
//int main ()
//{
//    int age = 23;
//    string name = "sunhaosong";

//    fun(age, name);
//    return 0;
//}


//struct info
//{
//    int age;
//    string name;
//};

//void fun (struct info &no1)
//{
//    cout<<"age:"<<no1.age<<"name:"<<no1.name<<endl;
//}
//int main()
//{
//    struct info no1 = {23,"haodong"};
//    fun(no1);

//    return 0;
//}


//引用的形参和const
//如果函数的实参不是左值或与const引用形参的类型不匹配，那么C++将创建正确类型的匿名变量，将实参的值传递给匿名变量，并让形参来引用该变量。
//void fun(const int &age,const string &name )
//{
//    cout<<"age:"<<age<<"name:"<<name<<endl;
//}
//int main()
//{
//    int age = 18;
//    string name = "haodong";
//    fun('h',name);
//    fun(18, "haodong");
//    return 0;
//}

//引用用于函数的返回值
const int &fun(int &ra)
{
    ra++;
    return ra;
}
int main()
{
     SetConsoleOutputCP(CP_UTF8);

    int a = 2;
    const int& b= fun(a);
    cout<<"a的地址 "<<&a<<", a="<<a<<endl;
    cout<<"b的地址 "<<&b<<", b="<<b<<endl;
    return 0;
}
