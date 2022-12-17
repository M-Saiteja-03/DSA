#include <stdio.h>

int main(void) {
	int n,x,rem,i;
	scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        int count=0;
        scanf("%d",&x);
        while(x!=0){
            rem=x%10;
            if(rem==4){
                count++;
            }
            x=x%10;
        }
        arr[i]=count;
    }
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
	return 0;
}