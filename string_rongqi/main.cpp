#include <iostream>
#include<windows.h>
using namespace std;

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);
//    //1.string的构造函数
//    string s1;          //默认构造函数
//    cout<<"s1="<<s1<<endl;
//    cout<<"s1.capacity()="<<s1.capacity()<<endl;//当前容量可以存放的字符
//    cout<<"s1.size()="<<s1.size()<<endl;//容器中数据的大小
//    cout<<"容器动态数组的首地址="<<(void*)s1.c_str()<<endl;
//    s1 = "xxxxxxxxxxxxxxxxxx";
//    cout<<"s1.capacity()="<<s1.capacity()<<endl;
//     cout<<"s1.size()="<<s1.size()<<endl;
//     cout<<"容器动态数组的首地址="<<(void*)s1.c_str()<<endl;

//    //2.string(const char* s);将string的对象初始换为s指向转换函数
//     string s2("hello word");
//     cout<<"s2 = "<<s2<<endl;
//     string s3 = "hello word";
//     cout<<"s3 = "<<s3<<endl;

//     //3.string(const string &str);将string对象初始化为str(拷贝构造函数)
//     string s4(s3);
//     cout<<"s4 = "<<s4<<endl;
//     string s5 = s3;
//     cout<<"s5 = "<<s5<<endl;

//     //4.string(const char* s, size_t n);将string对象初始化为s指向的前n个字符
//     string s6("hello word", 5);
//     cout<<"s6="<<s6<<endl;
//     cout<<s6.capacity()<<endl;
//     cout<<s6.size()<<endl;
//     string s7 ("hello word",50);
//     cout<<"s7="<<s7<<endl;
//     cout<<s7.capacity()<<endl;
//     cout<<s7.size()<<endl;

//     //5.string(const string &str,size_t pos=0,size_t npos);将string对象初始化为str从pos开始到结尾，或者从pos开始的n个字符
//     string s8 (s3,3,3);
//     cout<<"s8="<<s8<<endl;
//     string s9(s3,3);
//     cout<<"s9="<<s9<<endl;
//     cout<<"s9.capacity()"<<s9.capacity()<<endl;
//     cout<<s9.size()<<endl;

//     string s10("hello word",3);//不调用当前构造函数，同s6
//     cout<<"s10="<<s10<<endl;

//     //6.template<class T> string(T begin, T end)：将string对象初始化为区间[begin, end]内的字符，
//     string s11(s2.begin(), s2.end());
//     cout<<"s11="<<s11<<endl;

//     //7.string(size_t n,char c);创建一个由n个字符c组成的string对象
//     string s12(8,'x');
//     cout<<"s12="<<s12<<endl;


//     return 0;
//}


//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    //特性操作
//    string s1("hello word abc");
//    cout<<"s1="<<s1<<endl;
//    cout<<"容量："<<s1.capacity()<<endl;
//    s1.shrink_to_fit();     // 将容器的容量降到实际大小（需要重新分配内存）。
//    s1.reserve(30);         // 将容器的容量设置为至少size
//    cout<<"容量："<<s1.capacity()<<endl;

//    s1.resize(5);          // 把容器的实际大小置为len，如果len<实际大小，会截断多出的部分；如果len>实际大小，就用字符c填充。
//    cout<<"s1="<<s1<<endl;
//    s1.resize(20,'c');
//    cout<<"s1="<<s1<<endl;
//    s1.clear(); //清空容器
//    cout<<"s1="<<s1<<endl;
//    bool a = s1.empty();    //bool empty() const;     // 判断容器是否为空。
//    cout<<a<<endl;
//}

#include<vector>
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    //字符操作
    //operator[]和at()返回容器中的第n个元素，但at函数提供范围检查，当越界时会抛出out_of_range异常，operator[]不提供范围检查。
    string s = "hello word";
    char a = s[0];
    cout<<"a="<<a<<endl;
    s[0] = 'H';
    cout<<"s="<<s<<endl;
    char b = s.at(1);
    cout<<"b="<<b<<endl;

    char s1[10];
    int i = s.copy(s1,4,6);   // 把当前容器中的内容，从pos(第六个字节)开始的n(4)个字节拷贝到s中，返回实际拷贝的数目。
    cout<<"i="<<i<<endl;
    cout<<"s1="<<s1<<endl;

    cout<<"------------赋值操作---------------------------"<<endl;
    //赋值操作
    char s2[10] = "haodong";
    s.assign(s2);   // 将string对象赋值为s指向的NBTS。
    cout<<"s="<<s<<endl;
    s.assign(s2,3);
     cout<<"s="<<s<<endl;
     s.assign(s2,3,4);
      cout<<"s="<<s<<endl;
    string s3 = "dong";
    s.assign(s3);
     cout<<"s="<<s<<endl;
    s.assign(5, 'x');
     cout<<"s="<<s<<endl;
     vector<char> s4 = {'s','u','n'};
    s.assign(s4.begin(),s4.end());
    cout<<"s="<<s<<endl;
     cout<<"--------------交换操作-------------------------"<<endl;
     //交换操作
     string s5 = "haodong";
     string s6 = "sun";
     s5.swap(s6);
     cout<<s5<<endl;
     cout<<s6<<endl;
    cout<<"---------------截取操作-----------------------"<<endl;
     //截取操作
    string s7 ="haodong";
     string s8 = s7.substr(3,4);  // 返回pos(3)开始的n(4)个字节组成的子容器。
     cout<<s8<<endl;
      cout<<"-----------------比较操作----------------------"<<endl;
      string s9 = "sunhaodong";
      string s10 = "haodong";
      bool c = s9==s10;
      cout<<"c="<<c<<endl;
      int d = s9.compare(s10);//比较字符串，如果调用该函数的字符串对象等于参数字符串，则返回0。如果调用该函数的字符串对象小于参数字符串，则返回一个负数。如果调用该函数的字符串对象大于参数字符串，则返回一个正数。
      cout<<"d="<<d<<endl;
      int e = s9.compare(3,7,s10);
     cout<<"e="<<e<<endl;
     int f = s9.compare(6,4,s10,3,4);
     cout<<"f="<<f<<endl;
     cout<<"-----------------查找操作----------------------"<<endl;
     string s11 = "sunhaodong";
     string s12 = "haodong";
     int g = s11.find('n',3);
     cout<<"g="<<g<<endl;
     int h = s11.find('s');
     cout<<"h="<<h<<endl;
     i = s11.find(s12,1);
     cout<<"i="<<i<<endl;
     //find()函数与rfind()用法一样find从前往后查找，rfind从后往前查找。
     int j = s11.find_first_of('h');
     cout<<"j="<<j<<endl;
     int k = s11.find_last_of('d');
     cout<<"k="<<k<<endl;
     int l = s11.find_first_not_of('a');
     cout<<"j="<<l<<endl;
     cout<<"-----------------替换操作----------------------"<<endl;
     string s13 = "sunhaodong";
     string s14 = "xi";
     s13.replace(6,4,s14);
     cout<<"s13="<<s13<<endl;
     s13.replace(6,2,"dong",0,4);
     cout<<"s13="<<s13<<endl;
     s13.replace(0,3,3,'6');
     cout<<"s13="<<s13<<endl;
    cout<<"-----------------插入操作----------------------"<<endl;
    string s15 = "haodong";
    string s16 = "sun";
    s15.insert(0,s16);
    cout<<"s15="<<s15<<endl;
    s15.insert(10,"good",0,4);
    cout<<"s15="<<s15<<endl;
    cout<<"-----------------删除操作----------------------"<<endl;
    s15.erase(10,4);
    cout<<"s15="<<s15<<endl;
}



