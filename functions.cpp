#include <iostream>
#include <cstring>
#include <cmath>
#include "header.h"

using namespace std;

void InitList(LinkList &list)
{
    list = new City;
    if(!list)
    {
        cerr << "Out of space!" << endl;
        exit(1);
    }
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
    if(!node)
    {
        cerr << "Out of space!" << endl;
        exit(1);
    }
    strcpy(node->name, name);
    node->position = position;
    node->information = information;
    node->next = list->next;
    list->next = node;

}

City *FindByName(const LinkList &list, const char *name)
{
    City *p = list->next;

    while(p != nullptr)
    {
        if(!strcmp(name, p->name))
        {
            return p;
        }
        p = p->next;
    }

    return nullptr;
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

void InsertCity(LinkList &list)
{
    cout << "Name   Position(x,y) population(unit: w)  area(unit: km^2)  feature" << endl;
    cout << "example: 江苏 0 0  300000      2300    美食丰富" << endl;
    cout << "input: ";
    char name[kSize];
    Position position;
    Information information;

    cin >> name >> position.x >> position.y >> information.population >> information.area >> information.feature;
    InsertList(list, name, position, information);

}

void ShowMenu()
{
    cout << "         *城市链表*  " << endl;
    cout << "*1)    插入一个城市" << endl;
    cout << "*2)    删除一个城市" << endl;
    cout << "*3)    更新一个城市" << endl;
    cout << "*4)    查找一个城市" << endl;
    cout << "*5)    显示所有城市" << endl;
    cout << "*6)    显示与P(x,y)距离小于D的城市" << endl;
    cout << "*7)    退出" << endl;

}

City *FindByPosition(const LinkList &list, const Position &position)
{
    City *p = list->next;

    while(p != nullptr)
    {
        if(p->position.x == position.x && p->position.y == position.y)
        {
            return p;
        }
        p = p->next;
    }


    return nullptr;
}


City *FindPriorList(const LinkList &list, City *p)
{
    City *start = list;
    while(start->next != p)
    {
        start = start->next;
    }

    return start;

}

void DeleteByName(const LinkList &list, const char *name)
{
    City *res = FindByName(list, name);
    if(!res)
    {
        cout << "can't find it" << endl;
        return;
    }
    City *prior = FindPriorList(list, res);
    prior->next = res->next;
    delete res;
}
void DeleteByPosition(const LinkList &list, const Position &position)
{
    City *res = FindByPosition(list, position);
    if(!res)
    {
        cout << "can't find it" << endl;
        return;
    }
    City *prior = FindPriorList(list, res);
    prior->next = res->next;
    delete res;
}

void UpdateByName(const LinkList &list, const char *name)
{
    City *res = FindByName(list, name);
    if(!res)
    {
        cout << "can't find it" << endl;
        return;
    }
    cout << "Name   Position(x,y) population(unit: w)  area(unit: km^2)  feature" << endl;
    cout << "input: ";

    cin >> res->name >> res->position.x >> res->position.y >> res->information.population >> res->information.area >> res->information.feature;
}
void UpdateByPosition(const LinkList &list, const Position &position)
{
    City *res = FindByPosition(list, position);
    if(!res)
    {
        cout << "can't find it" << endl;
        return;
    }
    cout << "Name   Position(x,y) population(unit: w)  area(unit: km^2)  feature" << endl;
    cout << "input: ";

    cin >> res->name >> res->position.x >> res->position.y >> res->information.population >> res->information.area >> res->information.feature;
}


bool JudgeByDistance(const Position &lhs, const Position &rhs, int distance)
{
    int value = sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y));

    return value <= distance ? true : false;

}



void ShowbyDistance(const LinkList &list, const Position &position, int distance)
{
    City *p = list->next;

    while(p != nullptr)
    {
        if(JudgeByDistance(p->position, position, distance))
        {
            cout << "Name: " << p->name << endl;
            cout << "Position: " << "(" << p->position.x << "," << p->position.y << ")" << endl;
            cout << "Population: " << p->information.population << endl;
            cout << "Area: " << p->information.area << endl;
            cout << "Feature: " << p->information.feature << endl;

        }

        p = p->next;

    }
}

void ShowbyDistanceCity(const LinkList &list)
{
    Position positon;
    cout << "p(x,y): ";
    cin >> positon.x >> positon.y;
    cout << "D: ";
    int distance;
    cin >> distance;
    ShowbyDistance(list, positon, distance);
}

void ShowAllCity(const LinkList &list)
{
    City *p = list->next;

    int i = 1;
    while(p != nullptr)
    {
        cout << "No." << i++ << endl;
        cout << "Name: " << p->name << endl;
        cout << "Position: " << "(" << p->position.x << "," << p->position.y << ")" << endl;
        cout << "Population: " << p->information.population << endl;
        cout << "Area: " << p->information.area << endl;
        cout << "Feature: " << p->information.feature << endl;
        cout << endl;

        p = p->next;

    }

}

void OperateCity(const LinkList &list, OperateTag operate)
{
    while(1)
    {
        switch(operate)
        {
        case kUpdate:
            cout << "你希望通过城市名更改(1)或位置坐标更改(2)" << endl;

            break;
        case kDelete:
            cout << "你希望通过城市名删除(1)或位置坐标删除(2)" << endl;
            break;
        case kFind:
            cout << "你希望通过(1)城市名查找或(2)位置坐标查找" << endl;
            break;
        }
        int choice;
        cin >> choice;
        if(choice == 1)
        {
            char name_wanted[kSize];
            cout << "what city you want to update?";
            cin >> name_wanted;
            switch(operate)
            {
            case kUpdate:
                UpdateByName(list, name_wanted);
                break;

            case kDelete:
                DeleteByName(list, name_wanted);

            case kFind:
                City *res = FindByName(list, name_wanted);
                if(res == nullptr)
                {
                    cout << "can't find " << name_wanted << endl;

                }
                else
                {
                    cout << "position: (" << res->position.x << "," << res->position.y <<  ")" << endl;
                }
            }
            break;

        }
        else if(choice == 2)
        {
            Position position;
            cout << "input position(eg: 23 34)";
            cin >> position.x >> position.y;
            switch(operate)
            {
            case kUpdate:
                UpdateByPosition(list, position);
                break;
            case kDelete:
                DeleteByPosition(list, position);
                break;
            case kFind:
                City *res = FindByPosition(list, position);
                if(res == nullptr)
                {
                    cout << "can not find (" << position.x << "," << position.y << ")" << endl;

                }
                else
                {
                    cout << "name: " << res->name << endl;
                }
                break;
            }
            break;
        }
        else
        {
            cerr << "please enter 1 or 2!" << endl;
        }
    }

}
