#define TRUE    1
#define FALSE   0
#define OK  1
#define ERROR   0
#define INFEASIBLE   -1 
#define OVERFLOW    -2


typedef int Status;
typedef int ElemType;


typedef struct DulNode{
    ElemType data;
    struct DulNode* prior;
    struct DulNode* next;
}DulNode, *DulLinkList;

#include "stdio.h"
#include "stdlib.h"

Status InitList(DulLinkList L);
Status GetElem(DulLinkList L, int i, ElemType* e);
int LocateElem(DulLinkList L, ElemType e, Status compare(ElemType a, ElemType b));//Locate elem.using function compare.
Status ListInsert(DulLinkList L, int i, ElemType e);//Insert elem in i index.
Status TraverseList(DulLinkList L);
Status ListIntersaction(DulLinkList La, DulLinkList Lb, DulLinkList* Lc);
Status DestoryList(DulLinkList L);
Status DestoryElem(DulLinkList L, int index, ElemType* e);
Status NodeNum(DulLinkList L, ElemType value,int* node_num);
Status DelMin(DulLinkList L,ElemType* e);
