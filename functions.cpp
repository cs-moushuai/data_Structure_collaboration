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
    cout << "Format:  Name   Position(x,y) population(unit: w)  area(unit: km^2)  feature" << endl;
    cout << "Example: jiangsu 0 0  300000      2300    have delicious food" << endl;
    cout << "input: ";
    char name[kSize];
    Position position;
    Information information;

    cin >> name >> position.x >> position.y >> information.population >> information.area >> information.feature;
    InsertList(list, name, position, information);

}

void ShowMenu()
{
    cout << "         *the list of City*  " << endl;
    cout << "*1)    insert a city" << endl;
    cout << "*2)    delete a city" << endl;
    cout << "*3)    update a city" << endl;
    cout << "*4)    search for a city" << endl;
    cout << "*5)    show all cities in list" << endl;
    cout << "*6)    show cities that are less than D from P(x,y)" << endl;
    cout << "*7)    quit" << endl;

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

void DeleteByName(LinkList &list, const char *name)
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
void DeleteByPosition(LinkList &list, const Position &position)
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

void UpdateByName(LinkList &list, const char *name)
{
    City *res = FindByName(list, name);
    if(!res)
    {
        cout << "can't find it" << endl;
        return;
    }
    cout << "Format:  Name   Position(x,y) population(unit: w)  area(unit: km^2)  feature" << endl;
    cout << "input: ";

    cin >> res->name >> res->position.x >> res->position.y >> res->information.population >> res->information.area >> res->information.feature;
}
void UpdateByPosition(LinkList &list, const Position &position)
{
    City *res = FindByPosition(list, position);
    if(!res)
    {
        cout << "can't find it" << endl;
        return;
    }
    cout << "Format:  Name   Position(x,y) population(unit: w)  area(unit: km^2)  feature" << endl;
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
    system("clear");
    cout << "**************Show all city**************" << endl;
    City *p = list->next;

    int i = 1;
    while(p != nullptr)
    {
        cout << "No." << i++ << endl;
        cout << "Name: " << p->name << endl;
        cout << "Position: " << "(" << p->position.x << "," << p->position.y << ")" << endl;
        cout << "Population: " << p->information.population << "w" << endl;
        cout << "Area: " << p->information.area << "km^2" << endl;
        cout << "Feature: " << p->information.feature << endl;
        cout << endl;

        p = p->next;

    }

}

void OperateCity(LinkList &list, OperateTag operate)
{
    while(1)
    {
        switch(operate)
        {
        case kUpdate:
            cout << "You want to change city (1)by the city name or (2) by the location coordinates" << endl;

            break;
        case kDelete:
            cout << "You want to delete city (1)by the city name or (2) by the location coordinates" << endl;
            break;
        case kFind:
            cout << "You want to find city (1)by the city name or (2) by the location coordinates" << endl;
            break;
        }
        int choice;
        cin >> choice;
        if(choice == 1)
        {
            char name_wanted[kSize];
            switch(operate)
            {
            case kUpdate:
                cout << "Which city do you want to update?  " << endl;
                break;
            case kDelete:
                cout << "Which city do you want to delete?  " << endl;
                break;
            case kFind:
                cout << "Which city do you want to find?  " << endl;
                break;
            }
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
