#include <iostream>
#include<windows.h>
using namespace std;

//构造函数，可以重载，创建对象时调用一次不能手动调用。
//析构函数，不能重载，销毁对象前只调用一次可以手动调用。
class Info
{
public:
    int m_age;
    string m_name;
    int* m_ptr;
    Info()                    //构造
    {
        m_age = 0;m_name.clear();
        cout<<"调用了Info函数"<<endl;
    }
    Info(int age)
    {
        m_age = 0;m_name.clear();m_ptr = nullptr;
        cout<<"调用了Info(age)函数"<<endl;
        m_age = age;
    }
    Info(int age,string name)
    {
        m_age = 0;m_name.clear();
        cout<<"调用了Info（age,name)函数"<<endl;
        m_age = age;m_name = name;
    }
   Info(const Info &ss)   //无参数的拷贝构造函数  //深拷贝
   {
       m_age = ss.m_age - 1;
       m_name ="年轻的"+ss.m_name;
       m_ptr = new int;
       memcpy(m_ptr,ss.m_ptr,sizeof(int));
       cout<<"调用了拷贝构造函数"<<endl;
   }
   Info(const Info &ss,int i)   //有无参数的拷贝构造函数
   {
       m_age = ss.m_age - i;
       m_name ="年轻的"+ss.m_name;
       cout<<"调用了拷贝构造函数2"<<endl;
   }
    ~Info()
    {
       delete m_ptr;
       m_ptr = nullptr;
        cout<<"调用了~Info函数"<<endl;
    }
    void setvalue(int age1,string name1);
    void print();
};

void Info::setvalue(int age1,string name1)
{
    m_age = age1;
    m_name = name1;
}

void Info::print()
{
    cout<<"age:"<<m_age<<",name:"<<m_name<<", m_ptr = "<<m_ptr<<", *m_ptr"<<*m_ptr<<endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    //Info stud;
    //Info stud(18);
    //Info stud(18,"haodong");
    //Info stud = Info();
    //Info stud = 8;

    //Info* stud = new Info;
    //stud.setvalue (18,"haodong");
    //stud.print();

    //stud->print();
    //delete stud;

    Info s1;
    s1.m_age = 18;
    s1.m_name = "sunhaodong";
    s1.m_ptr = new int(3);
    s1.print();
    Info s2(s1);
    *s2.m_ptr = 5;
    s1.print();
    //Info s2 = s1;
    s2.print();
    return 0;
}
