#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node 
{
    int index;
    int position;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct List 
{
    Node *head;
    int count;
}List;

List * initialize()
{
    List *list = malloc(sizeof(List));
    list->head=NULL;
    list->count=0;
    return list;
}
Node * create(int index)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->index=index;
    temp->position=0;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}
void insert_end(List *list , int index)
{
    Node *temp=create(index);
    Node *new=list->head;
    if(list->head==NULL)
    {
        list->head=temp;
        return;
    }
    while(new->next)
        new=new->next;
    new->next=temp;
    temp->prev=new;
    temp->next=NULL;
    
}

void print_solution(List *list)
{
    Node *temp=list->head;
    if(list->head==NULL)
    {
        printf("Empty\n");
        return;
    }
    while(temp)
    {
        printf("%d " , temp->position);
        temp=temp->next;
    }
    printf("\n");
}
int place(List *list ,Node *node)
{
	int pos = node->index;
    Node * temp = list->head;
    for(int i=1;i<pos;i++)
    {
        if((temp->position==node->position)||(abs((temp->position-node->position))==abs((temp->index)-pos)))
        return 0;
        temp=temp->next;
        
    }
    return 1;
}
List * createBoard(List *list ,int n)
{
    int i ;
    for (i = 1 ; i<=n ; i++)
    {
        insert_end(list , i);
    }
    return list;
}

void queen(List * list, int n)
{
    Node * temp = list->head;
    temp->position = 0;
    while(temp->index!=0)
    {
        do
        {
            temp->position++;
        }while((temp->position<=n)&&!place(list , temp));
        if(temp->position<=n)
        {
            if(temp->index==n)
            print_solution(list);
            else
            {
                temp=temp->next;
                temp->position=0;
            }
        }
        else
        {	
			if(temp->prev!=NULL){
            	temp=temp->prev;
			}
			else
				return;
        }
    }
}


void main()
{
    int n;
    List *list = initialize();   
        printf("Enter number of queens");scanf("%d" , &n);
        List *board = createBoard(list , n);
        queen(board , n);
    
}
