
#include<stdio.h>
#include<stdlib.h>

void insbeg();
void inspos();
void insend();
void delbeg();
void delend();
void delpos();
void search();
int count();

struct node {
    int data;
    struct node *next;
};

struct node *newnode, *head=NULL;

int count(){
    struct node *temp;
    int c = 0;
    temp = head;
    while(temp != NULL){
        temp = temp->next;
        c++;
    }
    return(c);
}
void insbeg() {
    int val;
    printf("Enter the value : ");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
}

void traversal(){
    struct node *temp;
    // printf("count = %d",count());
    if(head == NULL){
        printf("Linked List empty");
    }
    else{
        temp = head;
        while(temp!= NULL){
            printf("%d\n",temp->data);
            temp = temp->next;
        }
    }
}
void insend(){
    struct node *temp;
    int val;
    if(head == NULL){
        insbeg();
    }
    else{
        printf("Enter the value : ");
        scanf("%d", &val);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}



void inspos(){
    int pos, val;
    struct node *temp;
    printf("Enter position : ");
    scanf("%d", &pos);
    if(pos == 1){
        insbeg();
    }
    else if(pos > 1 && pos <= count()){
        printf("Enter the value:");
        scanf("%d", &val);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        temp = head;
        int i = 1;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    else if(pos == (count()+1)){
        insend();
    }
    else{
        printf("Invalid position");
    }
    
}
void delbeg(){
    if(head == NULL){
        printf("Linked List empty");
    }
    else{
        struct node *temp;
        temp = head;
        head = head->next;
        printf("%d is deleted", temp->data);
    }
}

void delend(){
    if(head == NULL){
        printf("Linked List empty");
    }
    else if(head->next == NULL){
        printf("%d is deleted", head->data);
        head = NULL;
    }
    else{
        struct node *temp;
        temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        printf("%d is deleted", temp->next->data);
        temp->next = NULL;
    }
}
void delpos(){
    int pos,i;
    struct node *temp;
    printf("Enter the position to delete : ");
    scanf("%d", &pos);
    if(pos == 1){
        delbeg();
    }
    else if(pos > 1 && pos < count()){
        temp = head;
        i = 1;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        printf("%d is deleted", temp->next->data);
        temp->next = temp->next->next;
    }
    else if(pos == count()){
        delend();
    }
    else{
        printf("Invalid position");
    }
}

void search(){
    int e, f=0;
    struct node *temp;
    printf("Enter the element to be searched : ");
    scanf("%d", &e);
    temp = head;
    while(temp != 0){
        if(temp->data == e){
            printf("\nElement found");
            f = 1;
            break;
        }
        temp = temp->next;
    }
    if(f == 0){
        printf("Element not found");
    }
}

void main(){
    int choice;
    while(1){
        printf("\n--------------------------------------------\n");
        printf("\n1.Insertion beg\n2.Insertion postion\n3.Insertion end\n4.Traversal\n5.Deletion beg\n6.Deletion end\n7.Deletion pos\n8.Search\n9.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: insbeg();
                    break;
            case 2: inspos();
                    break;
            case 3: insend();
                    break;
            case 4: traversal();
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
                    printf("Invalid Choice");
        }
    }

}
