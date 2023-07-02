#include <iostream>
#include<fstream>
#include<vector>
#include<windows.h>
#include<iterator>
using namespace std;
class student
{
private:
    string m_name;
    int m_id;
    int m_chinese;
    int m_math;
    int m_english;
public:
    student(){}
    student(string name,int id, int chinese, int math, int english)
    {
        m_name = name;
        m_id = id;
        m_chinese = chinese;
        m_math = math;
        m_english = english;
    }
    void show()
    {
        cout<<"name:"<<m_name<<"id:"<<m_id
           <<"chinese:"<<m_chinese<<"math:"<<m_math
           <<"english:"<<m_english<<endl;
    }
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    char ys;
    string name;
    int id,chinese,math,english;
    fstream iofile;
    iofile.open("D:\\c++_code\\read_write\\test.txt",ios::out | ios::app);
    cout<<"------------简历学生信息------------"<<endl;
    do{
        cout<<"请输入id："<<endl;
        cin>>id;
        cout<<"请输入姓名："<<endl;
        cin>>name;
        cout<<"请输入语文成绩："<<endl;
        cin>>chinese;
        cout<<"请输入数学成绩："<<endl;
        cin>>math;
        cout<<"请输入英语成绩："<<endl;
        cin>>english;
        student s(name, id, chinese, math, english);
        iofile.write((char*)&s, sizeof(s));
        cout<<"是否继续建档？(Y/N)";
        cin>>ys;
    }while(ys == 'Y');
    iofile.close();
    iofile.open("D:\\c++_code\\read_write\\test.txt",ios::in);
    student s1;
    iofile.read((char*)&s1,sizeof(s1));
    vector<student> v;
    vector<student>::iterator vt;
    while(!iofile.eof())
    {
        v.push_back(s1);
        iofile.read((char*)&s1,sizeof(s1));
    }
    iofile.close();
    cout<<"-----------------输出档案信息----------------"<<endl;
    for(vt=v.begin();vt!=v.end();vt++)
    {
        (*vt).show();
    }
    return 0;
}
