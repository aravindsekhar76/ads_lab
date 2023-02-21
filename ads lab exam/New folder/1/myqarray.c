#include<stdio.h>
#include<stdlib.h>   
void insert();  
void delete();  
void display();  
int front = -1, rear = -1, n;  
int queue[50];  
void main ()  
{  
    int choice;  
    printf("Enter the max n of queue : ");
    scanf("%d", &n);
    while(choice != 4)   
    {             
        printf("\n-----------------QUEUE------------------------------------\n");  
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");  
        printf("\nEnter your choice : ");  
        scanf("%d",&choice); 
        switch(choice)  
        {  
            case 1:  
            {	insert();  
            	break;  
            }
	    case 2:  
            {	delete();  
            	break;
	    }  
            case 3: 
            {	display();  
           	break;  
            }
	    case 4:  
            {	
                exit(0);  
            	break;  
            }
	    default:   
            printf("\nPlease Enter a Valid Choice!\n");  
        }  
    }   
}  
void insert()  
{  
    int item; 
       
    if(rear == n-1)  
    {  
        printf("\nQUEUE IS FULL\n");  
        return;  
    }
    printf("\nEnter the element : ");  
    scanf("\n%d",&item);   
    if(front == -1 && rear == -1)  
    {  
        front = 0;  
        rear = 0;  
    }  
    else   
    {  
        rear = rear+1;  
    }  
    queue[rear] = item;  
    printf("\n%d is inserted.", item);  
          
}  
void delete()  
{  
    int item;   
    if (front == -1 || front > rear)  
    {  
        printf("\nQUEUE IS EMPTY\n");  
        return;  
              
    }  
    else  
    {  
        item = queue[front];  
        if(front == rear)  
        {  
            front = -1;  
            rear = -1 ;  
        }  
        else   
        {  
            front = front + 1;  
        }  
        printf("\n%d is deleted.", item);  
    }  
          
}  
          
void display()  
{  
    int i;  
    if(rear == -1)  
    {  
        printf("\nEMPTY QUEUE\n");  
    }  
    else  
    {   printf("\nThe Queue is \n");  
        for(i=front;i<=rear;i++)  
        {  
            printf("\n%d",queue[i]);  
        }     
    }  
}  
