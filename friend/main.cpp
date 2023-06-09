#include <iostream>
#include<windows.h>
using namespace std;

//友元函数

//class Girl
//{
//    friend void fun();
//    friend int main();
//public:
//    int m_age;
//    string m_name;
//    Girl()
//    {
//       m_age = 18;
//       m_name = "xioamei";
//       m_weight = 90;
//    }
//    void show()
//    {
//        cout<<"age:"<<m_age<<", name:"<<m_name<<endl;
//    }
//private:
//    int m_weight;
//    void show2()
//    {
//        cout<<"体重："<<m_weight<<endl;
//    }


//};

//void fun()
//{
//   Girl g;
//   g.show();
//   g.show2();

//};

//int main()
//{
//    SetConsoleOutputCP(CP_UTF8);

//    fun();

//    return 0;
//}

//友元类
//   class Girl
//    {
//        friend class Boy;
//    public:
//        int m_age;
//        string m_name;
//        Girl()
//        {
//           m_age = 18;
//           m_name = "xioamei";
//           m_weight = 90;
//        }
//        void show()
//        {
//            cout<<"age:"<<m_age<<", name:"<<m_name<<endl;
//        }
//    private:
//        int m_weight;
//        void show2()const
//        {
//            cout<<"体重："<<m_weight<<endl;
//        }


//    };

//    class Boy
//    {
//    public:
//        void func(const Girl &g)
//        {
//            cout<<"age:"<<g.m_age<<", name:"<<g.m_name<<endl;
//            cout<<"weight:"<<g.m_weight<<endl;
//            g.show2();
//        }
//    };

//    int main()
//    {
//        SetConsoleOutputCP(CP_UTF8);

//        Girl g;
//        Boy b;
//        b.func(g);

//        return 0;
//    }


//友元成员函数
class Girl;

class Boy
{
public:

       void func1(const Girl& g);
       void func2(const Girl& g);
};

class Girl
 {
     friend void Boy::func1(const Girl& g);
     friend void Boy::func2(const Girl& g);
 public:
     int m_age;
     string m_name;
     Girl()
     {
        m_age = 18;
        m_name = "xioamei";
        m_weight = 90;
     }
     void show()
     {
         cout<<"age:"<<m_age<<", name:"<<m_name<<endl;
     }
 private:
     int m_weight;
     void show2()const
     {
         cout<<"体重："<<m_weight<<endl;
     }


 };
void Boy::func1(const Girl& g)
{
    cout<<"age:"<<g.m_age<<", name:"<<g.m_name<<endl;
}
void Boy::func2(const Girl& g)
{
    cout<<"weight:"<<g.m_weight<<endl;
}


 int main()
 {
     SetConsoleOutputCP(CP_UTF8);

     Girl g;
     Boy b;
     b.func1(g);
     b.func2(g);

     return 0;
 }
