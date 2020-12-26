#ifndef BST_THREE_LINKS0_H_INCLUDED
#define BST_THREE_LINKS0_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>

struct BST_node{
    struct BST_node* up;
    int data;
    struct BST_node* left;
    struct BST_node* right;
};


int append(struct BST_node **ROOT, int d){
    struct BST_node *temp = (struct BST_node*)malloc(sizeof(struct BST_node));
    if(temp == NULL) exit(-1);

    temp->data = d;
    temp->left = temp->right = NULL;

    if(*ROOT == NULL) temp->up = NULL;

    else{
        struct BST_node* p = *ROOT;
        struct BST_node* parent;
        while(p){
            parent = p;
            if(d > p->data) p = p->right;
            else p = p->left;
        }
        temp->up = parent;
        if(d > parent->data) parent->right =  temp;
        else parent->left = temp;
    }

    return 1;
}



#endif // BST_THREE_LINKS0_H_INCLUDED
