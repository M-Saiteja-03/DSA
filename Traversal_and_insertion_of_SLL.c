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
struct node* insert_beginning(struct node * head){
    printf("in1 :%d\n",head);
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=10;
    ptr->next=head;
    head->data=100;
    return ptr;
 }
/*void insert_middle(struct node*p,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=45;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
}*/
// void insert_end(struct node *p){
//     struct node*ptr=(struct node*)malloc(sizeof(struct node));
//     ptr->data=60;
//     while(p->next!=NULL){
//         p=p->next;
//     }
//     p->next=ptr;
//     ptr->next=NULL;
// }

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
    printf("list before inserting at beginning\n");
    traverse(head);
    printf("list after inserting at beginning\n");
    printf("before:%d\n",head);
    head=insert_beginning(head);
    printf("after:%d\n",head);
    traverse(head);
    // printf("list after inserting at middle\n");
    // insert_middle(head,3);

    // printf("list after inserting at end\n");
    // insert_end(head);
    // traverse(head);
}