#include <iostream>
#include <cstring>
#include "header.h"

using namespace std;

void InitList(LinkList &list)
{
    list = new City;
    strcpy(list->name, "");
    list->position.x = list->position.y = 0;
    list->information.area = 0.0;
    list->information.population = 0;
    strcpy(list->information.feature, "");

    list->next = nullptr;
}

void InsertList(LinkList &list, const char *name, const Position position, const Information information)
{
    City *node = new City;
    strcpy(node->name, name);
    node->position = position;
    node->information = information;
    node->next = list->next;
    list->next = node;

}

Position FindByName(const LinkList &list, const char *name)
{
    City *p = list->next;

    while(p != nullptr)
    {
        if(!strcmp(name, p->name))
        {
            return p->position;
        }
        p = p->next;
    }

    cout << "can not find " << name << endl;

    Position tmp;
    tmp.x = tmp.y = 0;
    return tmp;
}

void FreeList(LinkList &list)
{
    for(City *p = list->next; p != nullptr;)
    {
        City *tmp = p;
        p = p->next;
        delete tmp;
    }
}

void ShowMenu()
{
    cout << "         *城市链表*  ";
    cout << "*1)    插入一个城市" << endl;
    cout << "*2)    删除一个城市" << endl;
    cout << "*3)    更新一个城市" << endl;
    cout << "*4)    查找一个城市"<< endl;
    cout << "*5)    显示所有城市" << endl;
    cout << "*6)    退出" << endl;

}

int main(void)
{
    LinkList head;
    InitList(head);

    cout << "Name   Position(x,y) population(unit: w)  area(unit: km^2)  feature" << endl;
    cout << "example: 江苏 0 0  300000      2300    美食丰富" << endl;
    cout << "input: ";
    char name[kSize];
    Position position;
    Information information;

    cin >> name >> position.x >> position.y >> information.population >> information.area >> information.feature;
    InsertList(head, name, position, information);

    char name_wanted[kSize];
    cout << "what city you want to find?";
    cin >> name_wanted;
    FindByName(head, name_wanted);


    FreeList(head);
    delete head;

    return 0;
}
