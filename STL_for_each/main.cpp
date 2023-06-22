#include <iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<windows.h>
using namespace std;

template <typename T>
void show(const T &no)
{
    cout<<"有请编号为"<<no<<"的同学"<<endl;
}
template <typename T>
class AA
{
public:
    void operator()(const T &no)
    {
          cout<<"有请编号为"<<no<<"的同学"<<endl;
    }
};
template <typename T1, typename T2>
void foreach(const T1 first,const T1 last, T2 pfun)
{
    for(auto it=first;it!=last;it++)
    {
        pfun(*it);
    }
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    vector<int> bh={1,2,3,4,5,6,7};
    //foreach(bh.begin(),bh.end(),show<int>);
    foreach(bh.begin(),bh.end(),AA<int>());
}
