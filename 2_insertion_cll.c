//only insertion at beginning logic changes in circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*head,*first,*second,*third;
void traverse(struct node * head){
    struct node*ptr=head;
    while(ptr->next!=head){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}
struct node*insert_beginning(struct node *head){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=5;
    struct node*rear=head;
    while(rear->next!=head){
        rear=rear->next;
    }
    rear->next=ptr;
    ptr->next=head;;
    head=ptr;
    return head;

}
void insert_middle(struct node *head,int index){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=25;
    struct node*p=head;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;

}
void insert_end(struct node *head){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=50;
    struct node*rear=head;
    while(rear->next!=head){
        rear=rear->next;
    }
    rear->next=ptr;
    ptr->next=head;
}
int main(){
    head=(struct node*)malloc(sizeof(struct node));
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=first;
    first->data=20;
    first->next=second;
    second->data=30;
    second->next=third;
    third->data=40;
    third->next=head;
    printf("before insertion\n");
    traverse(head);
    //head=insert_beginning(head);
    //printf("after insertion\n");
    //traverse(head);
    //insert_middle(head,2);
    printf("after insertion\n");
    insert_end(head);
    traverse(head);
}