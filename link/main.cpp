#include <iostream>
#include<windows.h>

using namespace std;

struct student
{
    int age;
    string name;
    struct student* next;
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    struct student* head = nullptr,*tail = nullptr, *tmp = nullptr;

    tmp = new student({23,"孙浩东",nullptr});
    head = tail = tmp;

    tmp = new student({23,"haodong", nullptr});
    tail->next = tmp;
    tail = tmp;

    tmp = new student({24,"Haodong", nullptr});
    tail->next = tmp;
    tail = tmp;

    tmp = head;
    while(head != nullptr)
    {
        cout<<"age:"<<tmp->age<<"name:"<<tmp->name<<"tmp->next:"<<tmp->next<<endl;
        tmp = tmp->next;
    }
    while(head != nullptr)

    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}
