#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
int data;
struct Node *next;
}Node;

typedef struct list{
Node *head;
int len;
}List;

List* list_initialize(){
List* lst=(List*)malloc(sizeof(List));
lst->head=NULL;
lst->len=0;
return lst;
}

Node* create_node(int data){
Node* t=(Node*)malloc(sizeof(Node));
t->data=data;
t->next=NULL;
return t;
}


void append_list(List* list,int s){
Node* temp;
temp=create_node(s);
Node* p=list->head;
Node* q;
if(list->head==NULL)
{
list->head=temp;
return;
}
else
{
while(p)
{
q=p;
p=p->next;
}
q->next=temp;
return;
}
++list->len;
}

int delete_front(List* list){
Node* p=list->head;
if(list->head==NULL){

}
list->head=p->next;
int i=p->data;
free(p);
--list->len;
return i;
}

void display(List *list)
{
    Node* p=list->head;
    printf("-->");
    if(list->head==NULL)
    {
    printf("EMPTY\n");
    return;
    }
    while(p!=NULL)
    {
    printf("%d ",p->data);
    p=p->next;
    }
printf("\n");
}



List* intersect(List* list1,List* list2){
List* res=list_initialize();
Node* p=list1->head;
Node* q=list2->head;
while(p)
{
while(q){
if (p->data==q->data){
int s=p->data;
append_list(res,s);
}
q=q->next;
}
q=list2->head;
p=p->next;
}
return res;

}




int main(){

List* list1=list_initialize();
List* list2=list_initialize();
List* res;
int ch,s,a=1;
do{

scanf("%d",&ch);
switch (ch){
case 1:
scanf("%d",&s);
append_list(list1,s);
break;
case 2:
scanf("%d",&s);
append_list(list2,s);
break;
case 3:
res=intersect(list1,list2);
display(res);
break;
case 0:
a=0;
}
}while(a);
}
