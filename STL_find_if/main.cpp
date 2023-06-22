#include <iostream>
#include<vector>
#include<algorithm>
#include<windows.h>
using namespace std;

template <typename T>
bool show(const T &no,const T &no1)
{
    if(no!=no1)
        return false;
    cout<<"有请编号为"<<no<<"的同学"<<endl;
    return true;
}
template <typename T>
class AA
{
public:
    bool operator()(const T& no, const T & no1)
    {
        if(no!=no1) return false;
        cout<<"有请编号为"<<no<<"的同学"<<endl;
        return true;
    }
};
template <typename T1,typename T2, typename T3>
T1 findif(const T1 first,const T1 last, T2 pfun,T3 no1)
{
    for(auto it=first;it!=last;it++)
    {
        if(pfun(*it,no1)==true) return it;

    }
    return last;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    vector<int> bh = {1,2,3,4,5,8,9};
//    auto it1 = findif(bh.begin(),bh.end(),show<int>,5);
//    if(it1==bh.end())
//         cout<<"查找失败"<<endl;
//    else
//         cout<<"查找成功"<<*it1<<endl;
    auto it2 = findif(bh.begin(),bh.end(),AA<int>(),8);
    if(it2 == bh.end())
    {
        cout<<"查找失败"<<endl;
    }
    else
    {
        cout<<"查找成功"<<endl;
    }
}
