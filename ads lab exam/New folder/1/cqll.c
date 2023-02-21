#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *next;
};
 struct node *front=NULL,*rear=NULL,*temp,*newnode;

/* void enqueue(void);
 void dequeue(void);
 void display(void);*/

 void enqueue()
 {
   newnode=(struct node*)malloc(sizeof(struct node));
   if((front==NULL)&&(rear==NULL)){
     printf("Enter data\n");
     scanf("%d",&newnode->data);
     newnode->next=front;
     front=newnode;
     rear=newnode;
   }
   else {
     printf("Enter data\n");
     scanf("%d",&newnode->data);
     rear->next=newnode;
     rear=newnode;
     rear->next=front;
   }
 }


 void dequeue()
 {
   if((front==NULL)&&(rear==NULL))
   {
     printf("Queue is empty\n");
   }
   else if(front==rear){
   free(front);
   front=NULL;
   rear=NULL;
   }
   else{
     temp=front;
     front=front->next;
     free(temp);
     printf("deleted successfully\n");
     temp=front;
     rear->next=front;
 }}


 void display()
 {
   if((front==NULL)&&(rear==NULL))
   {
     printf("Queue is empty\n");
   }
   else{
     temp=front;
       printf("%d\t",temp->data);
       temp=temp->next;
     while(temp!=front){
       printf("%d\t",temp->data);
       temp=temp->next;
     }printf("\n");
   }
 }

  void main()
 {
   int op;
   while(1){
    printf("\n ---CIRCULAR QUEUE---\n");
     printf("\n\nEnter your Option!\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
     printf("Enter your option:");
     scanf("%d",&op);
     switch(op){
       case 1:
              enqueue();
              break;
      case 2:
             dequeue();
             break;
      case 3:
             display();
             break;
      case 4: 
             exit(0);
             break;

      default:printf("Invalid option\n");
             break;
     }
   }
 }