#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*top;
void display(struct node*top){
    if(top==NULL){
        printf("****LIST IS EMPTY****\n");
    }
    else{
        while(top!=NULL){
            printf("element:%d\n",top->data);
            top=top->next;
        }
    }
}
void push(int value){
    if(top==NULL){
        top=(struct node*)malloc(sizeof(struct node));
        top->next=NULL;
        top->data=value;
    }
    else{
        struct node*newnode=(struct node*)malloc(sizeof(struct node));
        newnode->next=top;
        newnode->data=value;
        top=newnode;
    }
    
}
void pop(){
    if(top==NULL){
        printf("****LIST IS EMPTY****\n");
    }
    else{
        struct node*ptr=top;
        top=top->next;
        free(ptr);
    }
    
}
int main(){
    int choice,value;
    top=NULL;
    while(1){
        printf("***MENU***\n");
        printf("1.display\n");
        printf("2.push\n");
        printf("3.pop\n");
        printf("4.exit\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        if(choice==1){
            display(top);
        }
        else if(choice==2){
            printf("enter the data you want to push:");
            scanf("%d",&value);
            push(value);
        }
        else if(choice==3){
            pop();
        }
        else{
            exit(1);
        }

    }

}