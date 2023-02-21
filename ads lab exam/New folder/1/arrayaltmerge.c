#include<stdio.h>
void main()
{
 int a[20],b[20],c[40],i,j,n;
 printf("Enter No. of Elements in  Array : ");
 scanf("%d",&n);
 printf("Enter Elements of 1st Array : ");
 for(i=0;i<n;i++)
 {
  scanf("%d",&a[i]);
 }
 printf("Enter %d Elements of 2nd Array : ",n);
 for(i=0;i<n;i++)
 {
  scanf("%d",&b[i]);
 }

//  array alt merging
for(i=0,j=0;i<n;i++,j=j+2){
    c[j]=a[i];
}
for(i=0,j=1;i<n;i++,j=j+2){
    c[j]=b[i];
}
printf("Arrays after alternate merging:\n");
for(i=0;i<n+n;i++){
    printf("%d\n",c[i]);
}

}