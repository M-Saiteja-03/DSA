#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node* insert(int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return(newnode);
}

void Preorder(struct node*root){
    if(root!=NULL){
        printf("%d ",root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}
void Inorder(struct node*root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
void Postorder(struct node*root){
    if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
    }
}
int main()
{   
    struct node*root=insert(1);
    root->left=insert(2);
    root->right=insert(3);
    (root->left)->left=insert(4);
    (root->left)->right=insert(5);
    printf("Preorder:");
    Preorder(root);
    printf("\n");
    printf("Inorder:");
    Inorder(root);
    printf("\n");
    printf("Postorder:");
    Postorder(root);
    return 0;
}