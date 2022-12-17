#include<stdio.h>

void quicksort(int a[],int first,int last){
    if(first<last){
        int temp;
        int pivot=first;
        int i=first;
        int j=last;
        while(i<j){
            while(a[i]<=a[pivot]){
                i++;
            }
            while(a[j]>a[pivot]){
                j=j-1;
            }
            if(i<j){
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
        temp=a[j];
        a[j]=a[first];
        a[first]=temp;
        
        quicksort(a,first,j-1);
        quicksort(a,j+1,last);
    }
}
int main(){
    int a[]={3,5,4,2,1};
    int n=sizeof(a)/sizeof(int);
    printf("%d\n",n);
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
