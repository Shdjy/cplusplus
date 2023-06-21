#include <iostream>
#include<windows.h>
using namespace std;

template <typename T>
void show(T name)
{
    cout<<"你好"<<name<<"同学"<<endl;
}
void print()
{
    cout<<"递归结束"<<endl;
}
template <typename T , typename ...Args>
void print(T arg, Args... args)
{
    show(arg);
    print(args...);
}
template <typename ...Args>
void func(const string& str,Args...args)
{
    cout<<str<<endl;
    print(args...);
    cout<<"over"<<endl;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    print("浩东","浩东2","haodong");
    func("欢迎欢迎","浩东","浩东2");
    return 0;
}
