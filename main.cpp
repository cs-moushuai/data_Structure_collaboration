#include <iostream>
#include <cstring>
#include <cmath>
#include "header.h"

using namespace std;

int main(void)
{
    LinkList head;
    InitList(head);

    int choice;
    while(1)
    {
        system("clear");
        ShowMenu();
        cout << "your choice: ";
        cin >> choice;
        switch(choice)
        {
        case 1:
            InsertCity(head);
            break;
        case 2:
            DeleteCity(head);
            break;
        case 3:
            UpdateCity(head);
            break;
        case 4:
            FindCity(head);
            break;
        case 5:
            ShowAllCity(head);
            break;
        case 6:
            ShowbyDistanceCity(head);
            break;
        case 7:
            FreeList(head);
            delete head;
            exit(0);
            break;
        default:
            cout << "please input correctly(1-7)" << endl;

        }
        getchar();
        int tmp;
        cout << "按任意键继续";
        tmp = getchar();

    }

    return 0;
}
