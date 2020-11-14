#pragma  once 

#define kSize 100

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
