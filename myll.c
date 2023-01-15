#include<stdio.h>
#include<stdlib.h>
void insertbeg();
void insertend();
void insertpos();
void delbeg();
void delend();
void delpos();
void display();
int count();

struct node{
    int data;
    struct node *next;
}; 

struct node *newnode, *head=NULL;

int count(){
    struct node *temp;
    int c=0;
    temp= head;
    while (temp != NULL)
    {
        temp= temp->next;
        c++;
    }
    return(c);
}
void insertbeg(){
   int val;
   printf("enter the value: ");
   scanf("%d",&val);
   newnode=  (struct node*)malloc(sizeof(struct node));
   newnode->data= val;
   newnode->next= head;
   head= newnode;
}

void display()
{
    struct node *temp;
    if(head== NULL){
        printf("\n linked list is empty");
    }
    else{
        temp=head;
        while (temp!= NULL)
        {
            printf("%d\t ", temp->data);
            temp=temp->next;
        }
        
    }
}
void insertend(){
    struct node *temp;
    int val;
    if(head==NULL){
        insertbeg();
    }
    else{
        printf("enter the value: ");
        scanf("%d",&val);
        newnode= (struct node*)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insertpos(){
    int pos,val;
    struct node*temp;
    printf("enter the position: ");
    scanf("%d",&pos);
    
    if(pos==1){
        insertbeg();
    }
    else if(pos>1 && pos<= count()){
        printf("enter the value: ");
        scanf("%d",&val);
        newnode= (struct node* )malloc(sizeof(struct node));
        newnode->data=val;
        temp=head;
        int i=1;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
     }
     else if(pos==count()+1){
        insertend();
     }
     else{
        printf("invalid position");
     }
}
void delbeg(){
    if(head==NULL){
        printf("linked list is empty");
    }
    else{
        struct node *temp;
        temp=head;
        head=head->next;
        printf("%d deleted",temp->data);
    }

}

void delend(){
    if(head==NULL){
        printf("linked list is empty");

    }
    else {
        struct node *temp;
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
    printf("%d is deleted",temp->next->data);
    temp->next=NULL;

    }
}
void delpos(){
    int pos,i;
    struct node *temp;

        printf("enter the position: ");
        scanf("%d",&pos);
        if(i==1){
            delbeg();

        }
        else if (pos>1 && pos< count())
        {
           temp=head;
           i=1;
           while(i=pos-1){
            temp=temp->next;
            i++;
           }
           printf("%d is deleted",temp->next->data);
           temp->next=temp->next->next;
        }
        else if(pos==count()){
            delend();

        }
        
}
void search(){
    struct node *temp;
    int element, count=1,flag=0;
    printf("enter the element to search: ");
    scanf("%d",&element);
    temp=head;
    while (temp!=NULL)
    {
    if(temp->data==element){
        flag=1;
        printf("element found at position %d",count);
    }
    count++;
    temp=temp->next;
    }
    if(flag!=1){
        printf("element not found");
    }
}
    
void main(){
    int choice;
    while(1){
        printf("\n--------------------SINGLY LINKED LIST------------------------\n");
        printf("\n1.insert at beginning\n2.insert at end\n3.insert at position\n4.display\n5.delete beginning\n6.delete end\n7.delete position\n8.Search element\n9.Exit\n");
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: insertbeg();
            break;
        
        case 2: insertend();
            break;
        
        case 3: insertpos();
            break;
        
        case 4: display();
            break;
        case 5: delbeg();
            break;

        case 6: delend();
            break;

        case 7: delpos();
            break;

        case 8: search();
            break;

        case 9: exit(0);
            break;

        default: 
            printf("invald choice");
        }
    }
}