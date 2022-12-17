#include<stdio.h>
void function(void);
int main(){
    int a;
    printf("enter no:\n");
    scanf("%d", &a);
    printf("%d\n",a);
    printf("hello world\n");
    function();
    return 0;
}
void function()
    {
         printf("hello function");
    }