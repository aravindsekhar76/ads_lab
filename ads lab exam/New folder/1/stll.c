#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *newnode,*temp,*top=NULL;

void push(){
    int val;
    printf("enter the data to insert: ");
    scanf("%d",&val);
    newnode=(struct node*)malloc (sizeof(struct node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;

}
void display(){
    if(top==NULL){
        printf("STACK IS EMPTY");
    }
    else{
        temp=top;
        while(temp!=NULL){
            printf("\n %d\n",temp->data);
            temp=temp->next;
        }
    }
}

void pop(){
    if(top==NULL){
        printf("STACK IS EMPTY");
    }
    else{
        temp=top;
        top=top->next;
        printf("%d is deleted ",temp->data);
        free(temp);
    }
}

void peek(){
    if(top==NULL){
        printf("STACK IS EMPTY");
    }
    else{
        printf(" the top element is %d",top->data);
    }
}

void main(){
	int choice;
	while(1){
		printf("\n---------STACK--------------\n");
		printf("\n1.Push\n2.Pop\n3.Traversal \n4.Peek \n5.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
            case 4: peek();
				break;
			case 5: exit(0);
				break;
			default: printf("\nInvalid choice");
		}
	}
}