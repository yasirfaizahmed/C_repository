#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
struct node* front_ = NULL;
struct node* rear_ = NULL;

void push(void);
void print_all(struct node*);
int len(struct node*);
int get(void);
int peek(int);

int main(){
    int choice;
    while(1){
        scanf("%d", &choice);
        switch(choice){
            case 1:push();
            break;
            case 2:print_all(front_);
            break;
            case 3:printf("%d\n\n",len(front_));
            break;
            case 4:printf("%d\n",get());
            break;
            case 5:printf("\n%d",peek(4));
            break;
        }
    }

    return 0;
}

void push(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &temp->data);
    if(front_ == NULL){
        front_ = temp;
        temp->link = NULL;
        rear_ = temp;
    }
    else{
        rear_->link = temp;
        rear_ = temp;
        temp->link = NULL;
    }

}

void print_all(struct node* FRONT_){
    if(FRONT_ == NULL){
        printf("Queue is empty\n\n");
        return 0;
    }
    struct node* p;
    p = FRONT_;
    while(p->link != NULL){
        printf("%d-->", p->data);
        p = p->link;
    }
    printf("%d-->", p->data);
    printf("\n");
}

int len(struct node* FRONT_){
    struct node *p;
    p = FRONT_;
    int count = 0;
    if(FRONT_ == NULL)return 0;
    while(p->link != NULL){
        count++;
        p = p->link;
    }
    count++;
    return count;
}

int get(void){
    int data = front_->data;
    struct node* temp;
    temp = front_;
    front_ = front_->link;
    temp->link = NULL;
    free(temp);
    return data;
}

int peek(int n){
    int i = 1;
    struct node* temp;
    temp = front_;
    while(i < n){
        temp = temp->link;
        i++;
    }
    return temp->data;
}


