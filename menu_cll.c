#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
 }*head,*tail;

void traverse(struct node* head){
    if(head==NULL){
        printf("the list is empty\n");
    }
    else{
        struct node* ptr=head;
        while(ptr->next!=head){
        printf("element:%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("element:%d\n",ptr->data);
    }
}
struct node*insert_beginning(struct node *head){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter the element:");
    scanf("%d",&ptr->data);
    if(head==NULL){

        head=ptr;
        tail=ptr;
        tail->next=head;
    }
    else{
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=ptr;
        ptr->next=head;;
        head=ptr;

    }
    printf("insertion successful\n");
    return head;
}
void insert_middle(struct node *head,int index){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter the element:");
    scanf("%d",&ptr->data);
    struct node*p=head;
    for(int i=0;i<index-1;i++){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;

}
void insert_end(struct node *head){
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    printf("enter the element:");
    scanf("%d",&ptr->data);
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=ptr;
    ptr->next=head;
}
struct node* delete_beginning(struct node *head){
    struct node*ptr=head;
    while(tail->next!=head){
        tail=tail->next;
    }
    tail->next=head->next;
    head=head->next;
    free(ptr);
    return head;

}
delete_index(struct mode*head,int index){
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
    struct node*p=head;
    while(tail->next!=head){
        p=tail;
        tail=tail->next;
    }
    p->next=head;
    free(tail);
}
int main(){
    head=NULL;
    tail=NULL;
    int choice,index;
    while(1){
        printf("*WELCONE TO CLL MENU*\n");
        printf("1.Display\n");
        printf("2.Insert\n");
        printf("3.Delete\n");
        printf("4.end\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        if(choice==1){
            traverse(head);
        }
        else if(choice==2){
            printf("where do you want to insert the element?\n");
            printf("1.beginning\n");
            printf("2.middle\n");
            printf("3.end\n");
            scanf("%d",&choice);
            if(choice==1){
            head=insert_beginning(head);
            }
            else if(choice==2){
                printf("enter the index u want to enter(ASSUMING INDEX STARTS FROM 0):");
                scanf("%d",&index);
                insert_middle(head,index);
            }
            else{
                insert_end(head);
            }
        }
        else if(choice==3){
            printf("where do you want to delete the element?\n");
            printf("1.beginning\n");
            printf("2.middle\n");
            printf("3.end\n");
            scanf("%d",&choice);
            if(choice==1){
            head=delete_beginning(head);
            }
            else if(choice==2){
                printf("enter the index u want to delete(ASSUMING INDEX STARTS FROM 0):");
                scanf("%d",&index);
                delete_index(head,index);
            }
            else{
                 delete_end(head);
            }
        }
        else if(choice==4){
            exit(1);
        }

    }

}