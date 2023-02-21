#include<stdio.h>
void main(){
    int i,m,n;
    printf("\nenter the size of first array:");
    scanf("%d",&m);
    printf("\nenter the size of second array:");
    scanf("%d",&n);
    int a[m],b[n],c[m+n];

    printf("\nenter the elements of first array: ");
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    printf("\nenter the elements of second array: ");
    for(i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
// to perform merging
    for(i=0;i<m;i++){
        c[i]=a[i];
    }
    for(i=0;i<n;i++){
        c[i+m]=b[i];
    }
    printf("\narrays after merging: ");
    for(i=0;i<m+n;i++){
        printf("%d\n",c[i]);
    }


}