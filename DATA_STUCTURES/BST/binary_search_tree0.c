#include"BST_header0.h"
#include<stdio.h>

struct BST_node* root = NULL;



/*****
   root-->  8
          /   \
         3     10
        /  \     \
       1    6     14
           /  \   /
          4    7 13
****/


int main(){
    //int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    int arr[10];
    for(int i=0;i<10;i++) arr[i] = rand();
    int n = 0;
    while(n < sizeof(arr)/sizeof(arr[0])){
        append(&root, arr[n]);
        n++;
    }

    print_all(root, 0);

    //printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");

    //printf("\n\n\n\n\n\n\n%d",search_parent(&root, 1, 'c')->data);
    //delete_(&root, 3);

    //print_all(root, 0);

    inorder_traverse(root);
    return 0;
}
