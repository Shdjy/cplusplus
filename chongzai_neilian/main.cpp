#include <iostream>

using namespace std;

//函数重载
//void myswap(int &a, int &b)
//{
//    int tmp = a;
//    a = b;
//    b = tmp;
//}
//void myswap (string &s,string &t)
//{
//    string tmp = s;
//    s = t;
//    t = tmp;
//}
//int main()
//{
//    int a = 18;
//    int b = 23;
//    cout<<"a="<<a<<"b="<<b<<endl;
//    myswap(a, b);
//    cout <<"a="<<a<<"b="<<b<< endl;

//    string s = "sunhaodong";
//    string t = "haodong";
//    cout<<"s ="<<s<<", t ="<<t<<endl;
//    myswap(s, t);
//    cout<<"s ="<<s<<", t ="<<t<<endl;
//    return 0;
//}


//内联函数
//函数的定义声明前加上,inline
//节省时间消耗内存，函数不能过大，函数不能递归

inline void print(const int a,const string b)
{
    cout<<"age:"<<a<<", name:"<<b<<endl;
}
int main()
{
    print(18,"haosong");
    int age = 23;
    string name = "sunhaodong";
    cout<<"age:"<<age<<", name:"<<name<<endl;
    return 0;
}
