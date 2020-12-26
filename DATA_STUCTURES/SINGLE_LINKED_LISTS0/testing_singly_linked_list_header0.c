#include<stdio.h>
#include"singly_linked_list0.h"


struct node* root = NULL;

int main(){
    int n = 15;
    while(n > 0){
        append(&root, n);
        n--;
    }
    //sort_bubble(&root, 'a');
    print_all(root);

    replace_value(&root, 4, 999);

    print_all(root);

    return 0;
}


