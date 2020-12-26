#include<stdio.h>
#include"doubly_linkedlist0.h"

struct node* root;
int main(){

    append(&root, 10);
    append(&root, 20);
    append(&root, 30);
    append(&root, 40);

    print_all(root);
    return 0;
}
