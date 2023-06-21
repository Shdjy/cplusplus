#include <iostream>

using namespace std;


//static_cast<目标类型>(表达式);用于内置结构的转换

//int main()
//{
//    int i = 10;
//    double a = static_cast<double>(i);
//    cout<<"a="<<a<<endl;
//    //double* pi = static_cast<double>(&i);  //错误不支持普通类型的指针

//    void* pi1 = &i;
//    double* pi2 = static_cast<double*>(pi1);

//}

//const_cast<目标类型>(表达式);可以丢掉const的属性

void func(int *ii)
{}

int main()
{
    const int *aa=nullptr;
    int *bb = (int *)aa;                          // C风格，强制转换，丢掉const限定符。
    int* cc = const_cast<int*>(aa);      // C++风格，强制转换，丢掉const限定符。

    func(const_cast<int *>(aa));
}

//reinterpret_cast<目标类型>(表达式);可以转换不同类型的指针

//int main()
//{
//    char* a = nullptr;
//    int *aa = reinterpret_cast<int*>(a);

//}


