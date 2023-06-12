#include <iostream>
#include<windows.h>
using namespace std;


template <class T1,class T2>
class AA
{
public:
    T1 m_a;
    T2 m_b;
    AA(const T1 a,const T2 b):m_a(a),m_b(b){}
    void show()
    {
        cout<<"show()a="<<m_a<<", b="<<m_b<<endl;
    }
};

AA<int,string>func(AA<int,string >& aa)
{
    aa.show();
    cout<<"调用了func(AA<int,string >& aa)"<<endl;
    return aa;

}

//template <typename T1,typename T2>
//AA<T1, T2> func(AA<T1, T2>& aa)
//{
//    aa.show();
//    cout << "调用了func(AA<T1, T2> &aa)函数。\n";
//    return aa;
//}


template <typename T>
T func(T &aa)
{
    aa.show();
    cout << "调用了func(AA<T> &aa)函数。\n";
    return aa;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

   AA<int,string>aa(18,"dong");
   func(aa);

   AA<int,int>bb(18,23);
   func(bb);


    return 0;
}
