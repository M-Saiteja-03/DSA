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

int isBST(struct node*root){

    if(root->left==NULL){
            return;
    }
    
    if((root->left)->data<root->data){
        if(!isBST(root->left)){
            return 0;
        }
        if((root->right)->data>root->data){
            isBST(root->right);
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
    return 1;
}

void Preorder(struct node*root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct node*root){
    if(root==NULL){
        return;
    }
    Inorder(root->left);
    printf("%d ",root->data);
    Inorder(root->right);
}
void Postorder(struct node*root){
    if(root==NULL){
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

void Insertion(struct node*root,int key){
    // struct node*prev=NULL;
    while(root->left!=NULL){
        if(root->data==key){
            printf("duplicate\n");
        }
        else if(key>root->data){
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    struct node*new=insert(key);
    if(key>root->data){
        root->right=new;
    }
    else{
        root->left=new;
    }
}
int getrightmin(struct node*root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root->data;
}
struct node*Delete(struct node*root,int value){
    if(root==NULL){
        return NULL;
    }
    else if(value<root->data){
        root->left=Delete(root->left,value);
    }
    else if(value>root->data){
        root->right=Delete(root->right,value);
    }
    else{
        if(root->left==NULL&&root->right==NULL){
            free(root);
            return NULL;
        }
        else if (root->left==NULL)
        {
            struct node*temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL)
        {
            struct node*temp=root->left;
            free(root);
            return temp;
        }
        else{
            int rightmin=getrightmin(root->right);
            root->data=rightmin;
            root->right=Delete(root->right,rightmin);
        }
    }
    return root;
    
}
int main()
{   
    struct node*root=insert(10);
    root->left=insert(5);
    root->right=insert(15);
    (root->right)->left=insert(14);
    (root->right)->right=insert(16);
    (root->left)->left=insert(4);
    (root->left)->right=insert(6);
    /*       10
             /\
            5  15
           /\   /\
          4  6 14 16
    */     
    int x=isBST(root);
    printf("%d\n",x);
    if(x){
        printf("yes\n");
    }
    else{
        printf("no\n");
    }
    // printf("Preorder\n");
    // Preorder(root);
    printf("\nInorder\n");
    Inorder(root);
    // printf("\nPostorder\n");
    // Postorder(root);
    // printf("\nAfter Insertion\n");
    // Insertion(root,13);
    // Inorder(root);
    printf("\nAfter Deletion\n");
    Delete(root,4);
    Inorder(root);
    
}