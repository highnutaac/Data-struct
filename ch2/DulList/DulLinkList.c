#include "DulLinkList.h"
#include <stdio.h>
#include <stdlib.h>

Status InitList(DulLinkList L){
    L->data=0;
    L->next=L->prior=NULL;
    return OK;
}

Status DestoryElem(DulLinkList L,int index,ElemType* e){
    DulLinkList ptr=L;
    int i=0;
    while (i<index) {
        ptr=ptr->next;
        i++;
    }
    *e=ptr->data;
    ptr->next->prior=ptr->prior;
    ptr->prior->next=ptr->next;
    free(ptr);
    ptr=NULL;
    return OK;
}

Status TraverseList(DulLinkList L){
    DulLinkList ptr=L;
    while (ptr!=NULL) {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n\n");
}

int main(void){
    DulLinkList L = (DulLinkList)malloc(sizeof (DulNode));
    InitList(L);
    L->data=1;L->next=L;L->prior=NULL;
    DulNode* new=(DulNode*)malloc(sizeof(DulNode*));
    new->data=2;new->next=NULL;new->prior=L;
    L->next=new;
    DulNode* nnew=(DulNode*)malloc(sizeof(DulNode));
    nnew->data=3;nnew->next=NULL;nnew->prior=new;
    new->next=nnew;
    ElemType e;
    TraverseList(L);
    DestoryElem(L,1,&e);
    TraverseList(L);
    printf("%d\n",e);
}