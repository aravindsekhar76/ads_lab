#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*rear=NULL,*front=NULL;

void enqueue(){
    int val;
    printf("enter the value to insert: ");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(front==NULL){
        rear=front=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }

}

void dequeue(){
    if(front==NULL){
        printf("\n QUEUE IS EMPTY!");
    }
    else{
        temp=front;
        printf("%d is deleted",temp->data);
        front=front->next;
        free(temp);

    }
}
void display(){
    if (rear==NULL&&front==NULL)
    {
        printf("\nQUEUE IS EMPTY!\n");
    }
    else{
        temp=front;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void main(){
    int choice;
    while(1){
        printf("\n----QUEUE----");
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        printf("enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: enqueue();
            break;

            case 2: dequeue();
            break;

            case 3: display();
            break;

            case 4: exit(0);
            break;

            default: printf("invalid choice!");
        }
    }
}
