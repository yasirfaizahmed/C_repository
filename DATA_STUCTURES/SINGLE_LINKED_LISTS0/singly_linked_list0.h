/****************************************************************
USERDEFINED HEADER FOR SIMPLE OPERATIONS ON SINGLY LINKED LISTS

---Include it in the directory where the source code is present.
---The data-type of the structure members can be costomized from the structure definition at line-15.
*****************************************************************/

#ifndef SINGLY_LINKED_LIST0_H_INCLUDED
#define SINGLY_LINKED_LIST0_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>


struct node{
    int data;
    struct node* link;
};



/*appends the value passed at the end, and returns the ROOT*/
int append(struct node **ROOT, int d){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node*));
    if(temp == NULL) return -1;

    temp->data = d;
    if(*ROOT == NULL){
        *ROOT = temp;
        temp->link = NULL;
    }
    else{
        struct node* p = *ROOT;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
        temp->link = NULL;
    }

    return 1;
}

/*prints all the values in the LL*/
void print_all(struct node* ROOT){
    if(ROOT == NULL) printf("\nList is empty\n\n");
    struct node *temp;
    temp = ROOT;
    printf("\n");
    while(temp->link!=NULL){
        printf("%d-->", temp->data);
        temp = temp->link;
    }
    if(temp->link == NULL) printf("%d-->", temp->data);
}

/*Returns the lenght of LL*/
int len(struct node* ROOT){
    struct node* temp = ROOT;
    int countt = 0;
    if(ROOT == NULL) return countt;
    while(temp->link!=NULL){
        countt++;
        temp = temp->link;
    }
    if(temp->link == NULL) countt++;

    return countt;
}

/*Adds the node at the begining, returns the ROOT*/
int add_at_begining(struct node** ROOT, int d){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp == NULL) return -1;

    temp->data = d;
    temp->link = NULL;
    if(*ROOT == NULL)*ROOT = temp;
    else{
        temp->link = *ROOT;
        *ROOT = temp;
    }

    return 1;
}

/*Adds at a particular position , returns the ROOT*/
int add_at_position(struct node** ROOT, int n, int d){
    if(n > len(*ROOT)) return 0;
    if(n == 1) add_at_begining(ROOT, d);
    else{
        struct node *temp;
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = d;
        struct node *p;
        p = *ROOT;
        int i = 1;
        while(i != n-1){
            p = p->link;
            i++;
        }
        struct node *q;
        q = p->link;
        p->link = temp;
        temp->link = q;
    }

    return 1;
}

/*Deletes the front node, returns the ROOT*/
int delete_fornt(struct node** ROOT){
    struct node *temp;
    if(*ROOT == NULL) return -1;
    else{
        temp = *ROOT;
        *ROOT = temp->link;
        temp->link = NULL;
        free(temp);
    }

    return 1;
}

/*Deletes the node at particular position, returns the ROOT*/


int delete_at_position(struct node** ROOT, int n){
    if(n > len(*ROOT)) return 0;
    if(*ROOT == NULL) return -1;
    if(n == 1) delete_fornt(ROOT);
    else{
        struct node *p;
        p = *ROOT;
        int i = 1;
        while(i != n-1){
            p = p->link;
            i++;
        }
        struct node *q;
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }

    return 1;
}



/*Swaps the data values at positions n, m passed, and returns  the ROOT*/
int swap_data(struct node** ROOT, int n, int m){
    if(*ROOT == NULL)  return 0;
    struct node *tempn;
    tempn = *ROOT;
    int i = 1;
    int temp_data;
    while(i < n){
        tempn = tempn->link;
        i++;
    }
    temp_data = tempn->data;

    i = 1;
    struct node *tempm;
    tempm = *ROOT;
    while(i < m){
        tempm = tempm->link;
        i++;
    }
    tempn->data = tempm->data;
    tempm->data = temp_data;

    return 1;
}

/*Reverses the passed LL, returns the ROOT*/
int reverse_list(struct node** ROOT){
    if(*ROOT == NULL) return 0;
    int i = 1;
    int n = len(*ROOT);
    while(i <= n/2){
        swap_data(ROOT, i, (n-i+1));
        i++;
    }

    return 1;
}

/*peeks at the particular position and returns the value present at their*/
int peek(struct node* ROOT, int pos){
    if(pos > len(ROOT)) return 0;
    else if(pos < 1) return 0;
    struct node* temp;
    temp = ROOT;
    int i = 1;
    while(i < pos){
        temp = temp->link;
        i++;
    }

    return temp->data;
}

/*Overrights the value at position passed with a value passed */
int replace_value(struct node** ROOT, int pos, int d){
    int i = 1;
    struct node* temp;
    temp = *ROOT;
    if(*ROOT == NULL) return 0;
    while(i != pos){
        temp = temp->link;
        i++;
    }
    temp->data = d;

    return 1;
}

/*Bubble sorts the passed LL, returns the ROOT*/
int sort_bubble(struct node** ROOT, char mode){
    int n = len(*ROOT);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(peek(*ROOT, i) > peek(*ROOT, j) && mode == 'a') swap_data(ROOT, i, j);
            if(peek(*ROOT, i) < peek(*ROOT, j) && mode == 'd') swap_data(ROOT, i, j);
        }
    }

    return 1;
}

int sort_insertion(struct node** ROOT){
    int n = len(*ROOT);
    int i = 1, j = 2;
    int  temp_i, temp_j;
    for(i=1;i<n;i++){
        temp_i = i;
        temp_j = j;
        while(peek(*ROOT, i) > peek(*ROOT, j)){
            swap_data(ROOT, i, j);
            //print_all(*ROOT);
            if(i!=1 && j!=2){
                i--;j--;
            }
        }
        i = temp_i;
        j = temp_j;
        j++;
    }
    return 1;
}

struct node* return_address(struct node *ROOT, int pos){
    struct node* temp = ROOT;
    int i = 1;
    while(i < pos){
        temp = temp->link;
        i++;
    }
    return temp;
}


int binary_search_(struct node **ROOT, int d){
    struct node* temp = *ROOT;
    struct node* p = NULL;
    sort_bubble(ROOT, 'a');
    int i = len(*ROOT);
    while(i >= 1){
        if(d == peek(temp, i/2)) return i/2;
        if(d > peek(temp, i/2)){
            temp =  return_address(temp, (i/2) + 1);
            i = i + i/2 ;
        }
        if(d < peek(temp, i/2)) i = i/2;
    }

}



#endif // SINGLY_LINKED_LIST0_H_INCLUDED



