#include <iostream>
#include<memory>
#include<windows.h>
using namespace std;



class AA
{
public:
    string m_name;

    AA()
    {
        cout<<m_name<<"调用了构造函数1"<<endl;
    }
    AA(const string& name):m_name(name)
    {
        cout<<"调用了构造函数2"<<endl;
    }
    ~AA()
    {
        cout<<"调用了析构函数"<<endl;
    }
};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);
//    //初始化
// //    unique_ptr<AA> p0(new AA("hoadong"));
// //    unique_ptr<AA> p1 = make_unique<AA>("dong");
// //    unique_ptr<AA> p2 = make_unique<AA>();
//    //重载了*和->可以像使用指针一样使用unique_ptr,不支持普通的拷贝和赋值
//    //数组指针
//   unique_ptr<AA[]> p3 (new AA[2]);
//   p3[0].m_name = "haodong";
//   p3[1].m_name = "haoxi";
//   cout<<"p3[0].name="<<p3[0].m_name<<endl;
//   cout<<"p3[1].name="<<p3[1].m_name<<endl;

//}


void func1(const AA* a)//需要一个指针但不对指针负责
{
    cout<<a->m_name<<endl;
}

void func2(AA* a)//需要一个指针并对指针负责
{
    cout<<a->m_name<<endl;
}

void func3(const unique_ptr<AA> &a)//需要一个nuique_ptr,不会负责
{
    cout<<a->m_name<<endl;
}

void func4(unique_ptr<AA> a)//需要一个nuique_ptr,并负责
{
    cout<<a->m_name<<endl;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    unique_ptr<AA> p(new AA("hoadong"));
    //func1(p.get());//get()函数返回智能指针所管理的对象的裸指针。
    //func2(p.release());//release()释放智能指针对其所管理对象的所有权，并返回该对象的裸指针。
    //func3(p);
    func4(move(p));//move()实现转移语义
    if(p == nullptr)
    {
        cout<<"p是空指针"<<endl;
    }
}
