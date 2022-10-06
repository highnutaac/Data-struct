#define TRUE    1
#define FALSE   0
#define OK  1
#define ERROR   0
#define INFEASIBLE   -1 
#define OVERFLOW    -2


typedef int Status;
typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node* next;
}Node, *LinkList;


typedef struct DulNode{
    ElemType data;
    struct DulNode* prior;
    struct DulNode* next;
}DulNode, *DulLinkList;

#include "stdio.h"
#include "stdlib.h"

Status InitList(LinkList L);
Status GetElem(LinkList L, int i, ElemType* e);
int LocateElem(LinkList L, ElemType e, Status compare(ElemType a, ElemType b));//Locate elem.using function compare.
Status ListInsert(LinkList L, int i, ElemType e);//Insert elem in i index.
Status TraverseList(LinkList L);
Status ListIntersaction(LinkList La, LinkList Lb, LinkList* Lc);
Status DestoryList(LinkList L);
Status DestoryElem(LinkList L, int index, ElemType* e);
Status NodeNum(LinkList L, ElemType value,int* node_num);
Status DelMin(LinkList L,ElemType* e);
