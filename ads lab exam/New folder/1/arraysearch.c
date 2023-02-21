#include<stdio.h>
void main(){
    int i,n,a[10],s,flag=0;
    printf("enter the size of array: ");
    scanf("%d",&n);
    printf("enter the elements of array:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the element to search: ");
    scanf("%d",&s);
// perform array searching
    for(i=0;i<n;i++){
        if(a[i]==s){
            printf("\nelement found at position %d\t",i);
            flag=flag+1;
            break;
        }

    }
    if(flag==0){
        printf("element no found:");
    }
}