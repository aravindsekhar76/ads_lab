#include<stdio.h>
void main(){
    int n,i,j,temp;
    printf("\nenter the size of the array:");
    scanf("%d",&n);
    int a[n];
    printf("\nenter the elments of array: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Array before sorting: \n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    // to perform sorting

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){

                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\nArray after sorting: \n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}