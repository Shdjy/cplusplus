#include <iostream>
#include<windows.h>
#include<map>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    //构造函数
    map<int, string> m1;//创建一个空的map容器
    map<int, string> m2({{1,"haodong"},{2,"sunhaodong"},{3,"jiaqi"}});//使用统一初始化列表
    for(auto&val:m2)
        cout<<val.first<<","<<val.second<<"   ";
    cout<<endl;
    map<int, string>m3 = m2;//使用map(const map<k,v>&m);拷贝构造函数
    for(auto&val:m3)
        cout<<val.first<<","<<val.second<<"   ";
    cout<<endl;
    map<int, string> m4(m3.begin(),m3.end());//使用迭代器创建map容器
    for(auto&val:m4)
        cout<<val.first<<","<<val.second<<"   ";
    cout<<endl;
    cout<<"-------------特性操作-----------------"<<endl;
    cout<<"m2.size():"<<m2.size()<<endl;
    cout<<"是否为空"<<m2.empty()<<endl;
    m2.clear();
    cout<<"是否为空"<<m2.empty()<<endl;
    cout<<"-------------元素操作-------------"<<endl;
    cout<<"m3[1]:"<<m3[1]<<endl;//用给定的key访问元素
    cout<<"m3[2]:"<<m3.at(2)<<endl;
    cout<<"------------------交换操作-----------"<<endl;
    map<int,string>m5({{1,"one"},{2,"two"},{3,"three"}});
    m5.swap(m3);
    for(auto&val:m5)
        cout<<val.first<<","<<val.second<<"   ";
    cout<<endl;
    cout<<"----------------查找操作---------------"<<endl;
    auto im = m5.find(2);
    cout<<"m5[2]:"<<im->second<<endl;
    auto im2 = m5.lower_bound(2);
    cout<<im2->second<<endl;
    auto im3 = m5.upper_bound(2);
    cout<<im3->second<<endl;

    cout<<"k=3:"<<m5.count(3)<<endl;
    cout<<"---------------插入和删除--------------"<<endl;
    m3.insert({{4,"four"}});
    for(auto&val:m3)
        cout<<val.first<<","<<val.second<<"   ";
    cout<<endl;
    map<int,string> m6;
    m6.insert(m5.begin(),m5.end());
    for(auto&val:m6)
        cout<<val.first<<","<<val.second<<"   ";
    cout<<endl;
//    6）size_t erase(const K & key);  // 从容器中删除指定key的元素，返回已删除元素的个数。
//    7）iterator erase(iterator pos);  // 用迭代器删除元素，返回下一个有效的迭代器。
//    8）iterator erase(iterator first,iterator last);  // 用迭代器删除一个区间的元素，返回下一个有效的迭代器。
    return 0;
}
