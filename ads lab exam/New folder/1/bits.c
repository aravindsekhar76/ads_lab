#include<stdio.h>
void main(){
    int u[10],a[10],b[10],n,m,o,i,j,uni[10],inter[10],diff[10],s[10],t[10],p[10];

    printf("enter the no of elements in universal set:");
    scanf("%d",&n);
    printf("enter the elements:");
    for(i=0;i<n;i++){
        scanf("%d",&u[i]);
    }

    printf("enter the no of elements in set A:");
    scanf("%d",&m);
    printf("enter the elements:");
    for(i=0;i<m;i++){
        scanf("%d",&a[i]);
    }

    printf("enter the no of elements in set B:");
    scanf("%d",&o);
    printf("enter the elements:");
    for(i=0;i<o;i++){
        scanf("%d",&b[i]);
    }

// bits of A
    for(i=0;i<n;i++)
    {
        int count=0;
        for(j=0;j<m;j++)
        {
            if(a[j]==u[i])
            {
                count++;
            }
        }
            if(count>0)
            {
                s[i]=1;
            }
            else
            {
                s[i]=0;
            }   
    }
     printf("bitstring of A is: \n[");
     for(i=0;i<n;i++){
        printf("%d,",s[i]);
     }
     printf("]");

    //  bits of B
        for(i=0;i<n;i++){
            int count=0;
            for(j=0;j<o;j++)
            {
                if(b[j]==u[i])
                {
                    count++;
                }
            }
            if(count>0){
                t[i]=1;
            }
            else{
                t[i]=0;
            }

        }
        printf("\nbitsring of B is: \n[");
        for(i=0;i<n;i++){
            printf("%d,",t[i]);
        }
        printf("]");

// to find union
    for(i=0;i<n;i++){
        if(s[i]==1 ||t[i]==1){
            uni[i]=1;
        }
        else{
            uni[i]=0;
        }
    }
    printf("\nthe union of sets A and B is:\n [");
    for(i=0;i<n;i++){
        printf("%d,",uni[i]);
    }
    printf("]");

// to find intersection
    for(i=0;i<n;i++){
        if(s[i]==1 && t[i]==1){
            inter[i]=1;
        }
        else{
            inter[i]=0;
        }
    }
    printf("\nthe intersection of sets A and B is:\n[ ");
    for(i=0;i<n;i++){
        printf("%d,",inter[i]);
    }
    printf("]");
// to find difference
for(i=0;i<0;i++){
    if(t[i]==1){
        p[i]=0;
    }
    else{
        p[i]=1;
    }
}
for(i=0;i<n;i++){
    if(p[1]==1 && s[i]==1){
        diff[i]=1;
    }
    else{
        diff[i]=0;
    }
}
printf("The set difference is:\n[");
for(i=0;i<n;i++){
    printf("%d,",diff[i]);
}
printf("]");
}
