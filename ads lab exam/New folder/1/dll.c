#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};
struct node *newnode,*temp,*head=NULL;

int count(){
    int c=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        c++;
    }
    return(c);
}\

void insbeg(){
    int val;
    printf("eneter the data to insert:");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;

}

void insend(){
    if(head==NULL){
        insbeg();
    }
    else{
    int val;
    printf("eneter the data to insert:");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}
}

void inspos(){
    int pos,val;
    printf("enter the pos to insert:");
    scanf("%d",&pos);
    if(pos==1){
        insbeg();
    }
    else if(pos>1 && pos<count()){
        printf("eneter the data to insert:");
        scanf("%d",&val);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=val;
        int c=1;
        temp=head;
        while(c<pos-1){
            temp=temp->next;
            c++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
    }

    void display(){
        if(head==NULL){
            printf("\nLINKED LIST IS EMPTY!\n");
        }
        else{
            temp=head;
            while(temp!=NULL){
                printf("%d\t ",temp->data);
                temp=temp->next;
            }
        }
    }































void main(){
    int choice;
    while(1){
        printf("\n--------------------------------------------\n");
        printf("\n1.Insertion beg\n2.Insertion postion\n3.Insertion end\n4.Display\n5.Deletion beg\n6.Deletion end\n7.Deletion pos\n8.Search\n9.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insbeg();
                    break;
            case 2: inspos();
                    break;
            case 3: insend();
                    break;
            case 4: display();
                    break;
         /*  case 5: delbeg();
                    break;
            case 6: delend();
                    break;
            case 7: delpos();
                    break;
          /* case 8: search();
                    break;*/
            case 9: exit(0);
                    break;
            default: 
                    printf("Invalid Choice");
        }
    }

}