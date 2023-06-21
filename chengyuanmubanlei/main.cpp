#include <iostream>

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
        cout<<"a="<<m_a<<", b="<<m_b<<endl;
    }
    template<class T>
    class BB
    {
    public:
        T m_x;
        T1 m_aa;
        BB(){}
        void show();
    };
    BB<string> m_bb;
    template<typename T>
    void show(T tt);
};
template <class T1,class T2>
template<class T>
void AA<T1,T2>::BB<T>::show()
{
    cout<<"x="<<m_x<<", aa="<<m_aa<<endl;
}
template <class T1,class T2>
template<typename T>
void AA<T1,T2>::show(T tt)
{
    cout<<"tt="<<tt<<endl;
     cout<<"a="<<m_a<<", b="<<m_b<<endl;
     m_bb.show();
}
int main()
{
    AA<int, string> a(18,"dong");
    a.show();
    a.m_bb.m_x = "haodomg";
    a.m_bb.show();
    return 0;
}
