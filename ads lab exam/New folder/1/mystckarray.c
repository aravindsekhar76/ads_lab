#include<stdio.h>
#include<stdlib.h>

int stack[50],i,n,top=-1;

void push(){
    if(top==n-1){
        printf("stack is full! ");
    }
    else{
     int val;
    printf("enter the value to insert: ");
    scanf("%d",&val);
    top=top+1;
    stack[top]=val;
    }
}

void pop(){

    if(top==-1){
        printf("stack is empty");
    }
    else{
        printf("Deleted Element is %d",stack[top]);
        top--;
       /* int temp= stack[top];
        top=top-1;
        printf("%d is deleted", temp);*/
    }
}

void display(){
     for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
     }
     if(top==-1){
        printf("stack is empty!");

     }
     
     }


void main(){
    printf("enter the size of the stack: ");
    scanf("%d",&n);
    int choice;
    while(1){
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: push();
            break;
          
          
        case 2: pop();
            break;

           
        case 3: display();
            break;

           
         case 4: exit(0);
            break;

        
        default: printf("invalid choice");
            break;
        }

    }

}