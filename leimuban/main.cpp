#include <iostream>
#include <windows.h>
using namespace std;

//template <class T1,class T2>
//class AA
//{
//public:
//    T1 m_a;
//    T2 m_b;
//    AA(){}
//    AA(T1 a,T2 b):m_a(a),m_b(b){}
//    T1 gata()
//    {
//        T1 a = 2;
//        return m_a+a;
//    }
//    T2 getb();
//};
//template <class T1, class T2>
//T2 AA<T1,T2>::getb()
//{
//    return m_b;
//}
//int main()
//{
//    AA<int,string>* a = new AA<int,string>(18,"haodong");  //必须指明具体的数据类型

//    cout<<"a->geta:"<<a->gata()<<endl;
//    cout<<"a->getb:"<<a->getb()<<endl;
//    return 0;
//}


//模板类的实例-栈

//template <class datetype>
//class Stack
//{
//private:
//    datetype* item;
//    int stacksize;
//    int top;
//public:
//    Stack(int size):stacksize(size),top(0)
//    {
//        item = new datetype[stacksize];
//    }
//    ~Stack()
//    {
//        delete[] item;
//        item = nullptr;
//    }
//    //判断栈空
//    bool isempty()const
//    {
//        return top == 0;
//    }
//    //判断栈满
//    bool isfull()const
//    {
//        return top == stacksize - 1;
//    }
//    //入栈
//    bool push(const datetype& item)
//    {
//        if(top < stacksize){
//            this->item[top++] = item;

//            return 1;
//        }
//        return 0;
//    }
//    //出栈
//    bool pop(datetype& item)
//    {
//        if(top >0)
//        {
//            item = this->item[--top];

//            return 1;
//        }
//        return 0;
//    }

//};

//int main()
//{
//    Stack<int>ss(5);
//    ss.push(1); ss.push(2); ss.push(3); ss.push(4); ss.push(5);
//    int item;
//    while(ss.isempty() == false)
//    {
//        ss.pop(item);
//        cout<<"item="<<item<<endl;
//    }
//}

//类模板实例--数组
//template<class T,int len = 10>  //不可变
//class Arr
//{
//private:
//    int item[len];
//public:
//    Arr(){}
//    ~Arr(){}
//    T& operator[](int i)
//    {
//        return item[i];
//    }
//    const T& operator[](int i)const
//    {
//        return item[i];
//    }
//};
//int main()
//{
//    Arr<int>aa;
//    aa[0] = 1; aa[1] = 2; aa[2] = 12; aa[3] = 12; aa[4] = 13;
//    for(int i = 0;i<5;i++)
//    {
//        cout<<"aa["<<i<<"]="<<aa[i]<<endl;
//    }
//}


//template<class T>
//class Vector
//{
//private:
//    int len;
//    T* item;    //数组元素
//public:
//    Vector(int size):len(size)
//    {
//        item = new T[len];
//    }
//    ~Vector()
//    {
//        delete [] item;
//        item = nullptr;
//    }
//    void resize(int size)
//    {
//        if(size <= len)return;
//        T*tmp = new T[size];
//        for(int i = 0;i<len;i++)
//        {
//            tmp[i] = item[i];
//        }
//        delete[] item;
//        item = tmp;
//        len = size;
//        cout<<"扩容"<<endl;
//    }
//    int size()const
//    {
//        return len;
//    }
//    T& operator[](int i)
//    {
//        if(i>=len)
//        {
//            resize(i+1);
//        }
//        return item[i];
//    }
//    const T& operator[](int i)const
//       {
//           return item[i];
//       }
//};
//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    Vector<int>aa(10);
//    aa[0] = 1; aa[1] = 2; aa[2] = 12; aa[3] = 12; aa[4] = 13;
//        for(int i = 0;i<5;i++)
//        {
//            cout<<"aa["<<i<<"]="<<aa[i]<<endl;
//        }
//}


//嵌套递归使用模板类
//template<class datetype>
//class Stack
//{
//private:
//    datetype* item;
//    int stacksize;
//    int top;
//public:
//    Stack(int size = 3):stacksize(size),top(0)
//    {
//        item = new datetype[stacksize];
//    }
//    ~Stack()
//    {
//        delete[] item;
//        item = nullptr;
//    }
//    //重载复制运算实现深拷贝
//    Stack& operator=(const Stack& v)
//    {
//        delete[] item;
//        stacksize = v.stacksize;
//        item = new datetype[stacksize];
//        for(int i = 0;i<stacksize;i++)
//            item[i] = v.item[i];
//        top = v.top;
//        return *this;
//    }
//    bool isempty()const
//    {
//        return top ==0;
//    }
//    bool isfull()const
//    {
//        return top == stacksize -1;
//    }
//    bool push(const datetype& item)//入栈
//    {
//        if(top < stacksize)
//        {
//            this->item[top++] = item;
//            return 1;
//        }
//        return 0;
//    }
//    bool pop(datetype& item)//出栈
//    {
//        if(top > 0)
//        {
//            item = this->item[--top];
//            return 1;
//        }
//        return 0;
//    }
//};
//template <class T>
//class Vector
//{
//private:
//    int len;
//    T* item;
//public:
//    Vector(int size = 2):len(size)
//    {
//        item = new T[len];
//    }
//    ~Vector()
//    {
//        delete[] item;
//        item = nullptr;
//    }
//    //重载运算符实现深拷贝
//    Vector& operator=(const Vector& v)
//    {
//        delete[] item;
//        len = v.len;
//        item = new T[len];
//        for(int i = 0;i<len;i++)
//            item[i] = v.item[i];
//        return *this;
//    }
//    void resize(int size)
//    {
//        if(size <= len)
//            return;
//        T* tmp = new T[size];
//        for(int i = 0;i<len;i++)
//            tmp[i] = item[i];
//        delete[] item;
//        item = tmp;
//        len = size;
//    }
//    int size()const
//    {
//        return len;
//    }
//    T& operator[](int i)
//    {
//        if(i >= len)
//            resize(i+1);
//        return item[i];
//    }
//    const T& operator[](int i)const{return item[i];}
//};
//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    Vector<Stack<int>>vs;
//    vs[0].push(1); vs[0].push(2); vs[0].push(3);
//    vs[1].push(4); vs[1].push(5); vs[1].push(6);
//    vs[2].push(7); vs[2].push(8);
//    for(int i = 0;i<vs.size();i++)
//    {
//        while(vs[i].isempty() == 0)
//        {
//            int item;
//            vs[i].pop(item);
//            cout<<"item="<<item<<endl;
//        }
//    }

//    // 创建Stack容器，容器中的元素用Vector<string>。
//        Stack<Vector<int>> sv;

//        Vector<int> tmp;

//        tmp[0] = 1; tmp[1] = 2;
//        sv.push(tmp);

//        tmp[0] = 3; tmp[1] = 4;
//        sv.push(tmp);

//        tmp[0] = 5; tmp[1] = 6;   tmp[2] = 7;  tmp[3] = 8;
//        sv.push(tmp);


//        while (sv.isempty() == false)
//        {
//            sv.pop(tmp);
//            for (int i = 0; i< tmp.size(); i++)
//                cout << " sv[" << i << "] = " << tmp[i] << endl;
//        }

//        Vector<Vector<int>>vv;

//        vv[0][0] = 1; vv[0][1] = 1; vv[0][2] = 1;
//        vv[1][0] = 1; vv[1][1] = 1;
//        vv[2][0] = 1; vv[2][1] = 1;
//        for(int i = 0;i<vv.size();i++)
//        {
//            for(int j = 0;j<vv[i].size();j++)
//                cout<<"vv["<<i<<"]"<<"["<<j<<"]="<<vv[i][j]<<endl;
//        }
//}

//模板具体化

template <class T1,class T2>//模板类
class AA
{
public:
    T1 m_a;
    T2 m_b;
    AA(T1 a, T2 b):m_a(a),m_b(b)
    {
        cout<<"模板构造函数"<<endl;
    }
    void show()const;

};
template<class T1,class T2>
void AA<T1,T2>::show()const
{
    cout<<"模板类：a="<<m_a<<"m_b="<<m_b<<endl;
}

template <class T>
class AA<int, T>
{
public:
    int m_a;
    T m_b;
    AA(int a,T b):m_a(a),m_b(b)
    {
        cout<<"部分具体化构造函数"<<endl;
    }
    void show()const;
};
template <class T>
void AA<int, T>::show()const
{
    cout<<"部分具体：a="<<m_a<<"b="<<m_b<<endl;
}
template <>
class AA<int ,string>
{
public:
    int m_a;
    string m_b;
    AA(int a, string b):m_a(a),m_b(b)
    {
        cout<<"完全具体话构造函数"<<endl;
    }
    void show()const;
};

void AA<int,string>::show()const
{
    cout<<"完全具体:a="<<m_a<<",b="<<m_b<<endl;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    AA<int ,string>aa(18,"dong");
    AA<char,string>bb('d',"dong");
    AA<int ,double>cc(18,20.5);
}
