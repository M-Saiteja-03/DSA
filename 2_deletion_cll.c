#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
 }*head,*first,*second,*third;
 void traverse(struct node* head){
     struct node* ptr=head;
     while(ptr->next!=head){
         printf("element:%d\n",ptr->data);
         ptr=ptr->next;
     }
     printf("element:%d\n",ptr->data);

}
struct node* delete_beginning(struct node *head){
    struct node*rear=head;
    struct node*ptr=head;
    while(rear->next!=head){
        rear=rear->next;
    }
    rear->next=head->next;
    head=head->next;
    free(ptr);
    return head;
    
}

void delete_index(struct node*head,int index){
    struct node*p1=head;
    struct node*p2=head;
    for(int i=0;i<index;i++){
        p1=p2;
        p2=p2->next;
    }
    p1->next=p2->next;
    free(p2);
}
void delete_end(struct node *head){
    struct node*rear=head;
    struct node*p=head;
    while(rear->next!=head){
        p=rear;
        rear=rear->next;
    }
    p->next=head;
    free(rear);
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
    third->next=head;
    printf("list before deleting in middle\n");
    traverse(head);
    // printf("list after deleting at beginning\n");
    // head=delete_beginning(head);
    // traverse(head);
    // printf("list after deleting at end\n");
    // delete_end(head);
    // traverse(head);
    printf("list after deleting in middle\n");
    delete_index(head,2);
    traverse(head);
    
}