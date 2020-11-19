#pragma  once

const int kSize = 100;

typedef struct
{
    int population;
    double  area;
    char feature[kSize];
} Information;

typedef struct
{
    int x, y;

} Position;

typedef struct City
{
    char name[kSize];
    Position position;
    Information information;
    struct City *next;


} City, *LinkList;

enum Operate {kFind, kDelete, kUpdate};

void InitList(LinkList &list);
void InsertList(LinkList &list, const char *name, const Position position, const Information information);
City *FindByName(const LinkList &list, const char *name);
void FreeList(LinkList &list);
void InsertCity(LinkList &list);
void ShowMenu();
City *FindByPosition(const LinkList &list, const Position &position);
City *FindPriorList(const LinkList &list, City *p);
void DeleteByName(const LinkList &list, const char *name);
void DeleteByPosition(const LinkList &list, const Position &position);
void UpdateByName(const LinkList &list, const char *name);
void UpdateByPosition(const LinkList &list, const Position &position);
void ShowbyDistance(const LinkList &list, const Position &position, int distance);
void ShowbyDistanceCity(const LinkList &list);
void ShowAllCity(const LinkList &list);
void OperateCity(const LinkList &list, Operate operate);
