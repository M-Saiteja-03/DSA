#include<stdio.h>

int Merge(int A[],int low,int mid,int high){
    int i=low;
    int k=low;
    int j=mid+1;
    int B[100];
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            k++;
            j++;
        }
    }
    while (i<=mid)
    {
        B[k]=A[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        B[k]=A[j];
        j++;
        k++;
    }
    for(i=low;i<=high;i++){
        A[i]=B[i];
    }
    
}
int Mergesort(int A[],int low,int high){
    int invc=0;
    if(low<high){
        int mid=(low+high)/2;
        Mergesort(A,low,mid);
        Mergesort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}
int main()
{
    int A[]={4,1,33,23,55,36};
    int n=sizeof(A)/sizeof(int);
    Mergesort(A,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    
    return 0;
}