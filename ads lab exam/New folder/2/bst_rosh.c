#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *root=NULL,*newnode,*ptr,*temp,*a,*b;
int i,j;





struct node* creation(int val){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* position(struct node *a,int val){
    if(a->data==val){
        printf("already exists\n");
    }
    else if(val>a->data){
        if(a->right==NULL){
            return a;
        }
        b=position(a->right,val);
    }
    else if(val<a->data){
        if(a->left==NULL){
            return a;
        }
        b=position(a->left,val);
    }
}


void insert(int val){
    if(root==NULL){
        root=creation(val);
    }
    else {
        ptr=position(root,val);
        if(val>ptr->data){
            ptr->right=creation(val);
            if(ptr->right!=NULL){
                printf("Element inserted successfully\n");
            }
        }
        else{
            ptr->left=creation(val);
            if(ptr->left!=NULL){
                printf("Element inserted successfuly\n");
            }
        }
    }
}

void search(struct node *a,int val){
    if(a->data==val){
        printf("element found");
        return;
    }else if(val>a->data){
        if(a->right==NULL){
            printf("Element doesnt exist\n");
        }else{

        search(a->right,val);}
    }
    else{
        if(a->left==NULL){
            printf("Element doesnt exist\n");
        }else{

        search(a->left,val);
    }}
}

void inorder(struct node *a){
    if(a==NULL){
        printf("\t");
    }else{
    inorder(a->left);
    printf("%d\t",a->data);
    inorder(a->right);
}}

void preorder(struct node *a){
    if(a==NULL){
        printf("\t");
    }else{
    printf("%d\t",a->data);
    preorder(a->left);
    preorder(a->right);
}}

void postorder(struct node *a){
    if(a==NULL){
        printf("\t");
    }else{
    postorder(a->left);
    postorder(a->right);
    printf("%d\t",a->data);
}}






void main(){
    int op,val;
    do{
    switch(op){
        case 1:printf("Enter data for new node\n");
               scanf("%d",&val);
               insert(val);
               break;
        case 2:printf("Enter element to search for\n");
               scanf("%d",&val);
               search(root,val);
               break;
        case 3:if(root==NULL)
               {
                printf("Tree is empty\n");
               }
               else{
                inorder(root);
                }
               break;
        case 4:if(root==NULL)
               {
                printf("Tree is empty\n");
               }
               else{
                preorder(root);
                }
               break;
        case 5:if(root==NULL)
               {
                printf("Tree is empty\n");
               }
               else{
                postorder(root);
                }
               break;
        case 6:printf("Exit");
               exit(0);
               break;
    }

printf("\nOptions Available\n1.Insertion\n2.Search\n3.Inorder Traversal\n4.Preorder traversal\n5.Postorder traversal\n6.Exit\n\tENter your choice\t:");
scanf("%d",&op);
}while(op!=6);
}