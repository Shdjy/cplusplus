#include <iostream>
#include<windows.h>
using namespace std;

//int main()
//{
//    int* p = new int(5);
//    cout << "*p=" << *p<< endl;//用new运算符向系统申请一块内存，让指针指向这块内存；通过对指针解引用的方法，像使用变量一样使用这块内存；如果这块内存不用了，用delete运算符释放它。
//    *p = 8;
//    cout<< "*p=" <<*p<<endl;
//    delete p;
//    return 0;
//}


//void fun(string name,int age)
//{
//    cout<<"name:"<<name<<"age:"<<age<<endl;
//}

//int main()
//{
//    string name = "sunhaodong";
//    int age = 23;
//    fun(name,age);

//    void (*pf)(string, int);
//    pf = fun;
//    pf(name,age);
//    (*pf)(name,age);//c语言
//    return 0;
//}

//回调函数
//void fun(string name,int age)
//{
//    cout<<"name:"<<name<<"age:"<<age<<endl;
//}
//void fun2(void (*pf)(string,int),string name, int age)
//{
//    cout<<"学生信息："<<endl;
//    pf(name,age);
//}
//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    string name = "sunhaodong";
//    int age = 23;

//    fun2(fun,name,age);

//}

//用new创建数组

//int main()
//{
//    int* arr = new int[5];//创建数组
//    int i = 0;
//    for(i = 0;i <5;i++)
//    {
//        arr[i] = 618;
//        cout<<"arr["<<i<<"]="<<arr[i]<<endl;
//    }
//    delete[]arr;//释放数组

//    return 0;
//}


//qsort（）函数，数组排序

//int compasc(const void* p1,const void* p2)
//{
//    return(*(int*)p1 - *(int*)p2);
//}
//int compdesc(const void* p1,const void* p2)
//{
//    return(*(int*)p2 - *(int*)p1);
//}
//int main()
//{
//    int arr[9] = {9,6,3,8,5,2,7,4,1};

//    qsort(arr, sizeof(arr)/sizeof(arr[1]),sizeof(int), compasc );
//    for(int i = 0;i<8;i++)
//    {
//        cout<<"arr["<<i<<"]="<<arr[i];

//    }
//     cout<<endl;
//    qsort(arr, sizeof(arr)/sizeof(arr[1]),sizeof(int), compdesc );
//    for(int i = 0;i<8;i++)
//    {
//        cout<<"arr["<<i<<"]="<<arr[i];

//    }
//     cout<<endl;
//    return 0;
//}

//折半查找

int search(const int arr[],int len,int key)

{
   int low = 0;
   int high = len-1;
   int mind = 0;
   while(low <= high)
   {
       mind = (low + high)/2;
       if(arr[mind] == key)
       {
           return mind;
       }
       if(arr[mind] < key)
       {
           low = mind + 1;
       }
       if(arr[mind] > key)
       {
           high = mind - 1;
       }
   }
   return -1;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int i = search(arr, sizeof(arr)/sizeof(arr[0]),3);
    if(i >=0)
    {
        cout<<"找到了，下标为："<<i<<endl;
    }
    else
        cout<<"未找到！"<<endl;
    return 0;
}


