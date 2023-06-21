#include <iostream>
#include<windows.h>
#include<memory>
using namespace std;

//weak_ptr 是为了配合shared_ptr而引入的，它指向一个由shared_ptr管理的资源但不影响资源的生命周期。也就是说，将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数。
//不论是否有weak_ptr指向，如果最后一个指向资源的shared_ptr被销毁，资源就会被释放。
//weak_ptr更像是shared_ptr的助手而不是智能指针。
//1）operator=();  // 把shared_ptr或weak_ptr赋值给weak_ptr。
//2）expired();     // 判断它指资源是否已过期（已经被销毁）。
//3）lock();        // 返回shared_ptr，如果资源已过期，返回空的shared_ptr。
//4）reset();       // 将当前weak_ptr指针置为空。
//5）swap();       // 交换。

class BB;
class AA
{
public:
    string m_name;
    AA()
    {
        cout<<"调用了AA的构造函数1"<<endl;
    }
    AA(const string name):m_name(name)
    {
        cout<<"调用了AA的构造函数2"<<endl;
    }
    ~AA()
    {
        cout<<"调用了AA的析构函数"<<endl;
    }
    weak_ptr<BB> m_p;
};

class BB
{
public:
    string m_name;
    BB()
    {
        cout<<"调用了BB的构造函数1"<<endl;
    }
    BB(const string name):m_name(name)
    {
        cout<<"调用了BB的构造函数2"<<endl;
    }
    ~BB()
    {
        cout<<"调用了BB的析构函数"<<endl;
    }
    weak_ptr<AA> m_p;
};
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    shared_ptr<AA> pa = make_shared<AA>("haodong1");
    {
        shared_ptr<BB> pb = make_shared<BB>("haodong2");
        pa->m_p = pb;
        pb->m_p = pa;
        shared_ptr<BB> pp = pa->m_p.lock();
        if(pp == nullptr)
        {
            cout<<"语句块内：pa->m_p已过期"<<endl;
        }
        else
        {
            cout<<"语句块内：pp->m_name="<<pp->m_name<<endl;
        }
    }
    shared_ptr<BB> pp = pa->m_p.lock();
    if(pp == nullptr)
    {
        cout<<"语句块外部：pa->m_p已过期"<<endl;
    }
    else
    {
        cout<<"语句块外部:pp->m_p="<<pp->m_name<<endl;
    }

}
