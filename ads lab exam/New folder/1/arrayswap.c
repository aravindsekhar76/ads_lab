#include<stdio.h>
void main(){
    int n,i,temp,a[10],b[10];
    printf("enter the size of  array:");
    scanf("%d",&n);

    printf("\nenter the elements of first array:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nenter the elements of second array:");
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }

// performing swapping
    for(i=0;i<n;i++){
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
    printf("\nAfter swapping\n");
    printf("\n First array: \n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\nSecond array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",b[i]);
    }


}