#include "LinkList.h"

Status InitList(LinkList L) {
    L->data = 0;
    L->next = NULL;
    return OK;
}

Status GetElem(LinkList L, int i, ElemType* e) {
    LinkList ptr = L->next;
    int index = 0;
    while (index < i) {
        ptr = ptr->next;
        index++;
    }
    *e = ptr->data;
    return OK;
}

Status compare(ElemType a, ElemType b) {
    if (a == b) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

int LocateElem(LinkList L, ElemType e, Status compare(ElemType a, ElemType b)) {
    Node* ptr = L->next;
    int index = 0;
    while (ptr->data != e) {
        ptr = ptr->next;
        index++;
    }
    return index;
}

Status ListInsert(LinkList L, int i, ElemType e) {
    int index = 0;
    Node* ptr = L;
    while (index < i) {
        ptr = ptr->next;
        index++;
    }
    LinkList new=(LinkList)malloc(sizeof(Node));
    new->data = e; 
    new->next = ptr->next;
    ptr->next = new;
    return OK;
}

Status TraverseList(LinkList L) {
    Node* ptr = L->next;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return OK;
}

Status DestoryList(LinkList L){
    free(L);
    L=NULL;
    return OK;
}

Status DestoryElem(LinkList L,int index,ElemType* e){
    LinkList ptr=L->next;int i=0;LinkList pre_ptr=L;
    while (i<index) {
        pre_ptr=ptr;
        ptr=ptr->next;
        i++;
    }
    *e=ptr->data;
    pre_ptr->next=ptr->next;
    free(ptr);
    ptr=NULL;
    return OK;

}

Status NodeNum(LinkList L, ElemType value, int *node_num){
    LinkList ptr=L->next;
    *node_num=0;
    while (ptr!=NULL) {
        if (ptr->data==value) {
            (*node_num)++;
        }
        ptr=ptr->next;
    }
    return OK;
}

Status DelMin(LinkList L, ElemType *e){
    LinkList ptr=L->next;
    ElemType min=ptr->data;
    while (ptr!=NULL) {
        if (ptr->data<min) {
            min=ptr->data;
        }
        ptr=ptr->next;
    }
    printf("\n\nmin is %d.\t",min);
    int index=LocateElem(L,min,compare);
    DestoryElem(L,index,&min);
    printf("min is %d.\n",min);
    return OK;
}

int main(void) {
    LinkList L=(LinkList)malloc(sizeof(Node));
    InitList(L);
    ListInsert(L, 0, 1);
    ListInsert(L, 0, 2);
    ListInsert(L, 0, 3);
    ListInsert(L, 0, 4);
    ListInsert(L, 0, 5);
    ElemType e;
    GetElem(L,2,&e);
    printf("\n\n%d.\n",e);
    printf("\n\n%d.\n",LocateElem(L,3,compare));
    TraverseList(L);
    DestoryElem(L,2,&e);
    printf("\n\n\n%d..\n",e);
    TraverseList(L);
    ListInsert(L,4,2);
    ListInsert(L,4,2);
    ListInsert(L,3,3);
    TraverseList(L);
    int node_num;
    NodeNum(L, 3, &node_num);
    printf("node num = %d",node_num);
    DelMin(L, &node_num);
}