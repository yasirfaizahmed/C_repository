#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node{
    struct node* link;
    int data;
};

struct root{
    struct node* node_link;
    struct root* root_link;
    int vertex_data;
};

struct root* add_node(int , int);
void print_all();

struct root* root_list[4] = {NULL};

int main(){
    add_node(5, 9);
    add_node(1, 10);
    add_node(8, 7);
    add_node(4, 5);
    add_node(0, 8);
    add_node(0, 9);

    printf("%d", root_list[4]->node_link->link->data);



    return 0;
}


struct root* add_node(int src, int des){
    struct root* temp = (struct root*)malloc(sizeof(struct root));
    temp->node_link = NULL;
    temp->root_link = NULL;

    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->link = NULL;

    bool their = false;

    if(root_list[0] == NULL){
        root_list[0] = temp;
        temp->vertex_data = src;
        //printf("%d-->", temp->vertex_data);

        root_list[0]->node_link = p;
        p->data = des;

    }
    else{
        int i = 0;
        while(root_list[i]->root_link != NULL){
            if(src == root_list[i]->vertex_data){their = true; break;}
            i++;
        }
        i++;
        if(their == true){
            free(temp);
            struct node* q = root_list[i]->node_link;
            while(q->link != NULL){
                q = q->link;
            }
            q->link = p;
            p->data = des;
        }
        else if(their == false){
            root_list[i-1]->root_link = temp;
            root_list[i] = temp;
            temp->vertex_data = src;
            root_list[i]->node_link = p;
            p->data = des;
            //printf("%d-->", root_list[i+1]->vertex_data);
        }

    }

    return root_list[0];

}

void print_all(){
    struct root* t = root_list[0];
    int i = 0;
    while(t->root_link != NULL){
        printf("%d-->", root_list[i]->vertex_data);
        i++;
        t = t->root_link;
    }

}
