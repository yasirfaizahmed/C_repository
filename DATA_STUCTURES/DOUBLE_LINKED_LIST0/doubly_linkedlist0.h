#ifndef DOUBLY_LINKEDLIST0_H_INCLUDED
#define DOUBLY_LINKEDLIST0_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>

/**
        exit(-1) if memory allocation fails
        returns 1 if function executes without any errors
        else returns 0
**/

struct node{
    int data;
    struct node* left;
    struct node* right;
};

int append(struct node** ROOT, int d){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL) exit(-1);
    temp->data = d;

    if(*ROOT == NULL){
        temp->left = NULL;
        temp->right = NULL;
        *ROOT = temp;
        return 1;
    }
    else {
        struct node* p;
        p = *ROOT;
        while(p->right != NULL){
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
        temp->right = NULL;
    }
}

void print_all(struct node* ROOT){
    if(ROOT == NULL) printf("\nList is empty\n\n");
    else{
        struct node* temp = ROOT;
        while(temp->right != NULL){
            printf("%d<=>", temp->data);
            temp = temp->right;
        }
        printf("%d", temp->data);
    }
}


#endif // DOUBLY_LINKEDLIST0_H_INCLUDED
