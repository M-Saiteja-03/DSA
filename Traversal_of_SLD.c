#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
}*head,*second,*third;

void Traverse(struct node*ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}
void Insert(struct node*ptr){
    while(ptr!=NULL){
        printf("Element:%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=NULL;

    Traverse(head);

    return 0;
}