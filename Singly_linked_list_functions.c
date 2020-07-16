#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node *root = NULL;

void append();
void print_all();
int len(struct node*);
void add_at_begining();
void delete_at_position(int);
void delete_fornt();
void add_at_position(int);
void swap_data(int, int);
void reverse_list();
void sort_bubble(struct node*);
int peek(int);

int main(){
    int choice;

    while(1){
        printf("\n\n1:append\n");
        printf("2:print_all\n");
        printf("3:length\n");
        printf("4:add_at_beginning\n");
        printf("5:delete_at_position\n");
        printf("6:delete_front\n");
        printf("7:add_at_position\n");
        printf("8:swap\n");
        printf("9:reverse\n");
        printf("10:bubble_sort\n");
        printf("11:peek\n");
        scanf("%d", &choice);
        switch(choice){
            case 1:append();
            break;
            case 2:print_all();
            break;
            case 3:printf("length :%d\n\n", len(root));
            break;
            case 4:add_at_begining();
            break;
            case 5:delete_at_position(3);
            break;
            case 6:delete_fornt();
            break;
            case 7:add_at_position(3);
            break;
            case 8:swap_data(2, 5);
            break;
            case 9:reverse_list();
            break;
            case 10:sort_bubble(root);
            break;
            case 11:printf("peeked value at pos. 3:%d\n\n", peek(3));
            break;
            default:printf("invalid\n\n");
        }
    }
    return 0;
}

void append(){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(root == NULL) root = temp;
    else{
        struct node *p;
        p = root;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = temp;
    }

}

void print_all(){
    struct node *temp;
    temp = root;
    if(root == NULL)printf("list is empty\n\n");
    while(temp->link!=NULL){
        printf("%d-->", temp->data);
        temp = temp->link;
    }
    if(temp->link == NULL)printf("%d-->", temp->data);
}


int len(struct node* ROOT){
    struct node* temp = ROOT;
    int count = 0;
    if(ROOT == NULL)return count;
    while(temp->link!=NULL){
        count++;
        temp = temp->link;
    }
    if(temp->link == NULL)count++;
    return count;
}

void add_at_begining(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    temp->link = NULL;
    if(root == NULL)root = temp;
    else{
        temp->link = root;
        root = temp;
    }
}

void delete_at_position(int n){
    if(n > len(root))printf("invalid position to delete\n\n");
    if(root == NULL)printf("List is empty\n\n");
    else{
        struct node *p;
        p = root;
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
}

void delete_fornt(){
    struct node *temp;
    if(root == NULL)printf("List is empty\n\n");
    else{
        temp = root;
        root = temp->link;
    }
}

void add_at_position(int n){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    struct node *p;
    p = root;
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

void swap_data(int n, int m){
    if(root == NULL)printf("Empty list\n\n");
    struct node *tempn;
    tempn = root;
    int i = 1;
    int temp_data;
    while(i < n){
        tempn = tempn->link;
        i++;
    }
    temp_data = tempn->data;

    i = 1;
    struct node *tempm;
    tempm = root;
    while(i < m){
        tempm = tempm->link;
        i++;
    }
    tempn->data = tempm->data;
    tempm->data = temp_data;
}


void reverse_list(){
    int i = 1;
    int n = len(root);
    while(i <= n/2){
        swap_data(i, (n-i+1));
        i++;
    }
}

int peek(int pos){
    struct node* temp;
    temp = root;
    int i = 1;
    while(i < pos){
        temp = temp->link;
        i++;
    }
    return temp->data;
}

void sort_bubble(struct node* ROOT){
    int n = len(root);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(peek(i) > peek(j)){
                swap_data(i, j);
            }
        }
    }
}
