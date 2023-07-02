#include <iostream>
#include<windows.h>
#include<map>
#include<cstring>
#include<string.h>
using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    map<string,string> mp;
    map<string,string>::iterator iter;
    char key[3][20] = {"img","system","ip"};
    char value[3][20] = {"d:/a.img","win10","193.168.6.3"};
    for(int i=0;i<2;i++)
    {
        mp.insert(make_pair(key[i],value[i]));
    }
    mp.insert(pair<string,string>(key[2],value[2]));

    mp["addr"] = "中国";//数组插入方式
    for(iter = mp.begin();iter!=mp.end();iter++)//迭代器取出元素，循环去除元素
    {
        cout<<iter->first<<"\t"<<iter->second<<endl;
    }
    char key1[20];
    cout<<"请输入按key查找：";
    cin.getline(key1,20);
    for(iter=mp.begin();iter!=mp.end();iter++)
    {
        if(strcmp(iter->first.c_str(),key1)==0)
        {
            cout<<iter->first<<"找到了,对应值："<<iter->second<<endl;
        }
    }
    //第一种删除方式
    iter = mp.find("addr");
    if(iter!=mp.end())
    {
        cout<<iter->first<<"按照key找到了!对应value值为"<<iter->second<<endl;
        cout<<"开始删除元素"<<endl;
        mp.erase(iter);
    }
    //第二种删除方式
    char drop_key[20];
    char drop_value[20];
    cout<<"请输入按key删除：";
    cin.getline(drop_key,20);
    cout<<"请输入按value删除：";
    cin.getline(drop_value,20);
    for(iter = mp.begin();iter!=mp.end();iter++)
    {
        if(strcmp(iter->first.c_str(),drop_key)==0)
        {
            cout<<iter->first<<"按照key找到了，对应的value为:"<<iter->second<<endl;
            cout<<"开始删除！"<<endl;
            mp.erase(iter);
            break;
        }
        if(strcmp(iter->second.c_str(),drop_value)==0)
        {
            cout<<iter->second<<"按照value找到了，对应的key值为："<<iter->first<<endl;
            cout<<"开始删除！"<<endl;
            mp.erase(iter);
            break;
        }
    }
    cout << "----------删除元素后----------" << endl;
    for(iter=mp.begin();iter!=mp.end();iter++)
    {
        cout<<iter->first<<"\t"<<iter->second<<endl;
    }
    return 0;
}
