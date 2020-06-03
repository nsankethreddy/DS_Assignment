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


void round_robin(List* list){
display(list);
do{
int n = rand() % 10;
printf("%d\n",n);
if(n%2==1){
int s=delete_front(list);
append_list(list,s);
}
else{
int s=delete_front(list);
}
display(list);
}while(list->head!=NULL);
printf("ALL THE PROCESSES ARE COMPLETED \n");

}
int main(){

List* list=list_initialize();
int ch,s,a=1;
do{

scanf("%d",&ch);
switch (ch){
case 1:
scanf("%d",&s);
append_list(list,s);
break;
case 2:
display(list);
break;
case 3:
round_robin(list);
break;
case 0:
a=0;
}
}while(a);
}







