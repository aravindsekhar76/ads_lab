#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};

 struct node *newnode, *temp ,*head=NULL;

int count(){
    int c=0;
    temp=head;
    while ((temp!=NULL))
    {
        temp=temp->next;
        c++;

    }
    return(c);
}

void insbeg(){
    int val;
    printf("enter the data: ");
    scanf("%d",&val);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=head;
   // head->prev=newnode;//
    newnode->prev=NULL;
    head=newnode;

}

void insend(){
    if(head==NULL){
        insbeg();

    }
    else{
        int val;
        printf("enter the value :");
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
    printf("enter the position: ");
    scanf("%d",&pos);
    if(pos==1){
        insbeg();
    }
    else if(pos>1 && pos< count()) {
        printf("enter the data to add:");
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
        newnode->prev=temp;
        temp->next=newnode;

    }
}
void display(){
    if(head==NULL){
        printf("\nlist is empty");
    }
    else{
        temp=head;
        while (temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        
    }

}

void delbeg(){
     if(head==NULL){
        printf("list is empty");
     }
     else{
        temp=head;
        head=head->next;
        printf("%d is deleted",temp->data);
        free(temp);
     }
}

void delend(){
    if(head==NULL){
        printf("\n list is empty");
    }
    else if(head->next==NULL){
        printf("%d is deleted",head->data);
        head=NULL;

    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        printf("%d is deleted",temp->next->data);
        temp->next=NULL;


    }
}

void delpos(){
    int pos;
    printf("enter the position: ");
    scanf("%d",&pos);
    if(pos==1){
        delbeg();

    }
    else if(pos>1 && pos< count()){
        temp=head;
        int i=1;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        temp->next=temp->next->next;
    }
    else if(pos==count()){
        delend();

    }
    else{
        printf("invalid position");
    }
}
/*void search(){
    temp=head;
    int val,flag=0,count=1;
    printf("enter the elemnet to search:");
    scanf("%d",&val);
    temp=head;
    while(temp!=NULL){
        if(val==temp->data){
            flag=1;
            printf("element found at position %d",count);
            
        }
        count++;
        temp= temp->next;
    }
    if(flag!=1){
        printf("element not found: ");
    }


}*/


void main(){
    int choice;
    while(1){
        printf("\n-----------------DOUBLY LINKED LIST---------------------------\n");
        printf("\n1.Insertion beg\n2.Insertion postion\n3.Insertion end\n4.Display\n5.Deletion beg\n6.Deletion end\n7.Deletion pos\n8.Search\n9.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1: insbeg();
                    break;
            case 2: inspos();
                    break;
            case 3: insend();
                    break;
            case 4: display();
                    break;
            case 5: delbeg();
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