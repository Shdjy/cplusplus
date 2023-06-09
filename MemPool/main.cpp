#include <iostream>
#include<windows.h>
using namespace std;

class Boy
{
public:
    int m_age;
    int m_score;
    static char* m_pool;
    static bool initpool()
    {
        m_pool = (char*)malloc(18);
        if(m_pool == 0)return false;
        memset(m_pool,0,18);
        cout<<"分配了内存池"<<endl;
        return  true;
    }
    static void freepool()
    {
       if(m_pool == 0)
           return;
       free(m_pool);
       cout<<"内存池已释放"<<endl;
    }
    Boy(int age, int score)
    {
        m_age = age;
        m_score = score;
    }
    ~Boy()
    {
        cout<<"调用了析构函数"<<endl;
    }
    void* operator new(size_t size)
    {
       if(m_pool[0] == 0)
       {
           cout<<"分配第一块"<<endl;
           m_pool[0] = 1;
           return m_pool +1;
       }
       if(m_pool[9] == 0)
       {
           cout<<"分配第2块"<<endl;
           m_pool[9] = 1;
           return m_pool + 9;
       }
       void* ptr = malloc(size);
       cout<<"申请的内存地址"<<endl;
       return ptr;
    }
    void operator delete(void* ptr)
    {
        if(ptr == 0)
            return;
        if(ptr == m_pool+1)
        {
            cout<<"释放第一块内存"<<endl;
            m_pool[0] = 0;
            return;
        }
        if(ptr == m_pool+9)
        {
            cout<<"释放二快内存"<<endl;
            m_pool[9] = 0;
            return;
        }
        free(ptr);
    }
};
char* Boy::m_pool = 0;
int main()
{
    SetConsoleOutputCP(CP_UTF8);

    if(Boy::initpool() == false)
    {
        cout<<"内存池初始化失败"<<endl;
        return -1;
    }

    Boy* b1 = new Boy(18,90);
    cout<<"b1的地址是："<<b1<<", 年龄："<<b1->m_age<<",b1的成绩："<<b1->m_score<<endl;
    Boy* b2 = new Boy(18,90);
    cout<<"b2的地址是："<<b2<<", 年龄："<<b2->m_age<<",b2的成绩："<<b2->m_score<<endl;
    Boy* b3 = new Boy(18,90);
    cout<<"b3的地址是："<<b3<<", 年龄："<<b3->m_age<<",b3的成绩："<<b3->m_score<<endl;
    delete b1;
    Boy* b4 = new Boy(18,90);
    cout<<"b4的地址是："<<b4<<", 年龄："<<b4->m_age<<",b4的成绩："<<b4->m_score<<endl;

    delete b2;
    delete b3;
    delete b4;
   Boy::freepool();

    return 0;
}
