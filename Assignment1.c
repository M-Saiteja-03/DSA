#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
}*head,*first,*X,*third,*fourth;

void traverse(struct node* ptr){
     while(ptr!=NULL){
         printf("element:%d\n",ptr->data);
         ptr=ptr->next;
     }
}
void Insert(struct node*X){
    int temp_data,temp_address;
    struct node*Y=(struct node*)malloc(sizeof(struct node));
    Y->data=25; //d is 25 and Y is the node to be inserted before X.
    Y->next=X->next;
    X->next=Y;
    //code to swap the data
    temp_data=X->data;
    X->data=Y->data;
    Y->data=temp_data;
    //code to swap address
    temp_address=X;
    X=Y;
    Y=temp_address;

}
int main(){
    head=(struct node*)malloc(sizeof(struct node));
    first=(struct node*)malloc(sizeof(struct node));
    X=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=first;
    first->data=20;
    first->next=X;
    X->data=30;      //dj=30
    X->next=third;
    third->data=40;
    third->next=fourth;
    fourth->data=50;
    fourth->next=NULL;
    printf("list when Y is not inserted\n");
    traverse(head);
    printf("list when Y is inserted\n");
    Insert(X);
    traverse(head);
}
