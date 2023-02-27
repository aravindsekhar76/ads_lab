#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root=NULL, *ptr,*newnode,*temp,*b,*d;

struct node *createnode(int val){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node *position(struct node *temp,int val){
    if(val==temp->data){
        printf("element already exist");
    }
    else if(val>temp->data){
        if(temp->right==NULL){
            return temp;
        }
        b=position(temp->right,val);
    }
    else{
        if(temp->left==NULL){
            return temp;
        }
        b= position(temp->left,val);
    }
}


void insertion(int val){
    if(root==NULL){
        root=createnode(val);
    }
    else{
        ptr=position(root,val);
        if(val>ptr->data){
            ptr->right=createnode(val);
            if(ptr->right!=NULL){
                printf("\n%d inserted sucessfully",val);
            }
        }
        else{
            ptr->left=createnode(val);
            if(ptr->left!=NULL){
                printf("\n%d inserted sucessfully",val);
            }
        }
        
    }
}
void search(struct node *temp,int val){
    if(val==temp->data){
        printf("\nelement found");
        return;
    }
    else if(val>temp->data){
        if(temp->right==NULL){
            printf("\nelement doenst exist");
        }
        else{
            search(temp->right,val);
        }
    }
    else{
        if(temp->left==NULL){
            printf("\n element doesnt exist");
        }
        else{
            search(temp->left,val);
        }
    }
}
void inorder(struct node  *temp){
    if(temp==NULL){
        printf(".");
    }
    else{
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
    
}
void preorder(struct node *temp){
    if(temp==NULL){
        printf(".");
    }else{
        printf("%d\t",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}
void postorder(struct node *temp){
    if(temp==NULL){
        printf(".");
    }else{
        postorder(temp->left);
        postorder(temp->right);
        printf("%d\t",temp->data);
    }
}

/*void deletenode(struct node *temp,int val){
    if(temp==NULL){
        return temp;
    }
    if(val>temp->data){
        temp->right=deletenode(temp->right,val);
    }
    else if(val<temp->data){
        temp->left=deletenode(temp->left,val);
    }
    else{
        if(temp->left==NULL){
            d=temp->right;
            free(temp);
            return d;
        }
    else if(temp->right==NULL){
            d=temp->left;
            free(temp);
            return d;
        }
    }
    return temp;

}*/




void main(){
    int val,choice;
    while(1){
        printf("\n----BST---");
        printf("\n1.Insertion\n2.search\n3.Inorder traversal\n4.preorder traversal\n5.postorder traversal\n6.deletion\n7.exit\n");
        printf("\nEnter your choice:\t ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("\nenter the data to insert: \t");
                scanf("%d",&val);
                insertion(val);
                break;
        case 2: printf("\n enter the element to search: ");
                scanf("%d",&val);
                search(root,val);
                break;
        case 3: if(root==NULL){
                 printf("\ntree is empty");
                }else{
                    inorder(root);
                }break;
        case 4: if(root==NULL){
                printf("\n tree is empty");
                }else{
                    preorder(root);
                }break;
        case 5: if(root==NULL){
                printf("\n tree is empty");
                }else{
                    postorder(root);
                }
                break;
        /*case 6: printf("enter the value to delete:");
                scanf("%d",&val);
                deletenode(root,val);
                break;*/
        case 7: printf("\n GOOD BYE ");
                exit(0);
                break;
        default:printf("\nInvalid choice");
                
        }


    }
}