#include <iostream>
#include<windows.h>
#include<memory>
using namespace std;

//多个shared_ptr可以指向（关联）相同的对象，在内部采用计数机制来实现。
class AA
{
public:
    string m_name;
    AA() { cout << m_name << "调用构造函数AA()。\n"; }
    AA(const string & name) : m_name(name) { cout << "调用构造函数AA("<< m_name << ")。\n"; }
    ~AA() { cout << "调用了析构函数~AA(" << m_name << ")。\n"; }
};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    //初始化
//    //shared_ptr<AA> p(new AA("dong"));
//    //shared_ptr<AA> p1 = make_shared<AA>("dong");
//    AA* p2 = new AA("dong");
//    //shared_ptr<AA> p3(p2);
//    shared_ptr<AA> p4 = shared_ptr<AA> (p2);
//    int a = p4.use_count();
//    cout<<"a="<<a<<endl;
//    bool b= p4.unique();
//    cout<<"b="<<b<<endl;
//}


//int main()
//{
//     SetConsoleOutputCP(CP_UTF8);

//     shared_ptr<AA> p(new AA("浩东"));
//     shared_ptr<AA> p1 = p;
//     shared_ptr<AA> p2 = p;
//     cout<<"p.use_cout="<<p.use_count()<<endl;

//     shared_ptr<AA> pp(new AA("dong"));
//     shared_ptr<AA> pp1 = pp;
//     cout<<"pp.use_cout="<<pp.use_count()<<endl;

//     pp1 = p1;

//     cout<<"p.use_cout="<<p.use_count()<<endl;
//     cout<<"pp.use_cout="<<pp.use_count()<<endl;
//}


//智能指针的删除器
void deletefunc(AA* a)
{
    cout<<"全局自定义删除器"<<endl;
    delete a;
}
struct deleteclass
{
    void operator()(AA* a)
    {
        cout<<"仿函数自定义删除器"<<endl;
        delete a;
    }
};
auto deletelamb = [](AA* a)
{
    cout<<"lambda自定义删除器"<<endl;
          delete a;
};
int main()
{
     SetConsoleOutputCP(CP_UTF8);

     //shared_ptr<AA> p1(new AA("dong"),deletefunc);
     //shared_ptr<AA> p1(new AA("dong"),deleteclass());
     //shared_ptr<AA> p1(new AA("dong"),deletelamb);

     //unique_ptr<AA,decltype(deletefunc)*> p(new AA("dong"), deletefunc);
     //unique_ptr<AA,void(*)(AA*)> p(new AA("dong"), deletefunc);
     //unique_ptr<AA,deleteclass> p(new AA("dong"), deleteclass());
     unique_ptr<AA,decltype(deletelamb)> p(new AA("dong"), deletelamb);
}
