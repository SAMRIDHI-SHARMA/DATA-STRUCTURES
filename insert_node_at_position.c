// insert node at certain position 
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_at_end(struct node *ptr, int data){ // time complexity: O(1)
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link= NULL;

    ptr->link =temp;
    return temp;

}

void add_at_pos(struct node *head, int data, int pos){
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link= NULL;
    int count;
    while(count!=pos-1){
        ptr=ptr->link;
        count++;
    }
    temp->link = ptr->link;
    ptr->link = temp;

}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *ptr = head;
    ptr = add_at_end(ptr,93); // ptr is updated without traversing the list
    ptr = add_at_end(ptr,8); 

    int data = 67, position = 3;

    add_at_pos(head,data,position);
    struct node *ptr2 = head;

    
    while(ptr2!= NULL){                         
        printf("%d ", ptr2->data);
        ptr2 = ptr2->link;
    }
    return 0;
}