#ifndef SINGLY_LINKED_LIST_CPP_H_INCLUDED
#define SINGLY_LINKED_LIST_CPP_H_INCLUDED

/****************************************************************
USERDEFINED HEADER FOR SIMPLE OPERATIONS ON SINGLY LINKED LISTS

---Include it in the directory where the source code is present.
*****************************************************************/


#include<iostream>

template <class T>
class node{
private:
    node* root;

    T data;
    node* link;
public:
    node* ret = nullptr;

    int append(node**, T);
    void print_all(node*);
    int len(node*);
    int add_at_begining(node**, T);
    int add_at_position(node**, int, T);
    int delete_front(node**);
    int delete_at_position(node**, int);
    int swap_data(node**, int, int);
    int reverse_list(node**);
    T peek(node*, int);
    int replace_value(node**, int, T);
    int sort_bubble(node**, char);
    int sort_insertion(node**, char);
    void return_address(node*, int);    //stores the address of nth position in ret(public member)
};

template <class T> int node <T> ::append(node** ROOT, T d){
    node* temp = new node();
    if(temp == nullptr) return -1;

    temp->data = d;

    if(*ROOT == nullptr){
        *ROOT = temp;
        temp->link = nullptr;
        root = *ROOT;
        return 1;
    }
    else{
        node* p = *ROOT;
        while(p->link!=nullptr){
            p = p->link;
        }
        p->link = temp;
        temp->link = nullptr;
    }
    root = *ROOT;

    return 1;
}

template <class T> void node<T> ::print_all(node* ROOT){
    node* temp = ROOT;
    while(temp->link!=nullptr){
        std::cout<<temp->data<<"-->";
        temp = temp->link;
    }
    std::cout<<temp->data;
    std::cout<<std::endl;
}

template <class T> int node<T> ::len(node* ROOT){
    node* temp = ROOT;
    int countt = 0;
    if(ROOT == NULL) return countt;
    while(temp->link!=NULL){
        countt++;
        temp = temp->link;
    }
    if(temp->link == NULL) countt++;

    return countt;
}

template <class T> int node<T> ::add_at_begining(node** ROOT, T d){
    node *temp = new node();
    if(temp == nullptr) return -1;

    temp->data = d;
    temp->link = nullptr;
    if(*ROOT == nullptr){
        *ROOT = temp;
        root = temp;
    }
    else{
        temp->link = *ROOT;
        *ROOT = temp;
        root = temp;
    }

    return 1;
}

template <class T> int node<T> ::add_at_position(node** ROOT, int n, T d){
    if(n > len(*ROOT)) return 0;
    if(n == 1) add_at_begining(ROOT, d);
    else{
        node *temp = new node();
        temp->data = d;
        node *p;
        p = *ROOT;
        int i = 1;
        while(i != n-1){
            p = p->link;
            i++;
        }
        node *q;
        q = p->link;
        p->link = temp;
        temp->link = q;
    }

    return 1;
}

template <class T> int node<T> ::delete_front(node** ROOT){
    node *temp;
    if(*ROOT == nullptr) return -1;
    else{
        temp = *ROOT;
        *ROOT = temp->link;
        temp->link = nullptr;
        delete temp;
    }
    root = *ROOT;

    return 1;
}

template <class T> int node<T> ::delete_at_position(node** ROOT, int n){
    if(n > len(*ROOT)) return 0;
    if(*ROOT == nullptr) return -1;
    if(n == 1) delete_front(ROOT);
    else{
        node *p;
        p = *ROOT;
        int i = 1;
        while(i != n-1){
            p = p->link;
            i++;
        }
        node *q;
        q = p->link;
        p->link = q->link;
        q->link = nullptr;
        delete q;
    }

    return 1;
}

template <class T> int node<T> ::swap_data(node** ROOT, int n, int m){
    if(*ROOT == nullptr)  return 0;
    node *tempn;
    tempn = *ROOT;
    int i = 1;
    int temp_data;
    while(i < n){
        tempn = tempn->link;
        i++;
    }
    temp_data = tempn->data;

    i = 1;
    node *tempm;
    tempm = *ROOT;
    while(i < m){
        tempm = tempm->link;
        i++;
    }
    tempn->data = tempm->data;
    tempm->data = temp_data;

    return 1;
}

template <class T> int node<T> ::reverse_list(node** ROOT){
    if(*ROOT == nullptr) return 0;
    int i = 1;
    int n = len(*ROOT);
    while(i <= n/2){
        swap_data(ROOT, i, (n-i+1));
        i++;
    }

    return 1;
}

template <class T> T node<T> ::peek(node* ROOT, int pos){
    if(pos > len(ROOT)) return 0;
    else if(pos < 1) return 0;
    node* temp;
    temp = ROOT;
    int i = 1;
    while(i < pos){
        temp = temp->link;
        i++;
    }

    return temp->data;
}

template <class T> int node<T> ::replace_value(node** ROOT, int pos, T d){
    int i = 1;
    node* temp;
    temp = *ROOT;
    if(*ROOT == nullptr) return 0;
    while(i != pos){
        temp = temp->link;
        i++;
    }
    temp->data = d;

    return 1;
}

template <class T> int node<T> ::sort_bubble(node** ROOT, char mode){
    int n = len(*ROOT);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(peek(*ROOT, i) > peek(*ROOT, j) && mode == 'a') swap_data(ROOT, i, j);
            if(peek(*ROOT, i) < peek(*ROOT, j) && mode == 'd') swap_data(ROOT, i, j);
        }
    }

    return 1;
}

template <class T> int node<T> ::sort_insertion(node** ROOT, char mode){
    int n = len(*ROOT);
    int i = 1, j = 2;
    int  temp_i, temp_j;
    for(i=1;i<n;i++){
        temp_i = i;
        temp_j = j;
        if(mode == 'a'){
            while(peek(*ROOT, i) > peek(*ROOT, j)){
                swap_data(ROOT, i, j);
                if(i!=1 && j!=2){
                    i--;j--;
                }
            }
            i = temp_i;
            j = temp_j;
            j++;
        }
        else if(mode == 'd'){
        while(peek(*ROOT, i) < peek(*ROOT, j)){
                swap_data(ROOT, i, j);
                if(i!=1 && j!=2){
                    i--;j--;
                }
            }
            i = temp_i;
            j = temp_j;
            j++;
        }
    }

    return 1;
}

template <class T> void node<T> ::return_address(node* ROOT, int pos){
    node* temp = ROOT;
    int i = 1;
    while(i < pos){
        temp = temp->link;
        i++;
    }
    std::cout<<temp->data;
    ret = temp;

}


#endif // SINGLY_LINKED_LIST_CPP_H_INCLUDED
