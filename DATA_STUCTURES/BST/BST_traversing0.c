#include<stdio.h>
#include<stdlib.h>

struct my_struct{
    int data;
    struct my_struct* left;
    struct my_struct* right;
};

struct my_struct* root = NULL;

struct my_struct* new_node(int d){
    struct my_struct* temp = (struct my_struct*)malloc(sizeof(struct my_struct));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inorder_traverse(struct my_struct* ROOT){
    if(ROOT == NULL) return;

    inorder_traverse(ROOT->left);
    printf("%d ", ROOT->data);
    inorder_traverse(ROOT->right);
}

void preorder_traverse(struct my_struct* ROOT){
    if(ROOT == NULL) return;

    printf("%d ", ROOT->data);
    preorder_traverse(ROOT->left);
    preorder_traverse(ROOT->right);
}

void postorder_traverse(struct my_struct* ROOT){
    if(ROOT == NULL) return;

    postorder_traverse(ROOT->left);
    postorder_traverse(ROOT->right);
    printf("%d ", ROOT->data);

}

int main(){
    root = new_node(1);
    root->right = new_node(3);
    root->left = new_node(2);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    postorder_traverse(root);
}
