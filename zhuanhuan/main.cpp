#include <iostream>

using namespace std;


//explicit关键字用于关闭这种自动特性，但仍允许显式转换。
//class Boy
//{
//public:
//    int m_age;
//    string m_name;
//    double m_weight;
//    explicit Boy(int age)
//    {
//        m_age = age;
//        m_name.clear();
//        m_weight = 0;
//    }
//    explicit Boy(double weight)
//    {
//        m_age = 0;
//        m_name.clear();
//        m_weight = weight;
//    }
//    void print()
//    {
//        cout<<"age:"<<m_age<<", name:"<<m_name<<",weight:"<<m_weight<<endl;
//    }
//};

//int main()
//{
//   Boy b1(8);   //常规
//   b1.print();
//   //Boy b2 = 9;  //隐式转换
//   //b2.print();
//   Boy b3 = Boy(7);//显式转换
//   b3.print();
//   Boy b4(60.5);
//   b4.print();
//    return 0;
//}

class Boy
{
public:
    int m_age;
    string m_name;
    double m_weight;
    Boy()
    {
        m_name = "haodong";
        m_age = 18;
        m_weight = 65.5;
    }
    explicit operator int()
    {
        return m_age;
    }
    int to_int()
    {
        return m_age;
    }
    operator string()
    {
        return m_name;
    }
    explicit operator double()
    {
        return m_weight;
    }
};

int main()
{
    Boy b;
    //int i = int(b);
    int i = b.to_int();
    cout<<"i="<<i<<endl;
    string ii = string(b);
    cout<<"string="<<ii<<endl;

    return 0;
}
