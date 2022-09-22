#define TRUE    1
#define FALSE   0
#define OK  1
#define ERROR   0
#define    INFEASIBLE   -1 
#define OVERFLOW    -2
#define LIST_INIT_SIZE  10
#define LIST_INCREASE_SIZE  2

typedef int Status;
typedef int ElemType;
typedef struct{
    ElemType* head;// head ptr for struct
    int length;// length of List now
    int listsize;// storge value
}SqList;

#include "stdio.h"
#include "stdlib.h"

Status InitList(SqList* L);// Init SqList
Status GetElem(SqList L,int i,ElemType* e);// Get elem value by e
int LocateElem(SqList L,ElemType e,Status (compare(ElemType a,ElemType b)));//Locate elem.using function compare.
Status ListInsert(SqList* L,int i,ElemType e);//Insert elem in i index.
Status TraverseList(SqList L);
Status ListIntersaction(SqList La,SqList Lb,SqList* Lc);



