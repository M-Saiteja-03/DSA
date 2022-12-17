#include<stdio.h>
int binary_search(int arr[],int x,int length){
    int low=0;
    int high= length-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(x<arr[mid]){
            high=mid-1;
        }
        else if(x>arr[mid]){
            low=mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
    

}
int main()
{
    int arr[10]={10,20,30,40,50,60,70,80,90,100};
    int length  = sizeof(arr)/sizeof(int);
    int x=50;
    int index=binary_search(arr,x,length);
    if(index!=-1){
        printf("found at %d",index);
    }
    else{
        printf("not found");
    }


}