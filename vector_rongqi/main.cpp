#include <iostream>
#include<windows.h>
#include<vector>
using namespace std;
//vector容器
//int main()
//{
////    1）vector();  // 创建一个空的vector容器。
//    vector<int> v;
//    cout<<"v.capacity="<<v.capacity()<<endl;
//    cout<<"v.size()="<<v.size()<<endl;

////    2）vector(initializer_list<T> il); // 使用统一初始化列表。
//    vector<int> v2(8);
//    cout<<"v2.capacity="<<v2.capacity()<<endl;
//    cout<<"v2.size()="<<v2.size()<<endl;

////    3）vector(const vector<T>& v);  // 拷贝构造函数。
//    vector<int> v3(v2);
//    cout<<"v3.capacity="<<v3.capacity()<<endl;
//    cout<<"v3.size()="<<v3.size()<<endl;
////    4）vector(Iterator first, Iterator last);  // 用迭代器创建vector容器。
//    vector<int> v4 = {1,2,3,4,5,6};
//    vector<int> v5(v4.begin(),v4.end());
//    cout<<"v5.capacity="<<v5.capacity()<<endl;
//    cout<<"v5.size()="<<v5.size()<<endl;
////    5）vector(vector<T>&& v);  // 移动构造函数（C++11标准）。
//    vector<int> v6(move(v5));
////    6）explicit vector(const size_t n);   // 创建vector容器，元素个数为n（容量和实际大小都是n）。
//    vector<int> v7(5);
//    cout<<"v7.capacity()="<<v7.capacity()<<endl;
////    7）vector(const size_t n, const T& value);  // 创建vector容器，元素个数为n，值均为value。
//    vector<int> v8(6,6);
//    for(int val:v8)
//    {
//        cout<<val<<' ';
//    }

//    return 0;
//}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    cout<<"-----------------特性操作-----------------"<<endl;
    vector<int> v(6,6);
    bool a=v.empty();
    cout<<a<<endl;

    vector<int> v1(8);
    v1 = {6,6,6,6,6,6,};
    cout<<"v1.capacity()="<<v1.capacity()<<endl;
    v1.shrink_to_fit();  //需要重新分配内存
    cout<<"v1.capacity="<<v1.capacity()<<endl;
    cout<<"v1.size="<<v1.size()<<endl;
    v1.resize(10,8);
    cout<<"v1.size="<<v1.size()<<endl;
    for(int val:v1)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    cout<<"-----------------元素操作----------------"<<endl;
    cout<<"v1[7]="<<v1[7]<<endl;
    cout<<"v1[7]="<<v1.at(5)<<endl;
    cout<<"首地址："<<v1.data()<<endl;
    cout<<"v1[0]="<<v1.front()<<endl;
    cout<<"v1[9]="<<v1.back()<<endl;
    cout<<"-----------------赋值操作----------------"<<endl;
    vector<int> v2;
    v2 = v1;
    for(int val:v2)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    vector<int> v3;
    v3.assign({1,2,3,4,5,6});
    for(int val:v3)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    vector<int> v4;
    v4.assign(v2.begin(),v2.end());
    for(int val:v4)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    cout<<"-----------------交换操作----------------"<<endl;
    v3.swap(v2);
    for(int val:v2)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    cout<<"-----------------插入和删除----------------"<<endl;
    vector<int> v5;
    v5.assign({1,2,3,4,5,6});
    v5.push_back(7);
    v5.emplace_back(8);// // 在容器的尾部追加一个元素，…用于构造元素。
    for(int val:v5)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    auto i = v5.insert(v5.begin(),0);
    v5.emplace(i,99);
    for(int val:v5)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    vector<int> v6={1,2,3,4,5,6,7};
    vector<int> v7={1,2,3,4};
    v6.insert(v6.end(),v7.begin(),v7.end());
    for(int val:v6)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    cout<<"--------------------------------"<<endl;
    v6.pop_back();
    for(int val:v6)
    {
        cout<<val<<' ';
    }
    cout<<endl;
    v6.erase(v6.end()-1);
    v6.erase(v6.begin(),v6.begin()+3);
    for(int val:v6)
    {
        cout<<val<<' ';
    }
}
