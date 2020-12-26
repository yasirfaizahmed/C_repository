#include<iostream>
#include"SINGLY_LINKED_LIST_CPP.h"
using namespace std;

int main(){
    node<int> *root = nullptr;
    node <int> sll;    //singly linked list object
    int i=5;
    while(i){
        sll.append(&root, i);   //one object can have only one root
        i--;
    }
    sll.print_all(root);
    cout<<sll.len(root)<<endl;
    sll.add_at_begining(&root, 10);
    sll.print_all(root);
    sll.add_at_position(&root, 4, 100);
    sll.print_all(root);
    sll.delete_front(&root);
    sll.print_all(root);
    sll.delete_at_position(&root, 3);
    sll.print_all(root);
    sll.swap_data(&root, 3, 1);
    sll.print_all(root);
    sll.reverse_list(&root);
    sll.print_all(root);
    cout<<sll.peek(root, 4)<<endl;
    sll.replace_value(&root, 3, 99);
    sll.print_all(root);
    sll.sort_bubble(&root, 'd');
    sll.print_all(root);

    sll.sort_insertion(&root, 'a');
    sll.print_all(root);

    sll.return_address(root, 4);

}
