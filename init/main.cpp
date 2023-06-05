#include <iostream>
#include<windows.h>

using namespace std;

//class girlf
//{
//public:
//    string m_name;
//    girlf()
//    {
//        m_name.clear();
//        cout<<"调用了构造函数"<<endl;
//    }
//    girlf(string name)
//    {
//        m_name = name;
//        cout<<"调用了构造函数2"<<endl;
//    }
//    girlf(const girlf &gg)
//    {
//        m_name = gg.m_name;
//        cout<<"调用了拷贝构造函数"<<endl;
//    }
//};

//class Boy
//{
//public:
//    int m_age;
//    string m_name;
//    girlf&  m_girl;
// //    Boy()
// //    {
// //        cout<<"调用了Boy构造函数"<<endl;
// //    }
// //    Boy(int age, string name,girlf &girl)
// //    {
// //        m_age = age;
// //        m_name = name;
// //        m_girl.m_name = girl.m_name;
// //        cout<<"调用了Boy构造函数2"<<endl;
// //    }
//    Boy(int age, string name,girlf &girl):m_age(age),m_name(name),m_girl(girl)
//    {
//        cout<<"调用了Boy构造函数3"<<endl;
//    }
//    void print() const
//    {
//        cout<<"姓名："<<m_name<<", 年龄："<<m_age<<"， 女朋友"<<m_girl.m_name<<endl;
//    }
//};


//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    girlf girl("jiaqi");

//    Boy b1(23,"haodong",girl);
//    b1.print();
//    return 0;
//}


//this指针

class Boy
{
public:
    int m_age;
    string m_name;
    Boy(int age, string name)
    {
        m_age = age;
        m_name = name;
    }
    const Boy& bijiao(const Boy& b)const
    {
        if(b.m_age<m_age)
            return b;
        else
            return *this;
    }
    void show()const
    {
        cout<<"我是："<<m_name<<", 我的年龄："<<m_age<<endl;
    }

};

int main()
{
     SetConsoleOutputCP(CP_UTF8);
    //让年龄最小的进行自我介绍
    Boy b1(12,"zhangsan"),b2(10,"lisi"),b3(15,"wangwu");
    const Boy &b = b1.bijiao(b2).bijiao(b3);
    b.show();
    return 0;
}
