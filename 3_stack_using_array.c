#include<stdio.h>
#include<stdlib.h>
int size;
int top=-1;
void display(int stack[size]){
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

void push(int stack[size],int value){
    if(top+1>=size){
        printf("stack overflow\n");
        exit(1);
    }
    else{
        top=top+1;
        stack[top]=value;
        printf("%d",top);
    }
}
void pop(int stack[size]){
    if(top<=-1){
        printf("stack underflow");
        exit(1);
    }
    else{
        top-=1;
    }
}
int main(){
    int choice;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    int stack[size];
    while(1){
        printf("****MENU****\n");
        printf("1.Push\n2.Pop\n3.Display\n4.exit\n");
        printf("enter your choice:\n");
        scanf("%d",&choice);
        if(choice==1){
            int value;
            printf("enter the value you want to push:");
            scanf("%d",&value);
            push(stack,value);
        }
        else if(choice==2){
            pop(stack);
        }
        else if(choice==3){
            display(stack);
        }
        else{
            exit(1);
        }
    }
    
}