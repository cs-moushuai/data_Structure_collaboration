//只能被包含一次
#pragma  once

//最大长度, constexpr是const的强化版,可以在编译期得到结果
constexpr int kSize = 100;

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

//类内包含两个用户自定义成员,及一个char类型,和一个指针类型
typedef struct City
{
    char name[kSize];
    Position position;
    Information information;
    struct City *next;


} City, *LinkList;

//枚举类型, 接受一个参数在kFind, kDelete, kUpdate之间
enum OperateTag {kFind, kDelete, kUpdate};

void InitList(LinkList &list);
void InsertList(LinkList &list, const char *name, const Position position, const Information information);
City *FindByName(const LinkList &list, const char *name);
void FreeList(LinkList &list);
void InsertCity(LinkList &list);
void ShowMenu();
City *FindByPosition(const LinkList &list, const Position &position);
City *FindPriorList(const LinkList &list, City *p);
void DeleteByName(LinkList &list, const char *name);
void DeleteByPosition(LinkList &list, const Position &position);
void UpdateByName(LinkList &list, const char *name);
void UpdateByPosition(LinkList &list, const Position &position);
void ShowbyDistance(const LinkList &list, const Position &position, int distance);
void ShowbyDistanceCity(const LinkList &list);
void ShowAllCity(const LinkList &list);
void OperateCity(LinkList &list, OperateTag operate);
