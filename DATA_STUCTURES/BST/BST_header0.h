#ifndef BST_HEADER0_H_INCLUDED
#define BST_HEADER0_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#define COUNT 10

struct BST_node{
    struct BST_node* left;
    struct BST_node* right;
    int data;
};

int append(struct BST_node** ROOT, int d){
    struct BST_node* temp = (struct BST_node*)malloc(sizeof(struct BST_node));
    if(temp == NULL) exit(-1);

    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;

    if(*ROOT == NULL){
        temp->left = NULL;
        temp->right = NULL;
        *ROOT = temp;
    }
    else{
        struct BST_node* current = *ROOT;
        struct BST_node* parent;
        while(current != NULL){
            parent = current;
            if(d > current->data) current = current->right;
            else current = current->left;
        }
        if(d > parent->data) parent->right = temp;
        else parent->left = temp;
    }
    return 1;
}

void print_all(struct BST_node* ROOT, int space)
{
    if (ROOT == NULL) return;

    space += COUNT;
    print_all(ROOT->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++) printf(" ");

    printf("%d\n", ROOT->data);

    print_all(ROOT->left, space);
}

struct BST_node* search_parent(struct BST_node **ROOT, int d, char mode){
    struct BST_node *temp = *ROOT;
    if(d == temp->data) return *ROOT;
    while(temp != NULL){
        if(mode == 'p'){
            if(temp->left != NULL) if(d == temp->left->data) return temp;
            if(temp->right != NULL) if(d == temp->right->data) return temp;

            if(d > temp->data) temp = temp->right;
            else temp = temp->left;
        }
        if(mode == 'c'){
            if(d == temp->data) return temp;

            if(d > temp->data) temp = temp->right;
            else temp = temp->left;
        }
    }

    return NULL;
}


int delete_(struct BST_node **ROOT, int d){
    struct BST_node* to_delete = search_parent(ROOT, d, 'c');
    struct BST_node* temp = search_parent(ROOT, d, 'c')->right;

    struct BST_node* to_free_parent = search_parent(ROOT, d, 'c')->right;

    while(temp){
        if(temp->left == NULL) break;
        else temp = temp->left;
    }

    to_delete->data = temp->data;


    struct BST_node* to_free = search_parent(&to_free_parent, temp->data, 'p');

    to_free->left = NULL;
    free(temp);

    return 0;
}

void inorder_traverse(struct BST_node* ROOT){
    if(ROOT == NULL) return;

    inorder_traverse(ROOT->left);
    printf("%d ", ROOT->data);
    inorder_traverse(ROOT->right);
}

void preorder_traverse(struct BST_node* ROOT){
    if(ROOT == NULL) return;

    printf("%d ", ROOT->data);
    preorder_traverse(ROOT->left);
    preorder_traverse(ROOT->right);
}

void postorder_traverse(struct BST_node* ROOT){
    if(ROOT == NULL) return;

    postorder_traverse(ROOT->left);
    postorder_traverse(ROOT->right);
    printf("%d ", ROOT->data);

}



#endif // BST_HEADER0_H_INCLUDED
