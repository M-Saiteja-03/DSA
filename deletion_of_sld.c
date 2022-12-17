#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
 }*head,*first,*second,*third;
 void traverse(struct node* ptr){
     while(ptr!=NULL){
         printf("element:%d\n",ptr->data);
         ptr=ptr->next;
     }

}
struct node* delete_beginning(struct node *head){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node* delete_end(struct node *head){
    struct node*p1=(struct node*)malloc(sizeof(struct node));
    struct node*p2=(struct node*)malloc(sizeof(struct node));
    p1=head;
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        printf("There is only one element left\n");
        return NULL;
    }
    while(p1->next!=NULL){
        p2=p1;
        p1=p1->next;
    }
    p2->next=NULL;
    free(p1);
}
struct node* delete_index(struct node *head,int index){
    struct node*p1=(struct node*)malloc(sizeof(struct node));
    struct node*p2=(struct node*)malloc(sizeof(struct node));
    p1=head;
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        printf("There is only one element left\n");
        return NULL;
    }
    for(int i=0;i<index-1;i++){
        p2=p1;
        p1=p1->next;
    }
    p2->next=p1->next;
    p1->next=NULL;
    free(p1);
}
struct node* delete_value(struct node *head,int value){
    struct node*p1=(struct node*)malloc(sizeof(struct node));
    struct node*p2=(struct node*)malloc(sizeof(struct node));
    p1=head;
    p2=head;
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        printf("There is only one element left\n");
        return NULL;
    }
    if(p1->data==value){
        p1->next==NULL;
        head=head->next;
        free(p1);
      }
    else{
        while(p1->data!=value && p1->next!=NULL){
        p2=p1;
        p1=p1->next;
        }
        if(p1->data==value){
            p2->next=p1->next;
            p1->next=NULL;
            free(p1);
            return head;
        }
        else{
            printf("NOT FOUND\n");
        }
    return head;
    }
}
    
int main()
{
    head=(struct node*)malloc(sizeof(struct node));
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=20;
    head->next=first;
    first->data=30;
    first->next=second;
    second->data=40;
    second->next=third;
    third->data=50;
    third->next=NULL;
    //traverse(head);
    // printf("list after deleting at beginning\n");
    // head=delete_beginning(head);
    traverse(head);
    // printf("list after deleting at end\n");
    // delete_end(head);
    // traverse(head);
    // printf("list after deleting in middle\n");
    // delete_index(head,1);
    // traverse(head);
    printf("list after deleting the value\n");
    head=delete_value(head,1000);
    traverse(head);

}