#include <stdio.h>

#include <stdlib.h>



typedef struct node{

char data;

struct node *link;

struct node *prev;

}Node;



typedef struct list{

Node* head;

Node* tail;

int len;

}List;





List* list_initialize()

{

List *list=(List*)malloc(sizeof(List));

list->head=NULL;

list->tail=NULL;

list->len=0;

return list;

}









Node* create_node(char data){

Node* t=(Node*)malloc(sizeof(Node));

t->data=data;

t->link=NULL;

t->prev=NULL;

return t;

}









void append_list(List* list,char s){

Node* temp;

temp=create_node(s);

if(list->head==NULL)

{



list->head=temp;

list->tail=temp;

return;

}

else

{

temp->prev=list->tail;

list->tail->link=temp;

list->tail=temp;



}

++list->len;

}











List* reverse_list(List *list)

{

List* revlist=list_initialize();

Node* cur;

cur=list->tail;

char c;

while(cur){

c=cur->data;

append_list(revlist, c);

cur=cur->prev;

}

return revlist;

}





void check_palin(List *list,List *revlist)

{

Node* p=list->head;

Node* q=revlist->head;

int c=0;

while(p->data==q->data && p->link!=NULL){

c=c+1;

p=p->link;

q=q->link;

}

printf("%d ---%d \n",c,list->len);

if(c==(list->len))

{

    if(p->data==q->data){

    printf("PALINDROME\n");}

else{

printf("NOT PALINDROME\n");}

}

else{

printf("NOT PALINDROME\n");

}



}



void displaylist(List *list)

{

    Node* p=list->head;

    printf("---->");

    if(list->head==NULL)

    {

    printf("EMPTY\n");

    return;

    }

    while(p!=NULL)

    {

    printf("%c ",p->data);

    p=p->link;

    }

}



void destroy(List *lst){

free(lst);

}







int main()

{

int c;char s;int wish=0;



List* list=list_initialize();

List* revlist=list_initialize();

do{



printf(">>>>>>>INDEX>>>>>>\n");

printf("1)create/append to the list\n2)Check palindrome\n");

scanf("%d",&c);

switch (c){

case 1:

printf("element:");

scanf("%s",&s);

append_list(list,s);

displaylist(list);

printf("\n");

break;



case 2:



revlist=reverse_list(list);

displaylist(list);

displaylist(revlist);

check_palin(list,revlist);

break;



default:

printf("Wrong input\n");

break;





}

printf("Do you want to continue?:\n1)yes 0)no\n");

scanf("%d",&wish);





}

while(wish);

destroy(list);

destroy(revlist);

}
