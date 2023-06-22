#include <iostream>
#include<windows.h>
#include<fstream>
using namespace std;

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    string filename = R"(D:\c++_code\file_operation\test.txt)";
//    ofstream fout;
//    fout.open(filename,ios::app); //ios::out     		缺省值：会截断文件内容。
//                                //ios::trunc  		截断文件内容。（truncate）
//                                //  ios::app   		不截断文件内容，只在文件未尾追加文件。（append）
//    if(fout.is_open() == false)
//    {
//        cout<<"打开文件"<<filename<<"失败"<<endl;
//        return 0;
//    }
//    fout<<"浩东，23，身高180，体重70"<<endl;
//    fout<<"浩东，23，身高180，体重70"<<endl;
//    fout<<"浩东，23，身高180，体重70"<<endl;
//    fout.close();
//    cout<<"文件操作完成"<<endl;
//}

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);
//    string filename = R"(D:\c++_code\file_operation\test.txt)";
//    ifstream fin;
//    fin.open(filename,ios::in);
//    if(fin.is_open() == false)
//    {
//        cout<<"打开文件失败"<<endl;
//    }
//    //方法1
// //    string buffer;
// //    while(getline(fin,buffer))
// //    {
// //        cout<<buffer<<endl;
// //    }
//    //方法2
// //    char buffer[100];//保证缓冲区足够大
// //    while(fin.getline(buffer, 99))
// //    {
// //        cout<<buffer<<endl;
// //    }
//    //方法3
//    string buffer;
//    while(fin>>buffer)
//    {
//        cout<<buffer<<endl;
//    }
//    fin.close();
//    cout<<"操作文件完成"<<endl;
//}
    //二进制文件
    // 创建文件输出流对象，打开文件，如果文件不存在，则创建它。
    // ios::out     		缺省值：会截断文件内容。
    // ios::trunc  		截断文件内容。（truncate）
    // ios::app   			不截断文件内容，只在文件未尾追加文件。（append）
    // ios::binary   		以二进制方式打开文件。
    //ofstream fout(filename, ios::binary);
    //ofstream fout(filename, ios::out | ios::binary);
    //ofstream fout(filename, ios::trunc | ios::binary);
    //ofstream fout(filename, ios::app | ios::binary);

//随机存取

//移动文件位置指针
//方法一：
//std::istream & seekg(std::streampos _Pos);
//fin.seekg(128);   // 把文件指针移到第128字节。
//fin.seekp(128);   // 把文件指针移到第128字节。
//fin.seekg(ios::beg) // 把文件指针移动文件的开始。
//fin.seekp(ios::end) // 把文件指针移动文件的结尾。
//方法二：
//std::istream & seekg(std::streamoff _Off,std::ios::seekdir _Way);
//在ios中定义的枚举类型：
//enum seek_dir {beg, cur, end};  // beg-文件的起始位置；cur-文件的当前位置；end-文件的结尾位置。
//fin.seekg(30, ios::beg);    // 从文件开始的位置往后移30字节。
//fin.seekg(-5, ios::cur);     // 从当前位置往前移5字节。
//fin.seekg( 8, ios::cur);     // 从当前位置往后移8字节。
//fin.seekg(-10, ios::end);   // 从文件结尾的位置往前移10字节。
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    string filename = R"(D:\c++_code\file_operation\test.txt)";
    fstream fs;
    fs.open(filename,ios::in | ios::out);
    if(fs.is_open() == false)
    {
        cout<<"打开文件失败"<<endl;
    }
    fs.seekg(29);
    fs<<"孙\n";
    fs.seekg(0);
    string buffer;
    while(fs>>buffer)
    {
        cout<<buffer<<endl;
    }
    fs.close();
    cout<<"文件操作over"<<endl;
}
