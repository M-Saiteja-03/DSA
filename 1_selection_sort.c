#include<stdio.h>
int main()
{
    int i,j;
    int a[]={3,35,1,23,11,2};
    int n=sizeof(a)/sizeof(int);
    for (i = 0; i < n-1; i++)
    {
        int min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}